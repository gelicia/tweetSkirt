## tweetSkirt

This is a repository for all work related to making scrolling, dynamically built strings work on an LED array. Then it's about making tweets display on that array, because the internet of things is really about hooking everything up to twitter.

### /sparktweet/
The sparktweet directory is the code that sets up the function on a spark core. It exposes a REST call that can be passed a string and a couple other functions will display and scroll it on an LED array.

It does require the spark neopixel library. The file is **buildString.ino** and you are looking for line 972 that has the actual program and not just the character setup.

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
This directory contains the node program that will look to twitter for tweets and queue them to display, then display them off the queue.

Run `npm install` in the directory to install all dependencies. Rename sparkConfigTEMP.js and twitterConfigTEMP.js to not have TEMP in the name, and fill in the IDs, keys and tokens from twitter and spark.

You are interested in the **bot.js** file.

The program gets messages from two sources - mentions to @tweetSkirt and recent uses of #tweetSkirt. Tweets that have not been displayed before go in the queue, and then a seperate process pulls things from the queue. Currently, it looks for new tweets every 3 minutes, and will rotate the display every minute. 

For mentions, it grabs the last 50, and finds any that are less than 24 hours old that have not been displayed before. For #tweetSkirt usage, it grabs the last 50 "recent" (recent is up to the twitter search API) and finds any that have not been displayed before.

Any tweets that have been displayed have their IDs stored in a small database. Tweets don't have their ID stored until after the display was successful. 

### Other 
 **tweetskirt.ino** is an old file and I will update it maybe someday (probably not). 

The **ASCII Array Building directory** contains all the files for turning individual letters into strings of 1s and 0s to show if an LED should be lit or not, and also record the length of each character so we know how much 0 padding we need. Thanks to [Scott Lembcke](https://github.com/slembcke) for his ideas and help with this great way of saving space! You shouldn't need to run this again, this is just for reference.