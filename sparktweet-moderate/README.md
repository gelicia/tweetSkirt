The server and the app are both in this folder until I decide if it makes sense to split it up or not.

app
===
bower_components
js
bower.json
configTEMP.js - config for where the server is hosted. remove TEMP from name and add your info
loginConfigTEMP.js - needed for the salt
index.html

server
===
node_modules
loginConfigTEMP.js - needed to check the final hash
package.json
server.js