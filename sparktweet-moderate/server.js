var express = require('express');
var Datastore = require('nedb');

var loginCreds = require('./loginConfig');

var app = express();

app.get('/tweetQueue', function (req, res) {
	var tweetQueue_db = new Datastore({filename: '../sparktweet-twitter-bot/tweetQueue.db', autoload:true});
	tweetQueue_db.find({}, function (err, docs) {
		res.send(docs);
	});
});

app.get('/login', function (req, res) {

	//loginCreds.salt;
	//loginCreds.md5Password;

	console.log(req.query.username);
	console.log(req);
	res.send();
});

var server = app.listen(3000, function () {

  var host = server.address().address;
  var port = server.address().port;

  console.log('Example app listening at http://%s:%s', host, port)

})