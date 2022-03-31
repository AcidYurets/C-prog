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


int check_prime(int x)
{
    if (x > 1)
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

void fill_arr(int a[][M], int n, int m, int *s, int arr[], int *pointers[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check_prime(a[i][j]))
            {
                arr[*s] = a[i][j];
                pointers[*s] = &a[i][j];
                (*s)++;
            }
        }
    } 
}

void fill_matrix(int s, int arr[], int *pointers[])
{
    for (int i = 0; i < s; i++)
    {
        *pointers[i] = arr[i];
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
    int a[N][M], arr[N * M], rev[N * M];
    int *pointers[N * M];
    int n = 0, m = 0, s = 0;

    if (input_matrix(a, &n, &m))
    {
        return ERR;
    }
    
    fill_arr(a, n, m, &s, arr, pointers);

    if (s == 0)
    {
        return ERR;
    }

    for (int i = s - 1; i >= 0; i--)
    {
        rev[s - i - 1] = arr[i];
    }

    fill_matrix(s, rev, pointers);

    print_matrix(a, n, m);

    return 0;
}
