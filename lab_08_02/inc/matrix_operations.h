#ifndef OPERATIONS_H
#define OPERATIONS_H

void copy_matrix(int **dst, int **src, int n, int m);
void init_unit_matrix(int **a, int n);
void multiply(int **ans, int **a, int **b, int n);

#endif