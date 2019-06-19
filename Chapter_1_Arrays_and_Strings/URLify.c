#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

void URLify(char**);
void delete_spaces_on_sides(char**);

int main()
{
    char *str1 = malloc(128);
    printf("Enter test string: \n");
    fgets (str1, 128, stdin);
    URLify(&str1);
    printf("Check algorithm: %s\n", str1);
    free(str1);
    return 0;
}

void URLify(char** str)
{   
    delete_spaces_on_sides(str);

    int len             = strlen(*str);
    int space_counter   = 0;
    int new_len         = 0;
    int temp            = 0;

    for (int i = 0; i < len; i++)
    {
        if ((*str)[i] == ' ')
        {
            space_counter++;
        }
    }

    new_len         = len + 2 * space_counter;
    char*   new_str = malloc(new_len);
    int     j       = 0;

    for (int i = 0; i < len; i++)
    {
        if ((*str)[i] == ' ')
        {
            new_str[i + j]      = '%';
            new_str[i + j + 1]  = '2';
            new_str[i + j + 2]  = '0';
            j += 2;
        }

        else
        {
            new_str[i + j] = (*str)[i]; 
        }
    }

    *str = new_str;
}

void delete_spaces(char** str)
{
    int len               = strlen(*str);
    int new_len           = 0;
    int f_count_spaces    = 0;
    int b_count_spaces    = 0;   

    while((*str)[f_count_spaces] == ' ')
    {
        f_count_spaces++;
    } 

    while ((*str)[len - 2 - b_count_spaces] == ' ')
    {
        b_count_spaces++;
    }

    if ((f_count_spaces != 0) || (b_count_spaces != 0))
    {
        new_len = len - f_count_spaces - b_count_spaces;

        char *new_str = malloc(new_len);

        for (int i = 0; i < new_len; i++)
        {
            if ((*str)[f_count_spaces + i + b_count_spaces] == '\n')
            {
                new_str[i] = (*str)[f_count_spaces + i + b_count_spaces];
            }

            else
            {
                new_str[i] = (*str)[f_count_spaces + i];
            }
        }

        *str = new_str;
    }
}