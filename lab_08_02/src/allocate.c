#include "../inc/main.h"
#include "../inc/allocate.h"

void free_matrix(int **data)
{
    free(data[0]);
    free(data);
}

// Выделение памяти под обычную матрицу
int **allocate_matrix(int n, int m)
{
    int **p = NULL, *data;
    p = malloc(n * sizeof(int*));
    if (!p)
        p = NULL;
    else
    {
        data = calloc(n * m, sizeof(int));
        if (!data)
        {
            free(p);
            p = NULL;
        }
        else
            for (int i = 0; i < n; i++)
                p[i] = data + i * m;
    }
    
    return p;
}