#ifndef auth_h
#define auth_h

//student Registration
void RegisterUser(const char *filename, const char *role);

//Student login
int LogInUser(const char *filename, char *usernameout, const char *role);

// Logout
//void logoutUser(void);

//Student Registration
void StudentRegistration();
//Teacher Registration
void TeacherRegistration();

int StudentLogin(char *usernameout);
int TeacherLogin(char *usernameout);

#endif