#include <stdio.h>
#include <stdlib.h>
#include "../b_include/auth.h"
#include "../b_include/student.h"

char userName[100];

void StudentPortal()
{
  system("cls");
  printf("\n\n=====Welcome to Student Portal=====\n");
  int choice;
  do
  {
    printf("\n1. Registration\n2. Login\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      system("cls");

      //printf("Registration portal\n");
      getchar();
      StudentRegistration();
      break;
    case 2:
      {
        system("cls");
    //printf("\nStudent Login\n");

    if (StudentLogin(userName))
    {
         InitialAssessment(userName);
         studentDashboard(userName); 
    }
    else
    {
        printf("\nLogin Failed!\n");
    }

    break;
      }
      
    case 3:
      printf("Thank you\n\n");
      break;
    
    default:
    printf("Invalid choice! Please try again.\n");
    }
  } while (choice != 3);
}

void TeacherPortal()
{ 
  system("cls");
  printf("\n\nWelcome to Teacher Portal\n");
  int choice;
  do
  {
    
    printf("\n1. Registration\n2. Login\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");

      //printf("\nRegistration portal\n");
      getchar();
      TeacherRegistration();
      break;
    case 2:
    {
        system("cls");

      //printf("\nTeacher Login");

       if (TeacherLogin(userName))
    {
        printf("\nTeacher Login Successful!\n");
    }
    break;
    }

    case 3:
      printf("Thank you\n\n");
      break;
    
    default:
    printf("Invalid choice! Please try again.\n");
    }
  } while (choice != 3);
  
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

  while (1)
  {
    system("cls");

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
    scanf("%d", &choice);

    switch (choice)
    {
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
      system("cls");
  }
}