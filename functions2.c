//
// Created by dusad on 16/04/2022.
//
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "twitter_create.h"
#define MAX 100




void postTweet()
{
    printf("postTweet function is invoked\n");
}
void getNewsFeed()
{
    printf("getNewsFeed function is invoked\n");
}

void follow(char usrname[MAX], int userno)
{
    //char * a = usrname;
    char following[USR_LENGHT];
    printf("Enter the username of the user you want to follow: ");
    fflush(stdin);
    fgets(following, USR_LENGHT, stdin);
    if(following[strlen(following) - 1] == '\n')
        following[strlen(following) - 1 ] = '\0';
    printf("%s", following);
    twitter twitter_system;
    user users [userno];
    //user * ptr = (user *) usrname;
    //user * c = &usrname;
    int i = 0;
    while (i < userno) {
        printf("%d", i);

        if(strcmp(usrname, users[i].username) == 0){
            printf("test");

            //user * a = &users[i];


            for (int j = 0; j < userno; j++){

                if(strcmp(following, users[j].username) == 0){
                    //user * ptr2 = (user *) following;
                    //user * b = &users[j];
                    strcpy(&users[i].following[users[i].num_following], users[j].username);
                    users[i].num_following++;
                    strcpy(&users[j].followers[users[i].num_followers], users[i].username);
                    users[j].num_followers++;
                    //strcpy(&ptr->following[ptr->num_following], ptr2->username);
                    //ptr->num_following++;
                    //strcpy(a->following[a->num_following], b->username);
                    //b->num_following++;
                    //strcpy(&ptr2->following[ptr2->num_following], ptr->username);
                    //ptr2->num_followers++;


                }
            }
        }
        i++;
    }


    /*user *userPtr= (user *) users;
    user *user2Ptr= (user *) userToFollow;
    strcpy(&userPtr->following[userPtr->num_following], user2Ptr->username);
    userPtr->num_following++;
    strcpy(&user2Ptr->followers[user2Ptr->num_followers], userPtr->username);
    user2Ptr->num_followers++;
//    printf("follow function is invoked\n");*/
}
void unfollow()
{
    printf("unfollow function is invoked\n");
}
void delete()
{
    printf("delete function is invoked\n");
}
void endTurn()
{
    printf("endTurn function is invoked\n");
}
void endTwitter()
{
    printf("endTwitter function is invoked\n");
}
