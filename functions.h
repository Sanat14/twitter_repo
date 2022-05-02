

#ifndef ENGPROJECT2_FUNCTIONS_H
#define ENGPROJECT2_FUNCTIONS_H

#include "twitter_create.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void follow(twitter *ts, user *ptr);
void unfollow(twitter *ts, user *ptr);
void delete(twitter *ts, user *curruser);
void auxDelete(twitter *ts, user *curruser);
void postTweet(twitter *ts, user *userPtr);
void getNewsFeed(twitter *ts, user *currUser);

#endif //ENGPROJECT2_FUNCTIONS_H
