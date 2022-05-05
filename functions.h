#ifndef ENGASSIGNMENT2_FUNCTIONS_H
#define ENGASSIGNMENT2_FUNCTIONS_H

#include "twitter_create.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void follow(twitter *twitterApp, user *ptr);
void unfollow(twitter *twitterApp, user *ptr);
void delete(twitter *twitterApp, user *curruser);
void auxDelete(twitter *twitterApp, user *curruser);
void postTweet(twitter *twitterApp, user *ptr);
void getNewsFeed(twitter *twitterApp, user *currUser);

#endif //ENGASSIGNMENT2_FUNCTIONS_H

