// Our Twitter library
var Twit = require('twit');
var rest = require('restler');

// We need to include our configuration file
var T = new Twit(require('./twitterConfig.js'));
var sparkConfig = require('./sparkConfig.js');

var userName = '';
T.get('account/verify_credentials', {}, function(error, data){
	userName = data.screen_name;
});

var tweetQueue = [];

function findTweetToDisplay() {
	console.log("looking for mentions...");
	//get the 10 latest mentions
	T.get('statuses/mentions_timeline', {count:10}, function (error, data) {
		
		
			//send an api call to spark
			/*rest.post('https://api.spark.io/v1/devices/' + sparkConfig.deviceID + '/sing', {
				data: { 'access_token': sparkConfig.accessToken,
				'args': music.notes }
			}).on('complete', function(data, response) {
				console.log("played " + music.notes );
				//when it's done, favorite the tweet so the person knows they are now a performer
				T.post('favorites/create', { id: music.playID }, function(err, reply) {});
			});*/
		
	});
}

findTweetToDisplay(); 
setInterval(findTweetToDisplay, 1000 * 60);