var https = require('https');
var fs = require('fs');
var express = require('express');
var Datastore = require('nedb');
var jwt = require('jwt-simple');
var bodyParser = require('body-parser');
var Q = require('q');

var loginCreds = require('./loginConfig');

var app = express();

var urlencodedParser = bodyParser.urlencoded({ extended: false });

var tweetQueue_db = new Datastore({filename: '../sparktweet-twitter-bot/tweetQueue.db'});
var displayQueue_db = new Datastore({filename: '../sparktweet-twitter-bot/displayQueue.db'});
var displayedTweets_db = new  Datastore({filename: '../sparktweet-twitter-bot/displayedTweets.db'});
var login_db = new  Datastore({filename: './login.db'});


var allowCrossDomain = function(req, res, next) {
    res.header('Access-Control-Allow-Origin', '*');
    res.header('Access-Control-Allow-Methods', 'GET,PUT,POST,DELETE');
    res.header('Access-Control-Allow-Headers', 'Content-Type');
    next();
};

app.use(allowCrossDomain);

app.get('/login', function (req, res) {
	var output = {success: false};
	if (req.query.password === loginCreds.md5Password){
		output.success = true;
		var jwToken = jwt.encode({username: req.query.username}, (new Date()).toString());
		output.jwt = jwToken;

		login_db.loadDatabase(function (err) {
			if (!err){
				login_db.remove({}, {multi: true});
				login_db.insert({token: jwToken});
				res.send(output);
			}
			else {
				res.sendStatus(500);
			}
		});
	}
});

app.get('/logout', function (req, res) {
	authenticate(req.query.token).then(function(auth){
		if (auth){
			login_db.loadDatabase(function (err) {
				if (!err){
					login_db.remove({}, {multi: true});
					res.sendStatus(200);
				}
				else {
					res.sendStatus(500);
				}
			});
		}
		else {
			res.sendStatus(200);
		}
	});
});

app.get('/checkCookie', function (req, res) {
	authenticate(req.query.token).then(function(auth){
		res.send(auth);
	});
});

//show tweetQueue
app.get('/tweetQueue', function (req, res) {
	tweetQueue_db.loadDatabase(function (err) {
		if (!err){
			tweetQueue_db.find({}, function (err, docs) {
				res.send(docs);
			});
		}
		else {
			res.sendStatus(500);
		}
	});
});

//show displayQueue
app.get('/displayQueue', function (req, res) {
	displayQueue_db.loadDatabase(function (err) {
		if (!err){
			displayQueue_db.find({}, function (err, docs) {
				res.send(docs);
			});
		}
		else {
			res.sendStatus(500);
		}
	});
});

//show displayedTweets
app.get('/displayedTweets', function (req, res) {
	displayedTweets_db.loadDatabase(function (err) {
		if (!err){
			displayedTweets_db.find({}, function (err, docs) {
				res.send(docs);
			});
		}
		else {
			res.sendStatus(500);
		}
	});
});

//move to display queue
app.post('/displayQueue', urlencodedParser, function (req, res) {
	if (!req.body) { 
		return res.sendStatus(400); 
	}
	else {
		authenticate(req.body.auth).then(function(authSuccess){
			if (authSuccess){
				var loadSuccess = false;

				displayQueue_db.loadDatabase();

				var tweetID = Number(req.body.tweetId);

				var queueTweet = {
					"id" : tweetID,
					created_at: new Date(req.body.tweetCreated_at),
					message : req.body.tweetMessage,
					errorCount: 0
				};
				displayQueue_db.insert(queueTweet);

				tweetQueue_db.loadDatabase(function (err) {
					if (!err){
						tweetQueue_db.remove({id: tweetID});
					}
					else {
						res.sendStatus(500);
					}
				});

				return res.sendStatus(200);
			}
		});
	}
});

//move to displayed tweets
app.post('/displayedTweets', urlencodedParser, function (req, res) {
	if (!req.body) { 
		return res.sendStatus(400); 
	}
	else {
		authenticate(req.body.auth).then(function(authSuccess){
			if (authSuccess){
				displayedTweets_db.loadDatabase();

				var tweetID = Number(req.body.tweetId);

				var queueTweet = {
					"id" : tweetID,
					message: req.body.tweetMessage,
					displayed_at: new Date(req.body.displayed_at),
					displayed : req.body.displayed === "true"
				};
				displayedTweets_db.insert(queueTweet);

				
				tweetQueue_db.loadDatabase(function (err) {
					if (!err){
						tweetQueue_db.remove({id: tweetID}, {});
					}
					else {
						res.sendStatus(500);
					}
				});

				displayQueue_db.loadDatabase(function (err) {
					if (!err){
						displayQueue_db.remove({id: tweetID});
					}
					else {
						res.sendStatus(500);
					}
				});

				res.sendStatus(200);
			}
		});
	}
});

function authenticate(token){
	var deferred = Q.defer();

	login_db.loadDatabase(function (err) {
		if (!err){
			login_db.findOne({}, function (err, doc) {
				if (doc !== null && token == doc.token){
					deferred.resolve(true);
				}
				else {
					deferred.resolve(false);
				}
			});
		}
		else {
			deferred.reject();
		}
	});

	return deferred.promise;
}

/*var privateKey = fs.readFileSync( 'privatekey.pem' );
var certificate = fs.readFileSync( 'certificate.pem' );

https.createServer({
    key: privateKey,
    cert: certificate
}, app).listen(3000);*/

var server = app.listen(3000, function () {
  var host = server.address().address;
  var port = server.address().port;
  console.log('TweetSkirt Moderation API listening at http://%s:%s', host, port);
});