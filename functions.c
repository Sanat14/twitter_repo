#include "twitter_create.h"
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void follow(twitter *ts, user *ptr)
{
    char followUser[USR_LENGTH];
    printf("Which user do you want to follow\n");
    fflush(stdin);
    fgets(followUser, USR_LENGTH, stdin);
    if(followUser[strlen(followUser) -1] == '\n')
    {
        followUser[strlen(followUser) - 1] = '\0';
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
    int user_check = 0;
    while(currptr != NULL)
    {
        if(strcasecmp(currptr->username,followUser) == 0)
        {
            strcpy(ptr->following[ptr->num_following], currptr->username );
            ptr->num_following++;
            strcpy(currptr->followers[currptr->num_followers], ptr->username);
            currptr->num_followers++;
            user_check = 1;
            break;
        }
        else{
            currptr = currptr->nextptr;
        }
    }
    printf("you are now following %s\n", followUser);
    if(user_check == 0)
    {
        puts("User does not exist.");
        return;
    }
}
void unfollow(twitter *ts, user *ptr)
{
    char name[USR_LENGTH];
    char null[USR_LENGTH];
    userPtr currptr;
    currptr = ts->headPtr;
    for(int i = 0; i < USR_LENGTH; i++)
    {
        null[i] = '\0';
    }
    printf("\nWhich user do you want to unfollow:\n");
    fflush(stdin);
    fgets(name,USR_LENGTH,stdin);
    char* p;
    if((p= strchr(name,'\n'))!=NULL)
    {
        *p = '\0';
    }
    int check = 0;
    for(int j = 0; j<ptr->num_following; j++){
        if(strcmp(ptr->following[j], name) == 0)
        {
            strcpy(ptr->following[j], null);
            ptr->num_following--;
            check = 1;
            break;
        }
    }
    printf("You have unfollowed %s", name);
    if(check == 0)
    {
        printf("You don't follow this user");
        return;
    }
    while(currptr->nextptr != NULL)
    {
        if(strcasecmp(currptr->username, name) == 0){
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
    userPtr tmp;
    tmp = ts->headPtr;
    if(curruser == ts->headPtr)
    {
        ts->headPtr = curruser->nextptr;
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
}

void postTweet(twitter *ts, user* ptr)
{
    tweetPtr currptr = malloc(sizeof(struct tweet));
    printf("What's on your mind?\n");
    fgets(currptr->msg, TWEET_LENGTH,stdin);
    fflush(stdin);
    if(currptr->msg[strlen(currptr->msg) - 1] == '\n') {
        currptr->msg[strlen(currptr->msg) - 1] = '\0';
    }
    strcpy(currptr->user,ptr->username);
    if(ts->tweetHeadPtr == NULL){
        ts->tweetHeadPtr=currptr;
        currptr->nextPtr=NULL;
    }
    else
    {
        currptr->nextPtr=ts->tweetHeadPtr;
        ts->tweetHeadPtr= currptr;
    }
}
void getNewsFeed(twitter *ts, user *currUser)
{
    tweetPtr currptr; //temp ptr
    int tweet_check = 0;
    currptr = ts->tweetHeadPtr;
    while(currptr != NULL)
    {
        for(int i=0;i<currUser->num_following;i++)
        {
            if (strcasecmp(currptr->user, currUser->following[i])==0 || strcasecmp(currptr->user, currUser->username)==0)
            {
                tweet_check++;
                printf("%s\n", currptr->msg);
            }
        }

        if(currUser->num_following==0)
        {
            printf("%s\n", currptr->msg);
        }
        if(tweet_check==10)
        {
            break;
        }
        currptr = currptr->nextPtr;
    }
}

