## tweetSkirt
==========

This is a repository for all work related to making scrolling, dynamically built strings work on an LED array.

### /sparktweet/
The sparktweet directory is the code that sets up the function on a spark core. It exposes a REST call that can be passed a string and a couple other functions will display and scroll it on an LED array.

The Spark has a 63 length limit on the args being passed in, so to use the REST calls, you will need to do a series of calls. The calls need to begin with a 0 or 1 to indicate if it's an admin message or not. Of the admin calls, they will need to be either BEGIN to clear out the previous message or END to tell the Spark that you're done appending messages and it can display the whole string.

All non admin messages are simply appended together.

Keep in mind that, with the usage of two extra characters for the admin flag, you will need to split up each message to be 61 characters or less.

An example series of calls looks like the following:

```
curl https://api.spark.io/v1/devices/deviceID/buildString -d access_token=accessToken -d "args=1,BEGIN"

curl https://api.spark.io/v1/devices/deviceID/buildString -d access_token=accessToken -d "args=0,Message one "

curl https://api.spark.io/v1/devices/deviceID/buildString -d access_token=accessToken -d "args=0,Message two "

curl https://api.spark.io/v1/devices/deviceID/buildString -d access_token=accessToken -d "args=1,END"
```

### /sparktweet-twitter-bot/
For the twitter part, the bot gets messages from two sources - mentions to @tweetSkirt and recent uses of the #tweetSkirt. Tweets that have not been displayed before go in the queue, and then a seperate process pulls things from the queue. Currently, it looks for new tweets every 3 minutes, and will rotate the display every minute. 

For mentions, it grabs the last 50, and finds any that are less than 24 hours old that have not been displayed before. For #tweetSkirt usage, it grabs the last 50 "recent" (have been told this means within the last day) and finds any that have not been displayed before.

### Other 
 **tweetskirt.ino** is an old file and I will update it maybe someday (probably not). 

The **ASCII Array Building directory** contains all the files for parsing the individual letters and their lengths. Thanks to [Scott Lembcke](https://github.com/slembcke) for his help! You shouldn't need to run this again, this is just for reference.