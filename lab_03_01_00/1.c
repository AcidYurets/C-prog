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
    if (*m < 1 || *m > 10)
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


void fill_arr(int a[][M], int arr[], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        int check = 1;
        for (int j = 1; j < n; j++)
        {
            if (a[j][i] >= a[j - 1][i])
            {
                check = 0;
            }
        }
        arr[i] = check;
    }
    if (n == 1)
    {
        for (int i = 0; i < m; i++)
        {
            arr[i] = 0;
        }
    }
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
    int a[N][M], arr[M];
    int n = 0, m = 0;


    if (input_matrix(a, &n, &m))
    {
        return ERR;
    }

    fill_arr(a, arr, n, m);

    print_arr(arr, m);

    //print_matrix(a, n, m);

    return 0;
}
