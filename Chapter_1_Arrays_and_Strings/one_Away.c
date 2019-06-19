#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int bool;
#define true 1
#define false 0

bool oneEditAway(char*, char*);
bool oneReplacementAway(char*, char*);
bool oneInsertionAway(char*, char*);
bool oneRemovalAway(char*, char*);

int main()
{
    char* str1 = malloc(128);
    char* str2 = malloc(128);
    printf("Enter first test string: \n");
    fgets (str1, 128, stdin);
    printf("Enter second test string: \n");
    fgets (str2, 128, stdin);
    printf("Check algorithm: %d\n", oneEditAway(str1, str2));
    free(str1);
    free(str2);
    return 0;
}

bool oneEditAway(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == len2)
    {
        return oneReplacementAway(str1, str2);
    }

    else if (len1 == (len2 - 1))
    {
        return oneInsertionAway(str1, str2);
    }

    else if (len1 = (len2 + 1))
    {
        return oneInsertionAway(str2, str1);
    }

    return false;
}

bool oneReplacementAway(char* str1, char* str2)
{
    int     len         = strlen(str1);
    bool    is_Replaced = false;

    for (int i = 0; i < len; i++)
    {
        if (str1[i] != str2[i])
        {
            if (is_Replaced != true)
            {
                is_Replaced = true;
            }

            else
            {
                return false;
            }  
        }
    }

    return true;
}

bool oneInsertionAway(char* str1, char* str2)
{
    int     len1        = strlen(str1);
    int     j           = 0;

    for (int i = 0; i < len1; i++)
    {
        if (str1[i] != str2[i + j])
        {
            if (j != 1)
            {
                j++;
                i--;
            }

            else
            {
                return false;
            }
        }
    }

    return true;
}