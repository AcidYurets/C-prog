#include <stdio.h>
#include <math.h>

#define ERR -1
#define N 10

int input(int a[], int *n)
{
    scanf("%d", n);

    int x = 0;
    for (int i = 0; i < *n; i++)
        x += scanf("%d", &a[i]);
    if (x != *n)
        return ERR;
    return 0;
}


int check(int n)
{
    int last = n % 10;

    while (n / 10 != 0)
        n = n / 10;

    if (last == n)
        return 1;
    
    return 0;
}

int form(const int a[], int n, int b[], int *nn)
{
    *nn = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (check(a[i]))
        {
            b[*nn] = a[i];
            (*nn)++;
        }
    }

    if (*nn == 0)
        return ERR;

    return 0;
}

void output(const int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int a[N], b[N];
    int n = 0, nn = 0;

    if (input(a, &n))
    {
        return ERR;
    }

    if (form(a, n, b, &nn))
    {
        return ERR;
    }

    output(b, nn);

    return 0;
}
