#include <stdio.h>
#include <math.h>
#include <string.h>

#define ERR -1
#define STR_LEN 256
#define WORD_LEN 16

int read_line(char *s, int n);
void split(char arr[][WORD_LEN+1], int *n, char *str);
void change(char *word, char *new);
void fill_arr(char arr[][WORD_LEN + 1], char ans[][WORD_LEN + 1], int n, int *m);
void output(char a[][WORD_LEN+1], int n);