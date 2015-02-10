var express = require('express');
var Datastore = require('nedb');
var jwt = require('jwt-simple');
var bodyParser = require('body-parser');

var loginCreds = require('./loginConfig');

var app = express();

var urlencodedParser = bodyParser.urlencoded({ extended: false });

var allowCrossDomain = function(req, res, next) {
    res.header('Access-Control-Allow-Origin', '*');
    res.header('Access-Control-Allow-Methods', 'GET,PUT,POST,DELETE');
    res.header('Access-Control-Allow-Headers', 'Content-Type');

    next();
};

app.use(allowCrossDomain);

//show tweetQueue
app.get('/tweetQueue', function (req, res) {
	var tweetQueue_db = new Datastore({filename: '../sparktweet-twitter-bot/tweetQueue.db', autoload:true});
	tweetQueue_db.find({}, function (err, docs) {
		res.send(docs);
	});
});

//show displayQueue
app.get('/displayQueue', function (req, res) {
	var tweetQueue_db = new  Datastore({filename: '../sparktweet-twitter-bot/displayQueue.db', autoload:true});
	tweetQueue_db.find({}, function (err, docs) {
		res.send(docs);
	});
});

//move to display queue
app.post('/displayQueue', urlencodedParser, function (req, res) {
	if (!req.body) { 
		return res.sendStatus(400); 
	}
	else {
		var displayQueue_db = new  Datastore({filename: '../sparktweet-twitter-bot/displayQueue.db', autoload:true});

		//make sure jwt token matches db before saving displayQueue info
		console.log(req.body);
		return res.sendStatus(200);
	}
});

//move to displayed tweets
app.post('/displayedTweets', urlencodedParser, function (req, res) {
	if (!req.body) { 
		return res.sendStatus(400); 
	}
	else {
		var displayedTweets_db = new  Datastore({filename: '../sparktweet-twitter-bot/displayedTweets.db', autoload:true});
		
		//make sure jwt token matches db before saving into displayedTweets
		console.log(req.body);
		return res.sendStatus(200);
	}
});

app.get('/login', function (req, res) {
	var output = {success: false};
	if (req.query.password === loginCreds.md5Password){
		output.success = true;
		output.jwt = jwt.encode({username: req.query.username}, loginCreds.md5Password);
	}
	res.send(output);
});

var server = app.listen(3000, function () {

  var host = server.address().address;
  var port = server.address().port;
  console.log('Example app listening at http://%s:%s', host, port);

});