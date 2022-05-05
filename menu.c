#include "twitter_create.h"
#include "functions.h"
#include "menu.h"
#include <stdio.h>

int menu(twitter *twitterApp, user *sptr){

    int choice = -1;
    instructions();

    //menu for twitter system
    while(choice != 0){

        printf("Enter your choice:\n");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice){

            case 1:
                postTweet(twitterApp, sptr);
                return 1;

            case 2:
                getNewsFeed(twitterApp, sptr);
                return 2;

            case 3:
                follow(twitterApp, sptr);
                return 3;

            case 4:
                unfollow(twitterApp, sptr);
                return 4;

            case 5:
                delete(twitterApp, sptr);
                return 6;

            case 6:
                return 6;

            case 7:
                return 7;

            default:
                printf("Please select another option!\n");
                continue;

        }

    }

    return 7;

}

void instructions(void){

    printf("Option         Function\n");
    printf(" 1        |    postTweet\n");
    printf(" 2        |    getNewsFeed\n");
    printf(" 3        |    follow\n");
    printf(" 4        |    unfollow\n");
    printf(" 5        |    delete\n");
    printf(" 6        |    endTurn\n");
    printf(" 7        |    endTwitter\n");

}