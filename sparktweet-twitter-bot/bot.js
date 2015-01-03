// Our Twitter library
var Twit = require('twit');
var rest = require('restler');

// We need to include our configuration file
var T = new Twit(require('./twitterConfig.js'));
var sparkConfig = require('./sparkConfig.js');