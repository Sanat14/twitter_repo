//
// Created by dusad on 16/04/2022.
//
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "twitter_create.h"
#define MAX 100

void postTweet()
{
    printf("postTweet function is invoked\n");
}
void getNewsFeed()
{
    printf("getNewsFeed function is invoked\n");
}
void follow(char users[], char userToFollow[])
{
    user *userPtr= (user *) users;
    user *user2Ptr= (user *) userToFollow;
    strcpy(&userPtr->following[userPtr->num_following], user2Ptr->username);
    userPtr->num_following++;
    strcpy(&user2Ptr->followers[user2Ptr->num_followers], userPtr->username);
    user2Ptr->num_followers++;
//    printf("follow function is invoked\n");
}
void unfollow()
{
    printf("unfollow function is invoked\n");
}
void delete()
{
    printf("delete function is invoked\n");
}
void endTurn()
{
    printf("endTurn function is invoked\n");
}
void endTwitter()
{
    printf("endTwitter function is invoked\n");
}