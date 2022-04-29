#include "twitter_create.h"
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void follow(twitter *ts, user *ptr)
{
    char mUser[USR_LENGTH];
    printf("Enter user you want to Follow:\n");
    fflush(stdin);
    fgets(mUser, USR_LENGTH, stdin);
    if(mUser[strlen(mUser) -1] == '\n')
    {
        mUser[strlen(mUser) - 1] = '\0';
    }
    for(int d = 0; d < MAX_FOLLOWING; d++){
        if(strcasecmp(mUser,ptr->username)==0){
            printf("You are not allowed to follow yourself!\n Try entering a different user.\n");
            return;
        }
        if(strcasecmp(mUser,ptr->following[d])==0){
            printf("You already follow this User!\n No point in following them twice!\n\n");
            return;
        }
    }
    userPtr currptr;
    currptr = ts->headPtr;
    int user_check = 0;
    while(currptr != NULL)
    {
        if(strcasecmp(currptr->username,mUser) == 0)
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
    if(user_check == 0)
    {
        puts("Username you have entered is not in the System! You will be returned to the menu Now!");
        return;
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

void unfollow(twitter *ts, user *ptr)
{
    char name[USR_LENGTH];
    char null[USR_LENGTH];
    userPtr currptr;
    currptr = ts->headPtr;
    for(int j = 0; j < USR_LENGTH; j++)
    {
        null[j] = '\0';
    }
    printf("\nEnter username of the user you would like to unfollow:\n");
    fflush(stdin);
    fgets(name,USR_LENGTH,stdin);
    if(name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    int i, check = 0;
    for(i = 0; ptr->num_following; i++){
        if(strcmp(ptr->following[i], name) == 0)
        {
            strcpy(ptr->following[i], null);
            ptr->num_following--;
            check = 1;
            break;
        }
    }
    if(check == 0)
    {
        printf("Error, entered user not found.\n"
               "You do not follow this User.\n");
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
        if(strcmp(currptr->followers[i], ptr->username) == 0){
            strcpy(currptr->followers[i], null);
            currptr->num_followers--;
            break;
        }
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
        if(tweet_check==10)
        {
            break;
        }
        currptr = currptr->nextPtr;
    }
}

