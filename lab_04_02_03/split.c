#include "lab_04_01.h"

void split(char arr[][WORD_LEN+1], int *n, char *str)
{
    char word[STR_LEN + 1];
    int j = 0;
    *n = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == ',' || str[i] == ';' || str[i] == ':' || str[i] == '-' || str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            word[j] = '\0';
            if (strlen(word) > 0)
            {
                strcpy(arr[*n], word);
                (*n)++;
            }
            j = 0;
            continue;
        }
        word[j] = str[i];
        j++;
    }
    word[j] = '\0';
    if (strlen(word) > 0)
    {
        strcpy(arr[*n], word);
        (*n)++;
    }
}