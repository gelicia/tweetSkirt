var loginCreds = require('./loginConfig');
 
function submitLogin(){ 
  var username = $('#username').val();
  var password = md5($('#password').val() + loginCreds.salt);
  console.log(password);
}