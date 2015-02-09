var express = require('express');
var levelup = require('level');
var app = express();

var tweetQueue_db = levelup('./tweetQueue');

app.get('/tweetQueue', function (req, res) {
	var tweets = [];

	tweetQueue_db.createReadStream()
	.on('data', function (data) {
		tweets = data.value;
	})

  //res.send('about')
})