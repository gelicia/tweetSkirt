var loginCreds = require('./loginConfig');
 
function submitForm(){ 
  var username = $('#username').val();
  var password = md5($('#password').val() + loginCreds.salt);

  login().done(function(err, res){

  });

}

function login(username, password){
  var deferred = q.defer();

  $.ajax({
        url: "http://rest-service.guides.spring.io/greeting"
    }).then(function(data) {
       $('.greeting-id').append(data.id);
       $('.greeting-content').append(data.content);
    });

  return deferred.promise;
}