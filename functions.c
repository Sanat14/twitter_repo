#include "twitter_create.h"
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int tweetId = 1;
void follow(twitter *ts, user *ptr)
{
    char followUser[USR_LENGTH];
    printf("Which user do you want to follow\n");
    fflush(stdin);
    fgets(followUser, USR_LENGTH, stdin);
    char* p;
    if((p= strchr(followUser,'\n'))!=NULL)
    {
        *p = '\0';
    }
    for(int i = 0; i < MAX_FOLLOWING; i++){
        if(strcasecmp(followUser,ptr->username)==0){
            printf("You can't follow yourself!\n");
            return;
        }
        if(strcasecmp(followUser,ptr->following[i])==0){
            printf("You already follow this User!\n");
            return;
        }
    }
    userPtr currptr;
    currptr = ts->headPtr;
    int userCheck = 0;
    while(currptr != NULL)
    {
        if(strcasecmp(currptr->username,followUser) == 0)
        {
            strcpy(ptr->following[ptr->num_following], currptr->username );
            ptr->num_following++;
            strcpy(currptr->followers[currptr->num_followers], ptr->username);
            currptr->num_followers++;
            userCheck = 1;
            break;

        }
        else{
            currptr = currptr->nextptr;
        }

    }
    if(userCheck==1)
    {
        printf("you are now following %s\n", followUser);
    }
    if(userCheck == 0)
    {
        puts("User does not exist.");
        return;
    }
}
void unfollow(twitter *ts, user *ptr)
{
    char userUnf[USR_LENGTH];
    char null[USR_LENGTH];
    userPtr currptr;
    currptr = ts->headPtr;
    for(int i = 0; i < USR_LENGTH; i++)
    {
        null[i] = '\0';
    }
    printf("\nWhich user do you want to unfollow:\n");
    fflush(stdin);
    fgets(userUnf,USR_LENGTH,stdin);
    char* p;
    if((p= strchr(userUnf,'\n'))!=NULL)
    {
        *p = '\0';
    }
    int userCheck = 0;
    for(int j = 0; j<ptr->num_following; j++){
        if(strcmp(ptr->following[j], userUnf) == 0)
        {
            strcpy(ptr->following[j], null);
            ptr->num_following--;
            userCheck = 1;
            break;
        }
    }
    if(userCheck==1)
    {
        printf("You have unfollowed %s", userUnf);
    }

    if(userCheck == 0)
    {
        printf("You can only unfollow users you follow. Please enter a valid user.");
        return;
    }
    while(currptr->nextptr != NULL)
    {
        if(strcasecmp(currptr->username, userUnf) == 0){
            break;
        }
        currptr = currptr->nextptr;
    }
    for(int k = 0; k < currptr->num_followers; k++){
        if(strcmp(currptr->followers[k], ptr->username) == 0){
            strcpy(currptr->followers[k], null);
            currptr->num_followers--;
            break;
        }
    }
}
void delete(twitter *ts, user *curruser)
{
    printf("%s has deleted their account", curruser);
    userPtr tmp;
    tmp = ts->headPtr;
    if(curruser == ts->headPtr)
    {
        ts->headPtr = curruser->nextptr;
        auxDelete(ts, curruser);
        free(curruser);
        return;
    }
    while(strcasecmp(tmp->nextptr->username, curruser->username) != 0){
        tmp = tmp->nextptr;
    }
    tmp->nextptr = curruser->nextptr;
    auxDelete(ts, curruser);
    free(curruser);
}
void auxDelete(twitter *ts, user *curruser)
{
    char tmpuser[USR_LENGTH];
    for(int i = 0; i < curruser->num_followers; i++){
        strcpy(tmpuser,curruser->followers[i]);
        userPtr tmpptr = ts->headPtr;
        while(strcasecmp(tmpptr->username,tmpuser)!=0)
        {
            tmpptr = tmpptr->nextptr;
        }
        int k = 0;
        while(strcasecmp(tmpptr->following[k],curruser->username)!=0){
            k++;
        }
        for(int o = k+1; o < tmpptr->num_following; o++){
            strcpy(tmpptr->following[k],tmpptr->following[o]);
            k++;
        }
        tmpptr->num_following--;
    }
    for(int i = 0; i < curruser->num_following; i++){
        strcpy(tmpuser,curruser->following[i]);
        userPtr tmpptr = ts->headPtr;
        while(strcasecmp(tmpptr->username,tmpuser)!=0){
            tmpptr = tmpptr->nextptr;
        }
        int k = 0;
        while(strcasecmp(tmpptr->followers[k],curruser->username)!=0){
            k++;
        }
        for(int o = k+1; o < tmpptr->num_followers; o++){
            strcpy(tmpptr->followers[k],tmpptr->followers[o]);
            k++;
        }
        tmpptr->num_followers--;
    }

    if(ts->tweetHeadPtr == NULL){
        return;
    }
    tweetPtr currtweet = ts->tweetHeadPtr;
    tweetPtr prevtweet = ts->tweetHeadPtr->nextPtr;
    while(currtweet != NULL){
        if(strcasecmp(curruser->username,currtweet->user) == 0){
            if(currtweet == ts->tweetHeadPtr){
                ts->tweetHeadPtr = currtweet->nextPtr;
                free(currtweet);
                currtweet = ts->tweetHeadPtr->nextPtr;
                continue;
            }
            prevtweet->nextPtr = currtweet->nextPtr;
            free(currtweet);
            currtweet = prevtweet->nextPtr;
            continue;
        }
        prevtweet = currtweet;
        currtweet = currtweet->nextPtr;
    }
}
void postTweet(twitter *ts, user* userPtr)
{
    tweetPtr currptr = malloc(sizeof(struct tweet));
    printf("Enter your message.\n");
    fgets(currptr->msg, TWEET_LENGTH,stdin);
    currptr->id= tweetId;
    tweetId++;
    fflush(stdin);
    if(currptr->msg[strlen(currptr->msg) - 1] == '\n') {
        currptr->msg[strlen(currptr->msg) - 1] = '\0';
    }
    strcpy(currptr->user, userPtr->username);
    if(ts->tweetHeadPtr == NULL){
        ts->tweetHeadPtr = currptr;
        currptr->nextPtr = NULL;
    }
    else
    {
        currptr->nextPtr = ts->tweetHeadPtr;
        ts->tweetHeadPtr = currptr;
    }
}
void getNewsFeed(twitter *ts, user *currUser)
{
    tweetPtr currptr;
    int count = 0;
    currptr = ts->tweetHeadPtr;
    while(currptr != NULL)
    {
        if(currUser->num_following>0) {
            for (int i = 0; i < currUser->num_following; i++) {
                if (strcasecmp(currptr->user, currUser->following[i]) == 0 ||strcasecmp(currptr->user, currUser->username) == 0)
                {
                    count++;
                    printf("\n%s\n", currptr->msg);
                    printf("Posted by %s, tweetID: %d\n", currptr->user,currptr->id );
                    break;
                }
            }
        }

        else
        {
            if(strcasecmp(currptr->user, currUser->username)==0)
            {
                count++;
                printf("\n%s\n", currptr->msg);
                printf("Posted by %s, tweetID: %d\n", currptr->user,currptr->id);
            }

        }
        if(count==10)
        {
            break;
        }
        currptr = currptr->nextPtr;
    }
}

