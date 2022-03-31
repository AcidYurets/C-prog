#include "../inc/main.h"
#include "../inc/matrix_operations.h"

void copy_matrix(int **dst, int **src, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

void init_unit_matrix(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                a[i][j] = 1;
        }
    }
}

void init_zero_matrix(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
}

void multiply(int **ans, int **a, int **b, int n)
{
    init_zero_matrix(ans, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
