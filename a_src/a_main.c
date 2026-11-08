#include<stdio.h>
#include<stdlib.h>

void StudentPortal()
{
  printf("Welcome to Student Portal\n");
}
void TeacherPortal()
{
  printf("Welcome to Teacher Portal\n");
}
void AdminPortal()
{
  printf("Welcome to Admin Portal\n");
}
void AboutSystem()
{
  printf("Welcome to System\n");
}

int main()
{
    
  while(1){
        
    printf("==================================\n");
    printf("       SMART LEARNING SYSTEM      \n");
    printf("==================================\n");
    
    printf("\n1.Student Portal\n");
    printf("2.Teacher Portal\n");
    printf("3.Admin Portal\n");
    printf("4.About System\n");
    printf("5.Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);

    
    switch(choice){
        case 1:
          StudentPortal();
          break;

        case 2:
          TeacherPortal();
          break;

        case 3:
          AdminPortal();
          break;

        case 4:
          AboutSystem();
          break;

        case 5:
          printf("Thanks for using Smart Leaning System");
          exit(0);
        
        default:
        printf("Invalid Choice!!!");
        printf("please Try Again");
    }
  }
}