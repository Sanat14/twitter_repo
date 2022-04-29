
#include "twitter_create.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create_twitter_system(twitter * ts) {
    int num;
    userPtr currptr;
    ts->headPtr = NULL;
    ts->tweetHeadPtr = NULL;
    printf("Enter the number of users you want to create:\n");
    scanf("%d", &num);
    printf("Enter usernames\n");
    fflush(stdin);
    for (int i = 0; i < num; i++) {
        userPtr newptr = malloc(sizeof(user));
        if (newptr != NULL) {
//            printf("\nEnter username of the next user or press 'tab key' then 'Enter' to exit:\n");
            fgets(newptr->username, USR_LENGTH, stdin);
//            if (newptr->username[0] == '\t') {
//                break;
//            }
            if (newptr->username[strlen(newptr->username) - 1] == '\n') {
                newptr->username[strlen(newptr->username) - 1] = '\0';
            }
            newptr->num_followers = 0;
            newptr->num_following = 0;
            newptr->nextptr = NULL;
        }
        if (ts->headPtr == NULL) {
            ts->headPtr = newptr;
        } else {
            currptr = ts->headPtr;
            while (currptr->nextptr != NULL) {
                currptr = currptr->nextptr;
            }
            currptr->nextptr = newptr;
        }
    }
    currptr = ts->headPtr;
    while (currptr != NULL) {
        printf("User: %s        following: %d\tfollowers: %d\n", currptr->username, currptr->num_followers,
               currptr->num_followers);
        currptr = currptr->nextptr;
    }
    currptr = ts->headPtr;
    int choice;
    while (1) {
        printf("\n\nCurrent User: %s\n", currptr->username);
        choice = menu(ts, currptr);
        if (choice == 6) {
            if (currptr->nextptr == NULL) {
                currptr = ts->headPtr;
            }
            else {
                currptr = currptr->nextptr;
            }
        }
        else if (choice == 7) {
            break;
        }
    }
}