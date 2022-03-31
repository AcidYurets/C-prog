#include <stdio.h>
#include <math.h>

#define ERR -1
#define N 10
#define M 10

int input_matrix(int a[][M], int *n, int *m)
{
    if (scanf("%d%d", n, m) != 2)
    {
        return ERR;
    }

    if (*n < 1 || *n > 10)
    {
        return ERR;
    }
    if (*m < 2 || *m > 10)
    {
        return ERR;
    }
    
    int x = 0;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            x += scanf("%d", &a[i][j]);
    if (x != (*n) * (*m))
        return ERR;
    return 0;
}


void del_col(int a[][M], int n, int m, int ind)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (j >= ind)
            {
                a[i][j] = a[i][j + 1];
            }
        }
    }
}

int is_digit_in_num(int n, int d)
{
    //printf("%d %d ", n, d);
    n = (n < 0) ? -1 * n : n;
    if (n == d)
    {
        return 1;
    }
    int check = 0;
    while (n > 0)
    {
        int x = n % 10;
        if (x == d)
            check = 1;
        n /= 10;
    }
    //printf("%d\n", check);
    return check;
}

int search_col(int a[][M], int *n, int *m, int digit)
{
    for (int i = 0; i < *m; i++)
    {
        int check = 0;
        for (int j = 0; j < *n; j++)
        {
            if (is_digit_in_num(a[j][i], digit))
            {
                check = 1;
            }
        }
        if (check)
        {
            del_col(a, *n, *m, i);
            (*m) -= 1;
            i--;
        }
    }
    if (*m == 0)
    {
        return ERR;
    }
    return 0;
}

void print_arr(const int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}


void print_matrix(int a[][M], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d%s", a[i][j], (j + 1) % m ? " " : "\n");
}

int main()
{
    int a[N][M];
    int n = 0, m = 0, digit = 0;

    if (input_matrix(a, &n, &m))
    {
        return ERR;
    }

    if (scanf("%d", &digit) != 1)
    {
        return ERR;
    }

    if (digit < 0 || digit > 9)
    {
        return ERR;
    }

    if (search_col(a, &n, &m, digit))
    {
        return ERR;
    }

    print_matrix(a, n, m);

    return 0;
}
