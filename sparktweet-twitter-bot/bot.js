// Our Twitter library
var Twit = require('twit');
var rest = require('restler');
var levelup = require('level');
var q = require('q');

// We need to include our configuration file
var T = new Twit(require('./twitterConfig.js'));
var sparkConfig = require('./sparkConfig.js');

//levelup.destroy('./displayedTweets');

var displayed_db = levelup('./displayedTweets');

var tweetQueue = [];

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
						tweetQueue.push(queueTweet);
						console.log("queueing ", queueTweet.message, "queue at ", tweetQueue.length);
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
						tweetQueue.push(queueTweet);
						console.log("queueing ", queueTweet.message, "queue at ", tweetQueue.length);
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

	if (tweetQueue.length == 0){
		deferred.resolve(false);
	}
	else {
		var isAlreadyQueued = false;
		for (var i = 0; i < tweetQueue.length; i++) {
			if (tweetQueue[i].id == tweetData.id){
				isAlreadyQueued = true;
			}

			if (i == (tweetQueue.length - 1)){
				deferred.resolve(isAlreadyQueued);
			}
		}
	}
	
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

function displayTweet(){
	console.log("looking to display tweets, queue length is ", tweetQueue.length);

	tweetQueue.sort(function(a, b) {
		return a.created_at < b.created_at;
	});

	if (tweetQueue.length > 0){
		var tweet = tweetQueue.pop();
		sendMessage(1,"BEGIN").done(function(){
			//can only send 61 characters at a time to the spark
			var messagePromises = [];

			var msgsNeeded = Math.ceil(tweet.message.length/61);
			for (var i = 0; i < msgsNeeded; i++) {
				var thisMessageText = "";
				if (i == (msgsNeeded - 1)){
					thisMessageText = tweet.message.substring(61*i);
				}
				else {
					thisMessageText = tweet.message.substring(61*i, 61 * (i+1));
				}

				messagePromises.push(sendMessage(0,thisMessageText));
			}

			q.all(messagePromises).done(function(){
				sendMessage(1,"END");
				//displayed_db.put(tweet.id, tweet.created_at);
				//console.log("display done, length is ", tweetQueue.length);
			});

		});
	}
}

function sendMessage(adminFlag, message){
	var deferred = q.defer();
	rest.post('https://api.spark.io/v1/devices/' + sparkConfig.deviceID + '/buildString', {
		data: { 'access_token': sparkConfig.accessToken,
		'args': adminFlag + "," + message }
	}).on('complete', function(data, response) {
		if (data.ok !== undefined && !data.ok){
			console.log("Error: " + data.error + " for ", adminFlag, message, " Tweet will be requeued.");
		}
		else {
			console.log("msg sent : ", adminFlag, message);	
			if (adminFlag == 1 && message == "END"){
				displayed_db.put(tweet.id, tweet.created_at);
				console.log("display done, length is ", tweetQueue.length);
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