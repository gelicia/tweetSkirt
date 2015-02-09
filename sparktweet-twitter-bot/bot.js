// Our Twitter library
var Twit = require('twit');
var rest = require('restler');
var levelup = require('level');
var q = require('q');

// We need to include our configuration file
var T = new Twit(require('./twitterConfig.js'));
var sparkConfig = require('./sparkConfig.js');

//levelup.destroy('./displayedTweets');
//requeue undisplayed tweets when bot is started
levelup.destroy('./tweetQueue');
levelup.destroy('./displayQueue');

var tweetQueue_db = levelup('./tweetQueue');
var displayQueue_db = levelup('./displayQueue');
var displayed_db = levelup('./displayedTweets');

/* I am still on the fence about this setting. Do I leave out the name of who the tweet was a reply to?  */
var showBeginningName = false;
var displayMentionDays = 1;
var dbCleanupDays = 3;

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
						tweetQueue_db.put(queueTweet.id, queueTweet);
						console.log("queueing ", queueTweet.message);
					}
				});
			}
		};
	});

	//get usages of the #tweetSkirt hashtag
	T.get('search/tweets', { q: '#tweetSkirt', result_type: 'recent', count: 50}, function(error, data){
		for (var i = 0; i < data.statuses.length; i++) {
			var dataOfInterest = data.statuses[i];
			
			//only queue up not retweets
			if (dataOfInterest.retweeted_status == undefined){
				var isDisplayedPromise = isAlreadyDisplayed(dataOfInterest);

				isDisplayedPromise.done(function(result){
					if(result.toQueue){//tweet not found! queue it up!
						var queueTweet = processTweetData(result.data);
						console.log("put tweet", queueTweet);
						tweetQueue_db.put(queueTweet.id, queueTweet);
						console.log("queueing ", queueTweet.message);
					}
				});
			}
		};
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

function isAlreadyQueued(tweetData){
	var deferred = q.defer();

	tweetQueue_db.get(tweetData.id, function (err, value) {
		if (err) {
			if (err.notFound){ 
				deferred.resolve(false);
			}
			else {
				deferred.resolve(true);
			}
			
		}
		else { //value found, do not queue it up
			deferred.resolve(true);
		}
	});
	
	return deferred.promise;
}

function isAlreadyDisplayed(tweetData){
	var deferred = q.defer();

	var isQueuedPromise = isAlreadyQueued(tweetData);
	isQueuedPromise.done(function(isAlreadyQueuedResult){
		if (isAlreadyQueuedResult){
			deferred.resolve({toQueue: false, data:tweetData});
		} 
		else{
			displayed_db.get(tweetData.id, function (err, value) {
				if (err) {
					if (err.notFound){ //value not found, queue up
						deferred.resolve({toQueue: true, data:tweetData});
					}
					else {
						//count it as displayed (will not queue up) if there's an error, it should get queued next time around
						deferred.resolve({toQueue: false, data:tweetData});
					}
					
				}
				else { //value found, do not queue it up
					deferred.resolve({toQueue: false, data:tweetData});
				}
			});
		}
	});

	return deferred.promise;
}

function getLeastRecentTweet(){
	var deferred = q.defer();
	var tweetOfInterest = {};
//should be displayQueue
	tweetQueue_db.createReadStream()
	.on('data', function (data) {
		console.log("getLeastRecent", data.value);
		if (tweetOfInterest.created_at === undefined || data.value.created_at < tweetOfInterest.created_at){
			tweetOfInterest = data.value;
		}
	})
	.on('end', function () {
		deferred.resolve(tweetOfInterest);
	});

	return deferred.promise;
}

function displayTweet(){
	console.log("looking to display tweets");

	getLeastRecentTweet().done(function(tweetOfInterest){
		sendMessage(1,{message: "BEGIN"}).done(function(){
			console.log("tweetOfInterest", tweetOfInterest[0]);
			//can only send 61 characters at a time to the spark
			var messagePromises = [];

			var msgsNeeded = Math.ceil(tweetOfInterest.message.length/61);
			for (var i = 0; i < msgsNeeded; i++) {
				var tweetData = {};
				var thisMessageText = "";
				if (i == (msgsNeeded - 1)){
					thisMessageText = tweetOfInterest.message.substring(61*i);
				}
				else {
					thisMessageText = tweetOfInterest.message.substring(61*i, 61 * (i+1));
				}

				tweetData.message = thisMessageText;

				messagePromises.push(sendMessage(0,tweetData));
			}

			q.all(messagePromises).done(function(){
				sendMessage(1,{message:"END", id: tweetOfInterest.id, created_at: tweetOfInterest.created_at});
			});
		});
	});
}

function sendMessage(adminFlag, messageData){
	var deferred = q.defer();
	rest.post('https://api.spark.io/v1/devices/' + sparkConfig.deviceID + '/buildString', {
		data: { 'access_token': sparkConfig.accessToken,
		'args': adminFlag + "," + messageData.message }
	}).on('complete', function(data, response) {
		//sometimes the spark API returns the html for the error page instead of the standard array
		if ((data.ok !== undefined && !(data.ok)) || (typeof data == "string" && data.substring(0, 6) == "<html>")){
			console.log("Error: " + data.error + " for ", adminFlag, messageData.message, " Tweet will be requeued.");
		}
		else {
			console.log("msg sent : ", adminFlag, messageData.message);	
			if (adminFlag == 1 && message == "END"){
				//only put the id in the displayed db if sending to the spark doesn't fail
				displayed_db.put(messageData.id, messageData.created_at);
				console.log("display done");
			}
		}
		deferred.resolve();
	});

	return deferred.promise;
}

queueTweets(); 
//find tweets every three minutes
setInterval(queueTweets, 2 * 1000 * 60);

//display a tweet every minute
setInterval(displayTweet, 1000 * 30);

//Make this a process to go off every so often if this program ends up staying online longterm
function dbCleanup(){
	var now = new Date();
	displayed_db.createReadStream()
	.on('data', function (data) {
		var tweetDate = new Date(data.value);
		if (now - tweetDate > 1000*60*60*24*dbCleanupDays){
			displayed_db.del(data.key);
		}
	});
}

dbCleanup();