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


void swap_row(int a[][M], int m, int ind1, int ind2)
{
    for (int i = 0; i < m; i++)
    { 
        int temp = a[ind1][i];
        a[ind1][i] = a[ind2][i];
        a[ind2][i] = temp;
    }
}

void find_max(int a[][M], int max_el[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int max = a[i][0];
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        max_el[i] = max;
    }
}

void sort_matrix(int a[][M], int arr[], int n, int m)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] < arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swap_row(a, m, j, j + 1);
            }
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
    int a[N][M], max_el[N];
    int n = 0, m = 0;

    if (input_matrix(a, &n, &m))
    {
        return ERR;
    }

    find_max(a, max_el, n, m);

    sort_matrix(a, max_el, n, m);
   
    print_matrix(a, n, m);

    //print_arr(max_el, n);

    return 0;
}
