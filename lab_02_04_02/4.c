#include <stdio.h>
#include <math.h>

#define ERR -1
#define N 11

int input(int a[], int *n)
{
    int x = 0;
    for (int i = 0; i < N; i++)
    {
        x = scanf("%d", &a[i]);
        if (x == 1)
            (*n)++;

        if (*n == 10 && i == 10)
            return 0;
        if (*n == 11)
        {
            *n = 10;
            return 100;
        }
    }
    if (*n == 0)
        return ERR;
    return 0;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void selsort(int a[], int n)
{
    int ind = 0;
  
    for (int i = 0; i < n - 1; i++)
    {
        ind = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[ind])
                ind = j;
        swap(&a[ind], &a[i]);
    }
}


void output(const int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}


int main()
{
    int a[N];
    int n = 0;

    int in = input(a, &n);

    if (in == ERR)
        return ERR;

    selsort(a, n);

    output(a, n);
    
    return in;
}
