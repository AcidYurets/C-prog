#include "lab_04_01.h"

void get_arr(char a1[][WORD_LEN+1], char a2[][WORD_LEN+1], char ans[][WORD_LEN+1], int n, int m, int *k)
{
    *k = 0;
    for (int i = 0; i < n; i++)
    {
        int check = 0;
        for (int j = 0; j < n; j++)
        {
            if (strcmp(a1[i], a1[j]) == 0)
                check += 1;
        }
        for (int j = 0; j < m; j++)
        {
            if (strcmp(a1[i], a2[j]) == 0)
                check += 1;
        }
        if (check == 1)
        {
            strcpy(ans[*k], a1[i]);
            (*k)++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int check = 0;
        for (int j = 0; j < n; j++)
        {
            if (strcmp(a2[i], a1[j]) == 0)
                check += 1;
        }
        for (int j = 0; j < m; j++)
        {
            if (strcmp(a2[i], a2[j]) == 0)
                check += 1;
        }
        if (check == 1)
        {
            strcpy(ans[*k], a2[i]);
            (*k)++;
        }
    }
}