#include "lab_04.h"

void split(char arr[][WORD_LEN + 1], int *n, char *str)
{
    char *word = strtok(str, " ,.;:-!?");
    while (word != NULL)
    {
        strcpy(arr[*n], word);
        (*n)++;
        word = strtok(NULL, " ,.;:-!?");
    }
}

void change(char *word, char *new)
{
    char c = word[0];
    int j = 1;
    new[0] = word[0];
    for (int i = 1; word[i] != '\0'; i++)
    {
        if (word[i] != c)
        {
            new[j] = word[i];
            j++;
        }
    }
    new[j] = '\0';
}

void fill_arr(char arr[][WORD_LEN + 1], char ans[][WORD_LEN + 1], int n, int *m)
{
    *m = 0;
    char *last_word = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (strcmp(arr[i], last_word) != 0)
        {
            char new[WORD_LEN + 1];
            change(arr[i], new);
            strcpy(ans[*m], new);
            (*m)++;
        }
    }
}