#include<stdio.h>
#include <string.h>
#include "../../b_include/auth.h"


// Common Registration Function
void RegisterUser(const char *filename, const char *role)
{
    FILE *reg;

    char fullName[100];
    char email[100];
    char userName[20];
    char password[100];
    
    char filePath[100];
    sprintf(filePath, "../c_data/%s", filename);

    reg = fopen(filePath, "a");

    if (reg == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\n===== %s REGISTRATION =====\n", role);

    printf("Enter Full name: ");
    fgets(fullName, sizeof(fullName), stdin);
    fullName[strcspn(fullName, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    
    printf("Enter Username: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = '\0';

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    fprintf(reg, "%s|%s|%s|%s\n",
            fullName, email, userName, password);

    fclose(reg);

    printf("\n%s Registration Successful!\n", role);
}

//Student Registration
void StudentRegistration(){
    RegisterUser("student.txt", "Student");
}

//Teacher Registration
void TeacherRegistration(){
    RegisterUser("teacher.txt", "Teacher");
}
