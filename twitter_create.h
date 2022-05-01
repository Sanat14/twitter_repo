
#ifndef PROJECT2_TWITTER_CREATE_H
#define PROJECT2_TWITTER_CREATE_H

//Max length of a tweet
#define TWEET_LENGTH 270

//Max length of a username
#define USR_LENGTH 100

//Max num of a followers
#define MAX_FOLLOWERS 30

//Max num of following users
#define MAX_FOLLOWING 30


typedef struct tweet{

    int id;
    char msg[TWEET_LENGTH];
    char user[USR_LENGTH];
    struct tweet *nextPtr;

}tweet;

typedef tweet *tweetPtr;

typedef struct user{

    char username[USR_LENGTH];
    char followers[MAX_FOLLOWERS][USR_LENGTH];
    int num_followers;
    char following[MAX_FOLLOWING][USR_LENGTH];
    int num_following;
    struct user *nextptr;

}user;

typedef user *userPtr;

typedef struct twitter{

    userPtr headPtr;
    tweetPtr tweetHeadPtr;

} twitter;

void create_twitter_system(twitter * ts); 

#endif //PROJECT2_TWITTER_CREATE_H