#include "stdio.h"
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool checkPermutation(char* , char*);

int main()
{
    char str1[128];
    char str2[128];
    printf("Enter first test string: \n");
    fgets (str1, 128, stdin);
    printf("Enter second test string: \n");
    fgets (str2, 128, stdin);
    printf("Check algorithm: %d\n", checkPermutation(str1, str2));
    return 0;
}

bool checkPermutation(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
    {
        return false;
    }

    else
    {
        int chars_for_check[128] = {};
        
        for (int i = 0; i < len1; i++)
        {
            chars_for_check[str1[i]]++;
        }

        for (int i = 0; i < len2; i++)
        {
            chars_for_check[str2[i]]--;

            if(chars_for_check[str2[i]] < 0)
            {
                return false;
            }
        }

        return true;
    }
    
}