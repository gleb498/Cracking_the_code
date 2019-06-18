#include "stdio.h"
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool isUnique(char* );

int main()
{
    char str[128];
    printf("Enter test string: \n");
    scanf("%s", str);
    printf("Check algorithm: %d\n", isUnique(str));
    return 0;
}

bool isUnique(char* str)
{
    int str_len = strlen(str); 

    if (str_len > 128)
    {
        return false;
    } 
    
    else 
    {
        bool check_array[128] = {false, }; 

        for (int i = 0; i < str_len; i++)
        {
            if (check_array[str[i]] == true)
            {
                return false;
            }

            else
            {
                check_array[str[i]] = true;
            }  
        }

        return true;
    }
}