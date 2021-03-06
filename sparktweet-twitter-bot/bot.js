// Our Twitter library
var Twit = require('twit');
var rest = require('restler');
var Datastore = require('nedb');
var q = require('q');

// We need to include our configuration file
var T = new Twit(require('./twitterConfig.js'));
var sparkConfig = require('./sparkConfig.js');

var tweetQueue_db = new Datastore({filename: './tweetQueue.db', autoload:true});
var displayQueue_db = new Datastore({filename: './displayQueue.db', autoload:true});
var displayedTweets_db = new Datastore({filename: './displayedTweets.db', autoload:true});

//when this app starts, reset the moderation. If this gets to be too much of a pain, only remove from tweetQueue
//tweetQueue_db.remove({}, {multi: true});
//displayQueue_db.remove({}, {multi: true});
//displayedTweets_db.remove({},{multi: true});


// I am still on the fence about this setting. Do I leave out the name of who the tweet was a reply to?
 var showBeginningName = false;
 var displayMentionDays = 5;
 var dbCleanupDays = 3;

//how many times it will try to send everything to the spark before giving up
 var sparkErrorThreshhold = 3;

function queueTweets() {
	console.log("look for tweets...");
	var now = new Date(); 
	//get the 50 latest mentions
	T.get('statuses/mentions_timeline', {count:50}, function (error, data) {
		for (var i = 0; i < data.length; i++) {
			var dataOfInterest = data[i];
			//only look for tweets less than 24 hours old
			var tweetDate = new Date(dataOfInterest.created_at);
			if(now - tweetDate < (1000*60*60*24 * displayMentionDays)){
				//check that the tweet has not yet been displayed
				//we send all the data to it because the loop will keep running and we want to keep the data attached to the promise
				var isDisplayedPromise = isAlreadyDisplayed(dataOfInterest);
				isDisplayedPromise.done(function(result){
					if(result.toQueue){//tweet not found! queue it up!
						var queueTweet = processTweetData(result.data);					
						tweetQueue_db.insert(queueTweet);
						console.log("queueing ", queueTweet.message);
					}
				});
			}
		};
	});

	//get usages of the #tweetSkirt hashtag
	T.get('search/tweets', { q: '#tweetSkirt', result_type: 'recent', count: 50}, function(error, data){
		if (data.statuses !== null){
			for (var i = 0; i < data.statuses.length; i++) {
				var dataOfInterest = data.statuses[i];
				
				//only queue up not retweets
				if (dataOfInterest.retweeted_status == undefined){
					var isDisplayedPromise = isAlreadyDisplayed(dataOfInterest);

					isDisplayedPromise.done(function(result){
						if(result.toQueue){//tweet not found! queue it up!
							var queueTweet = processTweetData(result.data);
							tweetQueue_db.insert(queueTweet);
							console.log("queueing ", queueTweet.message);
						}
					});
				}
			};
		}
	});
}

function processTweetData(tweetData){
	var queuedMessage = "@" + tweetData.user.screen_name + " - ";
	
	//If the message begins with the name of who it was a reply to, remove that name from the string
	if (!showBeginningName && (tweetData.text).indexOf(tweetData.in_reply_to_screen_name) == 1){
		queuedMessage = queuedMessage + (tweetData.text).substring(tweetData.in_reply_to_screen_name.length+2);
	}
	else { //otherwise, just display the text
		queuedMessage = queuedMessage + tweetData.text;
	}

	var queueTweet = {
		"id" : tweetData.id,
		created_at: new Date(tweetData.created_at),
		message : queuedMessage
	};

	return queueTweet;
}

function isTweetQueued(tweetData){
	var deferred = q.defer();
	tweetQueue_db.loadDatabase();
	tweetQueue_db.findOne({id : tweetData.id}, function (err, doc) {
		if (err){ //if theres an error, just let it check next time
			deferred.resolve(true);
		}
		else if (doc === null){ //if nothing was found, return false
			deferred.resolve(false);
		}
		else { // otherwise return true
			deferred.resolve(true);
		}
	});
	
	return deferred.promise;
}

function isDisplayQueued(tweetData){
	var deferred = q.defer();
	displayQueue_db.loadDatabase();
	displayQueue_db.findOne({id : tweetData.id}, function (err, doc) {
		if (err){ //if theres an error, just let it check next time
			deferred.resolve(true);
		}
		else if (doc === null){ //if nothing was found, return false
			deferred.resolve(false);
		}
		else { // otherwise return true
			deferred.resolve(true);
		}
	});
	
	return deferred.promise;

}

