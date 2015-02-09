var loginCreds = require('./loginConfig');
var config = require('./config');
 
function submitForm(){ 
  var username = $('#username').val();
  var password = md5($('#password').val() + loginCreds.salt);

  login(username, password).then(function(err, res){
    console.log(err, res);
  });

}

function login(username, password){
  var deferred = Q.defer();

  $.ajax({
        url: config.rootURL + "/login?password=" + password
    }).then(function(data) {
       console.log(data);
    });

  return deferred.promise;
}