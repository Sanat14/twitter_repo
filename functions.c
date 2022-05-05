#include "twitter_create.h"
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int tweetId = 1;

//function to follow a user
void follow(twitter *twitterApp, user *ptr){

    char followUser[USR_LENGTH];

    printf("Which user do you want to follow\n");
    fflush(stdin);
    fgets(followUser, USR_LENGTH, stdin);

    char* p;

    //replacing the new line character with the null terminator
    if((p = strchr(followUser, '\n')) != NULL){

        *p = '\0';

    }

    //conditions to ensure the user can't follow themselves or someone they already follow
    for(int i = 0; i < MAX_FOLLOWING; i++){

        if(strcasecmp(followUser, ptr->username) == 0){

            printf("You can't follow yourself!\n");
            return;

        }

        if(strcasecmp(followUser, ptr->following[i]) == 0){

            printf("You already follow this User!\n");
            return;

        }

    }

    userPtr currptr;
    currptr = twitterApp->headPtr;
    int userCheck = 0;

    //loop to increment the number of followers and following
    //and modify the respective arrays
    while(currptr != NULL){

        if(strcasecmp(currptr->username, followUser) == 0){

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

    if(userCheck == 1){

        printf("You are now following %s\n", followUser);

    }

    //condition to check if the user exists
    if(userCheck == 0){

        puts("User does not exist.");
        return;

    }

}

//function to unfollow a user
void unfollow(twitter *twitterApp, user *ptr){

    char userUnf[USR_LENGTH];
    char empty[USR_LENGTH];
    userPtr currptr;
    currptr = twitterApp->headPtr;

    //creating an empty array
    for(int j = 0; j < USR_LENGTH; j++){

        empty[j] = '\0';

    }

    printf("\nWhich user do you want to unfollow:\n");
    fflush(stdin);
    fgets(userUnf,USR_LENGTH,stdin);
    char* p;

    if((p = strchr(userUnf, '\n')) != NULL){

        *p = '\0';

    }

    int i, userCheck = 0;

    //loop to decrease the number of following and modify the array
    for(i = 0; i < ptr->num_following; i++){

        if(strcmp(ptr->following[i], userUnf) == 0){

            strcpy(ptr->following[i], empty);
            ptr->num_following--;
            userCheck = 1;
            break;

        }

    }

    if(userCheck == 1){

        printf("You have unfollowed %s", userUnf);

    }

    //condition to check if the user entered was valid
    if(userCheck == 0){

        printf("You can only unfollow users you follow. Please enter a valid user");
        return;

    }

    while(currptr->nextptr != NULL){

        if(strcasecmp(currptr->username, userUnf) == 0){

            break;

        }

        currptr = currptr->nextptr;

    }

    //loop to decrease the number of followers and modify the array
    for(int j = 0; j < currptr->num_followers; j++){

        if(strcmp(currptr->followers[j], ptr->username) == 0){

            strcpy(currptr->followers[j], empty);
            currptr->num_followers--;
            break;

        }

    }

}

//function to delete a user's account
void delete(twitter *twitterApp, user *curruser){

    printf("%s has deleted their account", curruser->username);
    userPtr tmp;
    tmp = twitterApp->headPtr;

    //condition to call the function to delete the user from the twitter system if the first user is to be deleted
    if(curruser == twitterApp->headPtr){

        twitterApp->headPtr = curruser->nextptr;
        auxDelete(twitterApp, curruser);
        free(curruser);
        return;

    }

    //iterating till the user is found in the system
    while(strcasecmp(tmp->nextptr->username, curruser->username) != 0){

        tmp = tmp->nextptr;

    }

    //calling the function to delete the required user from the system
    tmp->nextptr = curruser->nextptr;
    auxDelete(twitterApp, curruser);
    free(curruser);

}

//function to delete the user from the followers and following arrays and delete the user's tweets
void auxDelete(twitter *twitterApp, user *curruser){

    char tmpuser[USR_LENGTH];

    //loop to keep modifying the following array until the desired result is obtained
    for(int i = 0; i < curruser->num_followers; i++){
        strcpy(tmpuser,curruser->followers[i]);
        userPtr tmpptr = twitterApp->headPtr;

        while(strcasecmp(tmpptr->username, tmpuser)!=0){

            tmpptr = tmpptr->nextptr;

        }

        int k = 0;

        while(strcasecmp(tmpptr->following[k], curruser->username) != 0){

            k++;

        }

        for(int l = k + 1; l < tmpptr->num_following; l++){

            strcpy(tmpptr->following[k], tmpptr->following[l]);
            k++;

        }

        tmpptr->num_following--;

    }

    //loop to keep modifying the followers array until the desired result is obtained
    for(int i = 0; i < curruser->num_following; i++){

        strcpy(tmpuser, curruser->following[i]);
        userPtr tmpptr = twitterApp->headPtr;

        while(strcasecmp(tmpptr->username, tmpuser) != 0){

            tmpptr = tmpptr->nextptr;

        }

        int k = 0;

        while(strcasecmp(tmpptr->followers[k], curruser->username) != 0){

            k++;

        }

        for(int l = k + 1; l < tmpptr->num_followers; l++){

            strcpy(tmpptr->followers[k], tmpptr->followers[l]);
            k++;

        }

        tmpptr->num_followers--;

    }

    //condition to stop the deletion process if there are no tweets left in the system
    if(twitterApp->tweetHeadPtr == NULL){

        return;

    }

    tweetPtr currtweet = twitterApp->tweetHeadPtr;
    tweetPtr prevtweet = twitterApp->tweetHeadPtr->nextPtr;

    //loop to run until all the tweets are deleted
    while(currtweet != NULL){

        if(strcasecmp(curruser->username, currtweet->user) == 0){

            if(currtweet == twitterApp->tweetHeadPtr){

                twitterApp->tweetHeadPtr = currtweet->nextPtr;
                free(currtweet);
                currtweet = twitterApp->tweetHeadPtr->nextPtr;
                continue;

            }

            prevtweet->nextPtr = currtweet->nextPtr;
            free(currtweet);
            currtweet = prevtweet->nextPtr;
            continue;

        }

        //pointing to the next tweet
        prevtweet = currtweet;
        currtweet = currtweet->nextPtr;

    }

}

//function to post a tweet
void postTweet(twitter *twitterApp, user* userPtr){

    tweetPtr currptr = malloc(sizeof(struct tweet));
    printf("Enter your message.\n");
    fgets(currptr->msg, TWEET_LENGTH,stdin);
    currptr->id = tweetId; //assigning the tweetID to the corresponding message
    tweetId++;
    fflush(stdin);

    if(currptr->msg[strlen(currptr->msg) - 1] == '\n'){

        currptr->msg[strlen(currptr->msg) - 1] = '\0';

    }

    strcpy(currptr->user, userPtr->username);

    if(twitterApp->tweetHeadPtr == NULL){

        twitterApp->tweetHeadPtr = currptr;
        currptr->nextPtr = NULL;

    }
    else{

        currptr->nextPtr = twitterApp->tweetHeadPtr;
        twitterApp->tweetHeadPtr = currptr;

    }

}

//function to show the user the news feed
void getNewsFeed(twitter *twitterApp, user *currUser){

    tweetPtr currptr;
    int count = 0;
    currptr = twitterApp->tweetHeadPtr;

    //loop will run until all the required tweets are shown to the user
    while(currptr != NULL){

        if(currUser->num_following > 0){

            for (int i = 0; i <= currUser->num_following; i++) {

                if (strcasecmp(currptr->user, currUser->following[i]) == 0 || strcasecmp(currptr->user, currUser->username) == 0){

                    count++;
                    printf("\n%s\n", currptr->msg);
                    printf("Posted by %s, tweetID: %d\n", currptr->user,currptr->id );
                    break;

                }

            }

        }

        else{

            if(strcasecmp(currptr->user, currUser->username) == 0){

                count++;
                printf("\n%s\n", currptr->msg);
                printf("Posted by %s, tweetID: %d\n", currptr->user,currptr->id);

            }

        }

        //condition to print only the 10 most recent tweets
        if(count == 10){

            break;

        }

        currptr = currptr->nextPtr;

    }

}