function isAlreadyDisplayed(tweetData){
	var deferred = q.defer();

	//first make sure its not already in the tweetQueue
	//TODO check the postModeration queue as well
	var isTweetQueuedPromise = isTweetQueued(tweetData);
	isTweetQueuedPromise.done(function(isTweetQueuedRes){
		if(isTweetQueuedRes){
			deferred.resolve({toQueue: false, data:tweetData});
		}
		else{
			var isDisplayQueuedPromise = isDisplayQueued(tweetData);
			isDisplayQueuedPromise.done(function(isDisplayQueuedRes){
				if(isDisplayQueuedRes){
					deferred.resolve({toQueue: false, data:tweetData});
				}
				else{
					displayedTweets_db.loadDatabase();
					displayedTweets_db.findOne({id : tweetData.id}, function (err, doc) {
						if (err){ //if theres an error, just let it check next time
							deferred.resolve({toQueue: false, data:tweetData});
						}
						else if (doc === null){ //value not found, queue up
							//console.log(tweetData.text, "not displayed");
							deferred.resolve({toQueue: true, data:tweetData});
						}
						else { //value found, do not queue it up
							//console.log(tweetData.text, "previously displayed");
							deferred.resolve({toQueue: false, data:tweetData});
						}
					});
				}
			});
		}
	});

	return deferred.promise;
}

 function getLeastRecentTweet(){
 	var deferred = q.defer();

 	displayQueue_db.findOne({}).sort({ created_at: 1 }).exec(function (err, doc) {
  		deferred.resolve(doc);
	});

 	return deferred.promise;
 }

 function incrementErrorCount(tweet){
 	displayQueue_db.update({ id: tweet.id }, { $inc: {errorCount: 1}});
 }

 function displayTweet(){
 	console.log("looking to display tweets");

	displayQueue_db.loadDatabase();
 	displayQueue_db.count({}, function (err, count) {
	  if (count > 0){
		getLeastRecentTweet().done(function(tweetOfInterest){
			if (tweetOfInterest.errorCount && tweetOfInterest.errorCount >= (sparkErrorThreshhold-1)){
				//too many errors, send to displayed
				displayedTweets_db.insert({id: tweetOfInterest.id, message: "Error: " +  tweetOfInterest.message, displayed_at: new Date(), displayed: false, errored: true});
				displayQueue_db.remove({id: tweetOfInterest.id}, {multi: true});
			}
			else {
				sendMessage(1,{message: "BEGIN"}).done(function(){
					var promiseChain = q.fcall(function(){});
					var formatMessage = tweetOfInterest.message;

					formatMessage = formatMessage.replace(/“/g, '"');
					formatMessage = formatMessage.replace(/”/g, '"');
					formatMessage = formatMessage.replace(/‘/g, '\'');
					formatMessage = formatMessage.replace(/’/g, '\'');

					formatMessage = formatMessage.replace(/&amp;/g, '%26');

					var msgsNeeded = Math.ceil(formatMessage.length/61);

					var addToChain = function (i){
						var message = {id: tweetOfInterest.id};
						if (i == (msgsNeeded - 1)){
							message.message = formatMessage.substring(61*i);
						}
						else {
							message.message = formatMessage.substring(61*i, 61 * (i+1));
						}

						var promiseLink = function(){
							var deferred = q.defer();
							sendMessage(0, message).done(function(){deferred.resolve();}, function(){deferred.reject();});
							return deferred.promise;
						};

						promiseChain = promiseChain.then(promiseLink);
					}

					for (var i = 0; i < msgsNeeded; i++) {
						addToChain(i);
					}

					promiseChain.done(function(){
						sendMessage(1,{message:"END", id: tweetOfInterest.id, created_at: tweetOfInterest.created_at}, formatMessage)
							.done(function(){}, function(){incrementErrorCount(tweetOfInterest);});
					}, function(){
						incrementErrorCount(tweetOfInterest);
					});
				}, function(){ //BEGIN errored out
					incrementErrorCount(tweetOfInterest);
				});
			}
		});
	  }

	});
}

function sendMessage(adminFlag, messageData, rootMsg){
	var deferred = q.defer();
	rest.post('https://api.spark.io/v1/devices/' + sparkConfig.deviceID + '/buildString', {
		data: { 'access_token': sparkConfig.accessToken,
		'args': adminFlag + "," + messageData.message }
	}).on('complete', function(data, response) {
		//sometimes the spark API returns the html for the error page instead of the standard array
		if ((data.ok !== undefined && !(data.ok)) || (typeof data == "string" && data.substring(0, 6) == "<html>")){
			console.log("Error: " + data.error + " for ", adminFlag, messageData.message, " Tweet will be requeued.");
			deferred.reject(data.error);
		}
		else {
			console.log("msg sent : ", adminFlag, messageData.message);	
			if (adminFlag == 1 && messageData.message == "END"){
				//only put the id in the displayed db if sending to the spark doesn't fail
				displayedTweets_db.insert({id: messageData.id, message: rootMsg, displayed_at: new Date(), displayed: true});
				displayQueue_db.remove({id: messageData.id}, {multi: true});
				console.log("display done");
			}
			deferred.resolve();
		}
	});

	return deferred.promise;
}

 queueTweets(); 
 
 //find tweets every three minutes
 setInterval(queueTweets, 2 * 1000 * 60);

 //display a tweet every minute
 setInterval(displayTweet, 1000 * 30);

// //Make this a process to go off every so often if this program ends up staying online longterm
// function dbCleanup(){
// 	var now = new Date();
// 	displayed_db.createReadStream()
// 	.on('data', function (data) {
// 		var tweetDate = new Date(data.value);
// 		if (now - tweetDate > 1000*60*60*24*dbCleanupDays){
// 			displayed_db.del(data.key);
// 		}
// 	});
// }

// dbCleanup();