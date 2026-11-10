#include<stdio.h>
#include<string.h>
#include "../../b_include/auth.h"

int LogInUser(char *filename,char *usernameout)
{
    FILE *login;

    char userName[20];
    char password[100];

    char saveduserName[20]; 
    char savedpassword[100];
    char fullName[50];
    char email[100];
    
    char line[300];
    char filePath[100];
   
    sprintf(filePath,"../c_data/%s", filename);


    
    login=fopen(filePath,"r");

    if (login == NULL)
    {
        printf("\nNo registered users found!\n");
        return 0;
    }

    printf("\n===== LOGIN =====\n");
    getchar();
    printf("Enter UserName: ");
    if (fgets(userName, sizeof(userName), stdin) == NULL)
    {
        fclose(login);
        return 0;
    }
    userName[strcspn(userName, "\r\n")] = '\0';

    
        printf("Enter Password: ");
        if (fgets(password, sizeof(password), stdin) == NULL)
        {
         fclose(login);
         return 0;
        }
        password[strcspn(password, "\r\n")] = '\0';

        

        while (fgets(line, sizeof(line), login) != NULL)
    {
        if (sscanf(line, "%49[^|]|%99[^|]|%19[^|]|%99[^\r\n]",
                   fullName, email, saveduserName, savedpassword) == 4)
        {
            if (strcmp(userName, saveduserName) == 0 &&
                strcmp(password, savedpassword) == 0)
            {
                strcpy(usernameout, saveduserName);

                fclose(login);

                printf("\nLOGIN SUCCESSFUL!\n");
                printf("Welcome, %s!\n", fullName);

                return 1;
            }
        }
    }

    fclose(login);

    printf("\nLOGIN FAILED!\n");
    printf("Invalid Username or Password!\n");
    return 0;
}
//Student Registration                      
int StudentLogin(char *usernameout){ 
     char username[20];                
    LogInUser("../../c_data/student.txt", username); 
    return 1;
}                                           
                                            
                                            
//Teacher Registration                      
int TeacherLogin(char *usernameout){ 
     char username[20];                
    LogInUser("../../c_data/tearcher.txt",username);
    return 1;
}                                           
                                            
                                            