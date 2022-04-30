
#include "twitter_create.h"
#include "functions.h"
#include "menu.h"
#include <stdio.h>

int menu(twitter *ts, user *sptr){
    int choice = -1;
    instructions();
    //calling functions according to user choice
    while(choice != 0){
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                postTweet(ts,sptr);
                return 1;
            case 2:
                getNewsFeed(ts, sptr);
                return 2;
            case 3:
                follow(ts, sptr);
                return 3;
            case 4:
                unfollow(ts, sptr);
                return 4;
            case 5:
                delete(ts, sptr);
                return 6;
            case 6:
                return 6;
            case 7:
                return 7;
            default:
                printf("Error! Not an option!\n");
                continue;
        }
    }
    printf("Program will Self-Destruct now! Bye User:%s\n", sptr->username);
    return 7;
}

void instructions(void)
{
    printf("Option         Function\n");
    printf(" 1        |    postTweet\n");
    printf(" 2        |    getNewsFeed\n");
    printf(" 3        |    follow\n");
    printf(" 4        |    unfollow\n");
    printf(" 5        |    delete\n");
    printf(" 6        |    endTurn\n");
    printf(" 7        |    endTwitter\n");

}