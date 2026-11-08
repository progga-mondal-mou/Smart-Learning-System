#ifndef auth.h
#define auth.h

//student Registration
int RegisterUser(void);

//Student login
int LogInUser(char *usernameout,char *role);

//Password
int ValidPassword(const char* password);

// Logout
void logoutUser(void);

#endif