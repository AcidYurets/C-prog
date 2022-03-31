#include <stdio.h>
#include <math.h>
#include <string.h>

#define ERR -1
#define STR_LEN 256
#define WORD_LEN 16

int read_line(char *s, int n);
void split(char arr[][WORD_LEN+1], int *n, char *str);
void get_arr(char a1[][WORD_LEN+1], char a2[][WORD_LEN+1], char ans[][WORD_LEN+1], int n, int m, int *k);
void output(char a[][WORD_LEN+1], int n);