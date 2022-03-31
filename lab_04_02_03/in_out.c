#include "lab_04_01.h"

int read_line(char *s, int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n - 1)
            s[i++] = ch;
    s[i] = '\0';
    return i;
}

void output(char a[][WORD_LEN+1], int n)
{
    for (int i = 0; i < n - 1; i++)
        printf("%s ", a[i]);
    printf("%s", a[n - 1]);
}