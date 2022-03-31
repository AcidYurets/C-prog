#include <stdio.h>
#include <math.h>

#define ERR -1
#define N 10
#define M 10

int input_num(int *n, int *m)
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
    if (*m != *n)
    {
        return ERR;
    }
    return 0;
}


void change(int a[][M], int n)
{
    int k = 1, j = 0, s = 1;
    while (j < n * n) 
    {
        for (int i = s - 1; i < n - (s - 1); ++i)
        {
            a[i][s - 1] = k++;
            j++;
        }
        for (int i = s; i < n - (s - 1); ++i) 
        {
            a[n - s][i] = k++;
            j++;
        }
        for (int i = n - (s + 1); i >= s - 1; i--) 
        {
            a[i][n - s] = k++;
            j++;
        }
        for (int i = n - (s + 1); i >= s; i--) 
        {
            a[s - 1][i] = k++;
            j++;
        }
        s++;
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
    int a[N][M];
    int n = 0, m = 0;

    if (input_num(&n, &m))
    {
        return ERR;
    }
    
    change(a, n);

    print_matrix(a, n, m);

    return 0;
}
