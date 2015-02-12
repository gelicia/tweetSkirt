var loginCreds = require('./loginConfig');
var config = require('./config');

function checkCookie(){
  if (document.cookie !== undefined){
      $.ajax({
          url: config.rootURL + "/checkCookie?token=" + document.cookie
      }).then(function(data) { //TODO ERRORS
         if (data){
          $('#error').text("");
          $('#login').css("display", "none");
          $('#title').text("Moderation");
          populateQueues();
         }
      });
  }
}
 
function submitForm(){ 
  var username = $('#username').val();
  var password = md5($('#password').val() + loginCreds.salt);

  login(username, password).then(function(res, err){
    if (res.success){
      $('#error').text("");
      $('#login').css("display", "none");
      $('#title').text("Moderation");

      document.cookie = res.jwt;

      populateQueues();
    }
    else {
      $('#error').text("Incorrect password"); 
    }
  });
}

function login(username, password){
  var deferred = Q.defer();

  $.ajax({
        url: config.rootURL + "/login?password=" + password
    }).then(function(data) { //TODO ERRORS
       deferred.resolve(data);
    });

  return deferred.promise;
}

function populateQueues(){
  getTweetQueue().then(function(tweetQueue, tweetErr){
    getDisplayQueue().then(function(displayQueue, displayErr){
      //tweetQueue
      var tweetContainer = d3.select("#tweetQueue");

      var tweets = tweetContainer.selectAll(".tweet").data(tweetQueue, function(d){return d._id;});

      var tweet = tweets.enter().append("div").classed("tweet", true);
      tweets.exit().remove();

      tweet.append("div").classed("tweetMessage", true).text(function(d){return d.message;});

      tweet.append("div").classed("textBtn", true).text("Display").on('click', function(d, i){
        moveToDisplay(d).then(function(){
          populateQueues();
        });
      });

      tweet.append("div").classed("textBtn", true).text("Remove").on('click', function(d){
        removeFromQueue(d).then(function(){
          populateQueues();
        });
      });

      //displayQueue
      var displayContainer = d3.select("#displayQueue");
      var displayTweets = displayContainer.selectAll(".tweet").data(displayQueue, function(d){return d._id;});
      var displayTweet = displayTweets.enter().append("div").classed("tweet", true);
      displayTweets.exit().remove();

      displayTweet.append("div").classed("tweetMessage", true).text(function(d){return d.message;});
      displayTweet.append("div").classed("textBtn", true).text("Remove").on('click', function(d){
        removeFromQueue(d).then(function(){
          populateQueues();
        });
      });
    });
  });
}

function getTweetQueue(){
  var deferred = Q.defer();

  $.ajax({
        url: config.rootURL + "/tweetQueue"
    }).then(function(data) { //TODO ERRORS
       deferred.resolve(data);
    });

  return deferred.promise;
}

function getDisplayQueue(){
  var deferred = Q.defer();

  $.ajax({
        url: config.rootURL + "/displayQueue"
    }).then(function(data, err) { //TODO ERRORS
       deferred.resolve(data);
    });

  return deferred.promise;
}

function moveToDisplay(d){
  var deferred = Q.defer();

  $.ajax({ 
    url: config.rootURL + "/displayQueue", 
    type: 'POST', 
    contentType: 'application/x-www-form-urlencoded', 
    data: {tweetId: d.id, tweetMessage: d.message, tweetCreated_at: new Date(d.created_at), auth:document.cookie},
    success: function(){ deferred.resolve(); } 
  });

  return deferred.promise;
}

function removeFromQueue(d){
    var deferred = Q.defer();

  $.ajax({ 
    url: config.rootURL + "/displayedTweets", 
    type: 'POST', 
    contentType: 'application/x-www-form-urlencoded', 
    data: {tweetId: d.id, displayed_at: new Date(), displayed: false, auth:document.cookie},
    success: function(){ deferred.resolve(); } 
  });

  return deferred.promise;
}