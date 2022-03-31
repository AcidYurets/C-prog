#include "../inc/main.h"
#include "../inc/allocate.h"
#include "../inc/in-out_processing.h"

int read_matrix(int ***a, int *n, int *m)
{
    int res = OK;

    *n = 0, *m = 0;
    if (scanf("%d", n) != 1 || *n <= 0)
        res = READ_ERR;
    else if (scanf("%d", m) != 1 || *m <= 0)
        res = READ_ERR;
    else
    {
        *a = allocate_matrix(*n, *m);
        if (*a == NULL)
        {
            res = MEMORY_ERR;
        }
        else
        {
            for (int i = 0; i < *n && res == OK; i++)
            {
                for (int j = 0 ; j < *m && res == OK; j++)
                {
                    int el = 0;
                    if (scanf("%d", &el) != 1)
                    {
                        free_matrix(*a);
                        res = READ_ERR;
                    }
                    else
                        (*a)[i][j] = el;
                }
            }
        }
    }

    return res;
}

void print_matrix(int **a, int n, int m)
{
    // printf("%d, %d: \n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < m - 1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][m - 1]);
    }
}
