#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERR -1

void fill_arr(int *b, int **a, int n, int m);
void fill_snake(int **a, int *b, int n);
int read_nm(FILE *f, int *n, int *m);
int read_matrix(FILE *f, int **a, int n, int m);
int print_matrix(int **a, int n, int m);
int **allocate_matrix(int n, int m);
