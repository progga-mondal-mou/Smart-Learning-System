
#include <stdio.h>
#include <string.h>

int validatePassword(const char *password)
{
    int upper = 0, lower = 0, digit = 0;

    if (strlen(password) < 8)
    {
        return 0;
    }

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            upper = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            lower = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            digit = 1;
        }
    }

    if (upper == 1 && lower == 1 && digit == 1)
    {
        return 1;
    }

    return 0;
}
