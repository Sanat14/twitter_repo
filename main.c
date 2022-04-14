#include <stdio.h>
#include <string.h>
#include "twitter_create.h"


int main() {

    twitter twitter_system;
    create_twitter_system(&twitter_system);
    printf("Enter the number of users you want to enter: ");
    scanf("%d", &twitter_system.num_users);
    fflush(stdin);

    //fgets(twitter_system.num_users, MAX_USERS, stdin);
    for(int i = 0; i < twitter_system.num_users; i++){
        printf("Enter the username or press ENTER to terminate \n");
        user usr = twitter_system.users[i];
        fgets(usr.username, USR_LENGHT, stdin);
        if (usr.username[strlen(usr.username) - 1] == '\n')
            usr.username[strlen(usr.username) - 1] = '\0';
        //scanf("%s", usr.username);
        usr.num_followers = 0;
        usr.num_following = 0;
        printf("User: %s; Followers: %d; Following: %d\n",usr.username, usr.num_followers, usr.num_followers );
    }
    // Creating follower and following system without Sanat
    printf("Do you want to set followers of a user? (y/n)");
    char input;
    fgets(&input, 10, stdin);
    if (input == 'n')
        printf("Thank you");
    while (input == 'y'){
        char input2, input3;
        printf("Enter the username from which you want to follow: ");
        fgets(&input2, 100, stdin);
        //char * pinput2 = &input2;
        for (int i = 0; i < twitter_system.num_users; i++){
            user usr = twitter_system.users[i];
            if (strcmp(&input2, usr.username) == 0){
                char * pinput2 = usr.username;
                printf("Which user do you want to follow: ");
                fgets(&input3, 100, stdin);
                for (int j = 0; j < twitter_system.num_users; j++){
                    user usr2 = twitter_system.users[i];
                    if (strcmp(&input3, usr2.username) == 0){

                    }
                }
            }
        }
    }




}
