#include "twitter_create.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function that handles the twitter system
void create_twitter_system(twitter * twitterApp){

    int num;
    userPtr currptr;
    twitterApp->headPtr = NULL;
    twitterApp->tweetHeadPtr = NULL;
    printf("Enter the number of users you want to create:\n");
    scanf("%d", &num);
    printf("Enter their usernames: \n");
    fflush(stdin);

    for (int i = 0; i < num; i++){

        userPtr newptr = malloc(sizeof(user));

        if (newptr != NULL){

            fgets(newptr->username, USR_LENGTH, stdin);

            if (newptr->username[strlen(newptr->username) - 1] == '\n') {//replacing newline with end of file terminator
                //for comparison purposes
                newptr->username[strlen(newptr->username) - 1] = '\0';
            }

            newptr->num_followers = 0;
            newptr->num_following = 0;
            newptr->nextptr = NULL;

        }

        if (twitterApp->headPtr == NULL){

            twitterApp->headPtr = newptr;

        }

        else{

            currptr = twitterApp->headPtr;
            while (currptr->nextptr != NULL){

                currptr = currptr->nextptr;

            }

            currptr->nextptr = newptr;

        }

    }

    currptr = twitterApp->headPtr;
    printf("Current Users on the system:\n");
    puts("--------------------------------------------------------------------------");

    while (currptr != NULL){

        printf("\nUser:%s\t\t|  Following:%d\t    Followers:%d", currptr->username, currptr->num_following, currptr->num_followers);
        currptr = currptr->nextptr;

    }

    currptr = twitterApp->headPtr;
    int choice;

    while (1) {

        printf("\n\nCurrent User: %s\n", currptr->username);
        choice = menu(twitterApp, currptr); //calling menu to show all options

        if (choice == 6){

            if (currptr->nextptr == NULL){

                currptr = twitterApp->headPtr;

            }

            else{

                currptr = currptr->nextptr;

            }

        }

        else if (choice == 7){

            break;

        }

    }

}