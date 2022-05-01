
#include <stdio.h>
#include <stdlib.h>
#include "twitter_create.h"

int main()
{
    twitter ts;
    create_twitter_system(&ts); // Calling the function
    userPtr currptr = ts.headPtr; // Calling the headPtr inside the twitter system
    printf("Last Active Users: \n");
    puts("--------------------------------------------------------------------------");

    if(ts.headPtr == NULL){

        exit(EXIT_SUCCESS);

    }

    // Prints out all the users linked list style
    while(currptr != NULL){

        printf("User:%s\t\t  Following:%d\t    Followers:%d\n", currptr->username, currptr->num_following, currptr->num_followers);
        currptr = currptr->nextptr;

    }

    return 0;

}
