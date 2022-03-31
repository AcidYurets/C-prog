
#include <stdio.h>
#include <math.h>
#include <string.h>

#define ERR -1
#define STR_LEN 256
#define WORD_LEN 16

int read_line(char *s, int n);
int is_digit(char a);
char *get_number_end(char *number_begin);
int check_num(char *str);
int check_input(char line[], char *num);
