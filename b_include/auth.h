#ifndef auth_h
#define auth_h

//student Registration
void RegisterUser();

//Student login
int LogInUser(char *usernameout,char *role);

//Password
int ValidPassword(const char* password);

// Logout
void logoutUser(void);

//Student Registration
void StudentRegistration();
//Teacher Registration
void TeacherRegistration();

int StudentLogin(char *usernameout);
int TeacherLogin(char *usernameout);

#endif