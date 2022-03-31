#include "lab_04.h"

int read_line(char *s, int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n - 1)
            s[i++] = ch;
    s[i] = '\0';
    return i;
}

int check_input(char line[], char *n)
{
    char *num = strtok(line, " \t\n\v\f\r");
    char *x = strtok(NULL, " \t\n\v\f\r");

    if (x != NULL || num == NULL)
    {
        return ERR;
    }
    strcpy(n, num);
    
    return 0;
}