#include "../inc/main.h"
#include "../inc/add-del_operations.h"

void find_max_el(int **a, int n, int m, int *ai, int *aj)
{
    int max = **a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] >= max)
            {
                max = a[i][j];
                *ai = i;
                *aj = j;
            }
        }
    }
}

void delete_row(int **a, int n, int m)
{
    int to_del = 0, aj = 0;
    find_max_el(a, n, m, &to_del, &aj);
    
    for (int i = to_del + 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i - 1][j] = a[i][j];
        }
    }
}

void delete_col(int **a, int n, int m)
{
    int to_del = 0, ai = 0;
    find_max_el(a, n, m, &ai, &to_del);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = to_del + 1; j < m; j++)
        {
            a[i][j - 1] = a[i][j];
        }
    }
}

void add_row(int **a, int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i][j];
        }
        a[n][j] = floor((float) sum / n);
    }
}

void add_col(int **a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int min = a[i][0];
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] < min)
                min = a[i][j];
        }
        a[i][m] = min;
    }
}