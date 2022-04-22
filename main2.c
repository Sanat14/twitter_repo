#include <stdio.h>
#include <string.h>
#include "twitter_create.h"
#include "menu.h"
#include "functions.h"


/*int main() {

    twitter twitter_system;
    user users [twitter_system.num_users];
    create_twitter_system(&twitter_system);
    printf("Enter the number of users you want to enter: ");
    scanf("%d", &twitter_system.num_users);
    fflush(stdin);

    //fgets(twitter_system.num_users, MAX_USERS, stdin);
    for(int i = 0; i < twitter_system.num_users; i++){
        printf("Enter the username or press ENTER to terminate \n");
        user usr = twitter_system.users[i];
        fgets(users[i].username, USR_LENGHT, stdin);
        if (users[i].username[strlen(users[i].username) - 1] == '\n')
            users[i].username[strlen(users[i].username) - 1] = '\0';
        //scanf("%s", usr.username);
        users[i].num_followers = 0;
        users[i].num_following = 0;
        printf("User: %s; Followers: %d; Following: %d\n",usr.username, usr.num_followers, usr.num_followers );
    }

    // Trying following again
    for (int i = 0; i < twitter_system.num_users; i++){
        user * a = &users[i];
        for (int j = 0; j < twitter_system.num_users; j++){
            if (j == i){
                continue;
            }
            if (j != i){
                int input = 0;
                user * b = &users[j];
                printf("Current user: %s\n", users[i].username);
                //scanf("%d", input);
                printf("Do you want to follow \"%s\"? (1 for yes/0 for no)\n", users[j].username);
                //user users [twitter_system.num_users];
                //user * d = &usr2.username;
                //user * c = &usr.username;
                //user * a = &users[i];
                //user * b = &users[i+1];
                strcpy(&a->following[a->num_following], b->username);
                a->num_following++;

                strcpy(&b->followers[b->num_followers], a->username);
                b->num_followers++;

            }
            printf("User: %s; Followers: %d; Following: %d\n",users[i].username, users[i].num_followers, users[i].num_followers );
        }



    }




}*/


int main() {

    twitter twitter_system;

    create_twitter_system(&twitter_system);
    printf("Enter the number of users you want to enter: ");
    scanf("%d", &twitter_system.num_users);
    fflush(stdin);
    user users [twitter_system.num_users];

    //fgets(twitter_system.num_users, MAX_USERS, stdin);
    for(int i = 0; i < twitter_system.num_users; i++){
        printf("Enter the username or press ENTER to terminate \n");
        //user usr = twitter_system.users[i];
        fgets(users[i].username, USR_LENGHT, stdin);
        if (users[i].username[strlen(users[i].username) - 1] == '\n')
            users[i].username[strlen(users[i].username) - 1] = '\0';
        //scanf("%s", usr.username);
        users[i].num_followers = 0;
        users[i].num_following = 0;
        printf("User: %s; Followers: %d; Following: %d\n",users[i].username, users[i].num_followers, users[i].num_followers );
    }

    // Trying following again
    /*for (int i = 0; i < twitter_system.num_users; i++){
        user * a = &users[i];
        for (int j = 0; j < twitter_system.num_users; j++){
            if (j == i){
                continue;
            }
            if (j != i){
                int input = 0;
                user * b = &users[j];
                printf("Current user: %s\n", users[i].username);
                //scanf("%d", input);
                printf("Do you want to follow \"%s\"? (1 for yes/0 for no)\n", users[j].username);
                //user users [twitter_system.num_users];
                //user * d = &usr2.username;
                //user * c = &usr.username;
                //user * a = &users[i];
                //user * b = &users[i+1];
                strcpy(&a->following[a->num_following], b->username);
                a->num_following++;

                strcpy(&b->followers[b->num_followers], a->username);
                b->num_followers++;

            }
            printf("User: %s; Followers: %d; Following: %d\n",users[i].username, users[i].num_followers, users[i].num_followers );
        }

    }*/
    for (int i = 0; i < twitter_system.num_users; i++){
        user * a = &users[i];
        char usrname[100];
        strcpy(usrname, a->username);
        printf("Current user: %s\n", users[i].username);
        follow(users[i].username, twitter_system.num_users);
        /*int userCh;
        printf("enter ur choice\n");
        scanf("%d", &userCh);
        while(userCh!=8)
        {
            menu(userCh);
            printf("\nenter ur choice\n");
            scanf("%d", &userCh);
        }
        printf("User: %s; Followers: %d; Following: %d\n",users[i].username, users[i].num_followers, users[i].num_followers );
//    printf("who do u want to follow?\n");
//    char following[MAX];
//    fgets(following, MAX, stdin);
//    follow(usr.username, following);
//    printf("%d %d", usr.num_following, usr.following);
         */

    }
    for(int i = 0; i < twitter_system.num_users; i++){
        printf("User: %s; Followers: %d; Following: %d\n",users[i].username, users[i].num_followers, users[i].num_followers );
    }


}

