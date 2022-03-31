#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OK 0
#define ERR -1
#define READ_ERR -2
#define READ_MATRIX_ERR -3
#define READ_POWER_ERR -4
#define MEMORY_ERR -5

// Значения переменных k, s, n, m, p, q описано в задании
void deletion(int ***matrix_a, int ***matrix_a1, int ***matrix_b, int ***matrix_b1, int *k, int *s, int n, int m, int p, int q);
// Значения переменных z, k, s описано в задании
void addition(int ***matrix_a1, int ***matrix_a2, int ***matrix_b1, int ***matrix_b2, int *z, int k, int s);
// Значения переменных r1, r2, z описано в задании
void multiplication(int ***ans, int **matrix_a2, int **matrix_b2, int r1, int r2, int z);

#endif
