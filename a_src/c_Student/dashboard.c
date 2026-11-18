#include<stdio.h>
//#include<stdio.h>
#include<stdlib.h>

#include"../../b_include/student.h"


void studentDashboard(const char * userName)
{
    system("cls");
    while(1){
        printf("=======STUDENT DASHBOARD=======\n");
        printf("\n1.Study\n");
        printf("2.Justify Yourself\n");
        printf("3.View Progess\n");
        printf("4.Log out\n");
        
        int choice;
        printf("\nPlease enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
             case 1:
             printf("\n study ");

             break;

             case 2: 
             printf("\n exam ");
             
             break;  

             case 3: 
             printf("\n progress ");
             break;  

             case 4: 
             printf("\n Logged out successfully ");
             return;
             
             default:
             printf("\n Invalid Choice!!!\nPlease try again\n");

        }
        printf("\nPress Enter to continue...");
    }
}