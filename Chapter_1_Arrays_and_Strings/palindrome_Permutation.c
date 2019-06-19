#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int bool;
#define true 1
#define false 0

void delete_all_spaces_in_string(char**);
bool palindrome_Permutation(char**);

int main()
{
    char* str = malloc(128);
    printf("Enter first test string: \n");
    fgets (str, 128, stdin);
    printf("Check algorithm: %d\n", palindrome_Permutation(&str));
    free(str);
    return 0;
}

void delete_all_spaces_in_string(char** str)
{
    int     len             = strlen(*str);
    int     space_counter   = 0;
    int     new_len         = 0;
    char*   new_str         = NULL;         

    for (int i = 0; i < len; i++)
    {
        if ((*str)[i] == ' ')
        {
            space_counter++;
        }
    }

    new_len         = len - space_counter;
    new_str         = malloc(new_len);
    space_counter   = 0;

    for (int i = 0; i < new_len; i++)
    {
        if ((*str)[i + space_counter] != ' ')
        {
            new_str[i] = (*str)[i + space_counter]; 
        }

        else 
        {
            space_counter++;
            i--;
        }
    }

    *str = new_str;
}

bool palindrome_Permutation(char** str)
{
    delete_all_spaces_in_string(str);

    int     len_wo_null         = strlen(*str) - 1;
    int     check_array[128]    = {0, };
    bool    is_Center           = false;

    for (int i = 0; i < len_wo_null; i++)
    {
        (*str)[i] = tolower((*str)[i]);
        check_array[(*str)[i]]++;
    }

    for (int i = 0; i < len_wo_null; i++)
    {
        if (check_array[(*str)[i]] % 2 == 1)
        {
            if (is_Center == false)
            {
                is_Center = true;
            }

            else
            {
                return false;
            }
            
        }
    }
    
    return true;
}