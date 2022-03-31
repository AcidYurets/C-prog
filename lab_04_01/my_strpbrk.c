#include "lab_04_01.h"

char *my_strpbrk(char *str1, char *str2)
{
    char *p = NULL;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (p != NULL)
            break;
        for (int j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                p = (str1 + i);
                break;
            }
        }
    }
    return p;
}