#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "twitter_create.h"
#include "functions.h"
#define MAX 100

int main()
{
    twitter twitter_system;
    create_twitter_system(&twitter_system);
    scanf("%d", &twitter_system.num_users);
    fflush(stdin);
    for(int i =0; i < twitter_system.num_users; i++)
    {
        user usr = twitter_system.users[i];
        fgets(usr.username, USR_LENGHT, stdin);
        char* p;
        if((p= strchr(usr.username,'\n'))!=NULL)
        {
            *p= '\0';
        }
        printf("User: %s, Followers: %d , Following: %d\n",usr.username, usr.num_followers, usr.num_followers );
    }
    int userCh;
    printf("enter ur choice\n");
    scanf("%d", &userCh);
    while(userCh!=8)
    {
        menu(userCh);
        printf("\nenter ur choice\n");
        scanf("%d", &userCh);
    }
//    printf("who do u want to follow?\n");
//    char following[MAX];
//    fgets(following, MAX, stdin);
//    follow(usr.username, following);
//    printf("%d %d", usr.num_following, usr.following);
    return 0;
}


