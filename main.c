//Written by Sanat Dusad and Bhavya Bhatia
//Student numbers- 21352231 and 21206612
//C program that implements a simplified version of the Twitter platform.
#include <stdio.h>
#include <stdlib.h>
#include "twitter_create.h"

int main()
{
    twitter twitterApp;
    //Calling function which handles the entire twitter system.
    create_twitter_system(&twitterApp);
    userPtr currptr = twitterApp.headPtr;
    printf("Last Active Users: \n");
    printf("--------------------------------------------------------------------------\n");

    if(twitterApp.headPtr == NULL){

        exit(EXIT_SUCCESS);

    }

    //prints the last active users on the platform
    while(currptr != NULL){

        printf("User:%s\t\t  Following:%d\t    Followers:%d\n", currptr->username, currptr->num_following, currptr->num_followers);
        currptr = currptr->nextptr;

    }

    return 0;

}
