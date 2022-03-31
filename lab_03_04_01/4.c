#include <stdio.h>
#include <math.h>

#define ERR -1
#define N 10
#define M 10

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int input_matrix(int a[][N], int *n, int *m)
{
    if (scanf("%d%d", n, m) != 2)
    {
        return ERR;
    }

    if (*n < 1 || *n > 10)
    {
        return ERR;
    }
    if (*m < 1 || *m > 10)
    {
        return ERR;
    }
    if (*n != *m)
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

void swap_row(int a[][N], int n, int ind1, int ind2, int from, int to)
{
    for (int i = from; i <= to; i++)
    { 
        int temp = a[ind1][i];
        a[ind1][i] = a[ind2][i];
        a[ind2][i] = temp;
    }
}

void modif_matrix(int a[][N], int n)
{
    for (int i = 0; i < (n / 2); i++)
    {
        swap_row(a, n, i, n - i - 1, i, n - i - 1);
    }
}


void print_matrix(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d%s", a[i][j], (j + 1) % n ? " " : "\n");
}

int main()
{
    int a[N][M];
    int n = 0, m = 0;

    if (input_matrix(a, &n, &m))
    {
        return ERR;
    }

    modif_matrix(a, n);

    //swap_row(a, n, 0, 5, 1, 4);

    print_matrix(a, n);

    return 0;
}
