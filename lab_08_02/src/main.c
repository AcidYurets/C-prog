#include "../inc/main.h"
#include "../inc/allocate.h"
#include "../inc/in-out_processing.h"
#include "../inc/add-del_operations.h"
#include "../inc/matrix_operations.h"

int main()
{
    int res = OK;
    int n = 0, m = 0, p = 0, q = 0;
    int **a = NULL, **b = NULL, **a1 = NULL, **b1 = NULL, **a2 = NULL, **b2 = NULL, **ans = NULL;

    // Ввод
    if (read_matrix(&a, &n, &m))
    {
        res = READ_MATRIX_ERR;
    }
    else if (read_matrix(&b, &p, &q))
    {
        free_matrix(a);
        res = READ_MATRIX_ERR;
    }

    if (res == OK)
    {
        // Удаление
        int k = 0, s = 0;
        deletion(&a, &a1, &b, &b1, &k, &s, n, m, p, q);

        // Добавление
        int z = 0;
        addition(&a1, &a2, &b1, &b2, &z, k, s);

        // Умножение и вывод
        int r1 = 0, r2 = 0;
        if (scanf("%d", &r1) != 1 || r1 < 0)
            res = READ_POWER_ERR;
        else if (scanf("%d", &r2) != 1 || r2 < 0)
            res = READ_POWER_ERR;
        else
        {
            multiplication(&ans, a2, b2, r1, r2, z);
            print_matrix(ans, z, z);
            free_matrix(ans);
        }
    }

    // Освобождение
    if (res != READ_MATRIX_ERR)
    {
        free_matrix(a2);
        free_matrix(b2);
    }

    return res;
}

// Значения переменных k, s, n, m, p, q описано в задании
void deletion(int ***matrix_a, int ***matrix_a1, int ***matrix_b, int ***matrix_b1, int *k, int *s, int n, int m, int p, int q)
{
    if (n > m)
    {
        *k = m;
        for (int i = 0; i < n - m; i++)
            delete_row(*matrix_a, n - i, m);
    }
    else
    {
        *k = n;
        for (int i = 0; i < m - n; i++)
            delete_col(*matrix_a, n, m - i);
    }
    *matrix_a1 = allocate_matrix(*k, *k);
    copy_matrix(*matrix_a1, *matrix_a, *k, *k);
    free_matrix(*matrix_a);

    if (p > q)
    {
        *s = q;
        for (int i = 0; i < p - q; i++)
            delete_row(*matrix_b, p - i, q);
    }
    else
    {
        *s = p;
        for (int i = 0; i < q - p; i++)
            delete_col(*matrix_b, p, q - i);
    }
    *matrix_b1 = allocate_matrix(*s, *s);
    copy_matrix(*matrix_b1, *matrix_b, *s, *s);
    free_matrix(*matrix_b);
}

// Значения переменных z, k, s описано в задании
void addition(int ***matrix_a1, int ***matrix_a2, int ***matrix_b1, int ***matrix_b2, int *z, int k, int s)
{
    if (k > s)
    {
        *z = k;
        *matrix_b2 = allocate_matrix(*z, *z);
        copy_matrix(*matrix_b2, *matrix_b1, s, s);
        free_matrix(*matrix_b1);
        int j = k - s;
        for (int i = 0; i < j; i++)
        {
            add_row(*matrix_b2, s + i, s);
        }
        for (int i = 0; i < j; i++)
        {
            add_col(*matrix_b2, s + j, s + i);
        }
        *matrix_a2 = *matrix_a1;
    }
    else
    {
        *z = s;
        *matrix_a2 = allocate_matrix(*z, *z);
        copy_matrix(*matrix_a2, *matrix_a1, k, k);
        free_matrix(*matrix_a1);
        
        int j = s - k;
        for (int i = 0; i < j; i++)
        {
            add_row(*matrix_a2, k + i, k);
        }
        for (int i = 0; i < j; i++)
        {
            add_col(*matrix_a2, k + j, k + i);
        }
        *matrix_b2 = *matrix_b1;
    }
}

// Значения переменных r1, r2, z описано в задании
void multiplication(int ***ans, int **matrix_a2, int **matrix_b2, int r1, int r2, int z)
{
    *ans = allocate_matrix(z, z);
    init_unit_matrix(*ans, z);

    int **x = allocate_matrix(z, z);
    for (int i = 0; i < r1; i++)
    {
        copy_matrix(x, *ans, z, z);
        multiply(*ans, x, matrix_a2, z);
    }
    for (int i = 0; i < r2; i++)
    {
        copy_matrix(x, *ans, z, z);
        multiply(*ans, x, matrix_b2, z);
    }
    free_matrix(x);
}
