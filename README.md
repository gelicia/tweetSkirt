tweetSkirt
==========
This is a repository for all work related to making scrolling, dynamically built work on an LED array.

The ASCII Array Building directory contains all the files for parsing the individual letters and their lengths. Thanks to [Scott Lembcke](https://github.com/slembcke) for his help! You shouldn't need to run this again, this is just for reference.

The sparktweet directory is the code for getting this to run on a spark core, with text passing via a REST call. The Spark has a 63 length limit on the args being passed in, so to use the REST calls, you will need to do a series of calls. The calls need to begin with a 0 or 1 to indicate if it's an admin message or not. Of the admin calls, they will need to be either BEGIN to clear out the previous message or END to tell the Spark that you're done appending messages and it can display the whole string.

All non admin messages are simply appended together.

Keep in mind that, with the usage of two extra characters for the admin flag, you will need to split up each message to be 61 characters or less.

curl https://api.spark.io/v1/devices/deviceID/buildString -d access_token=accessToken -d "args=1,BEGIN"

curl https://api.spark.io/v1/devices/deviceID/buildString -d access_token=accessToken -d "args=0,Message one "

curl https://api.spark.io/v1/devices/deviceID/buildString -d access_token=accessToken -d "args=0,Message two "

curl https://api.spark.io/v1/devices/deviceID/buildString -d access_token=accessToken -d "args=1,END"