var loginCreds = require('./loginConfig');
var config = require('./config');

function checkCookie(){
  var authCookie = $.cookie("tweetSkirtAuth");
  if (authCookie !== undefined){
      $.ajax({
          url: config.rootURL + "/checkCookie?token=" + authCookie
      }).then(function(data) { //TODO ERRORS
         if (data){
          $('#error').text("");
          $('#login').css("display", "none");
          $('#tweetQueue').css("display", "block");
          $('#displayQueue').css("display", "block");
          $('#navBarList').append("<li class=\"active\"><a onclick=\"logout()\">Logout</a></li>");

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
      $('#tweetQueue').css("display", "block");
      $('#displayQueue').css("display", "block");
      $('#navBarList').append("<li class=\"active\"><a onclick=\"logout()\">Logout</a></li>");


      $.cookie("tweetSkirtAuth", res.jwt);

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

function logout(){
  var authCookie = $.cookie("tweetSkirtAuth");
  if (authCookie !== undefined){
      $.ajax({
          url: config.rootURL + "/logout?token=" + authCookie
      }).then(function(data) { //TODO ERRORS
         if (data){
          $('#error').text("");
          $('#login').css("display", "block");
          $('#tweetQueue').css("display", "none");
          $('#displayQueue').css("display", "none");
          $('#navBarList > li.active').remove();
          $('.tweet').remove();
         }
      });
  }
}

function populateQueues(){
  getTweetQueue().then(function(tweetQueue, tweetErr){
    getDisplayQueue().then(function(displayQueue, displayErr){
      //tweetQueue
      var tweetContainer = d3.select("#tweetQueue > .panel-body > ul.list-group");
      var tweets = tweetContainer.selectAll(".list-group-item").data(tweetQueue, function(d){return d._id;});
      var tweet = tweets.enter().append("li").classed("list-group-item", true);
      tweets.exit().remove();

      tweet.append("p").classed("tweetMessage", true).text(function(d){return d.message;});

      tweet.append("button")
        .attr("type", "button")
        .classed("btn", true)
        .classed("btn-primary", true)
        .text("Display").on('click', function(d, i){
          moveToDisplay(d).then(function(){
            populateQueues();
          });
        });

      tweet.append("button")
        .attr("type", "button")
        .classed("btn", true)
        .classed("btn-default", true)
        .text("Remove").on('click', function(d, i){
          removeFromQueue(d).then(function(){
            populateQueues();
          });
        });

      //displayQueue
      var displayContainer = d3.select("#displayQueue > .panel-body > ul.list-group");
      var displayTweets = displayContainer.selectAll(".list-group-item").data(displayQueue, function(d){return d._id;});
      var displayTweet = displayTweets.enter().append("li").classed("list-group-item", true);
      displayTweets.exit().remove();

      displayTweet.append("p").classed("tweetMessage", true).text(function(d){return d.message;});
      
      displayTweet.append("button")
        .attr("type", "button")
        .classed("btn", true)
        .classed("btn-default", true)
        .text("Remove").on('click', function(d, i){
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
    data: {tweetId: d.id, tweetMessage: d.message, tweetCreated_at: new Date(d.created_at), auth:$.cookie("tweetSkirtAuth")},
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
    data: {tweetId: d.id, displayed_at: new Date(), displayed: false, auth:$.cookie("tweetSkirtAuth")},
    success: function(){ deferred.resolve(); } 
  });

  return deferred.promise;
}