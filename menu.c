//
// Created by dusad on 16/04/2022.
//
#include <stdio.h>
#include "functions.h"
#include "menu.h"

void menu(int choice)
{
        switch(choice) {
            case 1:
                postTweet();
                break;
            case 2:
                getNewsFeed();
                break;
            case 3:
                follow();
                break;
            case 4:
                unfollow();
                break;
            case 5:
                delete();
                break;
            case 6:
                endTurn();
                break;
            case 7:
                endTwitter();
                break;
            default:
                puts("Invalid choice.");
                break;
        }
    printf("end of run.");

}

