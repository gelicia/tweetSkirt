var loginCreds = require('./loginConfig');
var config = require('./config');
 
function submitForm(){ 
  var username = $('#username').val();
  var password = md5($('#password').val() + loginCreds.salt);

  login(username, password).then(function(res, err){
    if (res.success){
      $('#error').text("");
      console.log(res);
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