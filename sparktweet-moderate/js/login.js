var loginCreds = require('./loginConfig');
var config = require('./config');
 
function submitForm(){ 
  var username = $('#username').val();
  var password = md5($('#password').val() + loginCreds.salt);

  login(username, password).then(function(res, err){
    if (res.success){
      $('#error').text("");
      $('#login').css("display", "none");
      $('#title').text("Moderation");

      getTweetQueue().then(function(tweetQueue, tweetErr){
        getDisplayQueue().then(function(displayQueue, displayErr){
          console.log("tweets", tweetQueue);
          console.log("display", displayQueue);
        });
      });

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
    }).then(function(data) {
       deferred.resolve(data);
    });

  return deferred.promise;
}

function getTweetQueue(){
  var deferred = Q.defer();

  $.ajax({
        url: config.rootURL + "/tweetQueue"
    }).then(function(data) {
       deferred.resolve(data);
    });

  return deferred.promise;
}

function getDisplayQueue(){
  var deferred = Q.defer();

  $.ajax({
        url: config.rootURL + "/displayQueue"
    }).then(function(data) {
       deferred.resolve(data);
    });

  return deferred.promise;
}