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


int rev(int n)
{
    int x = 0, d = 1;

    int m = n;
    while (m / 10 != 0)
    {
        m = m / 10;
        d *= 10;
    }
        
    while (n > 0)
    {
        x += (n % 10) * d;
        n /= 10;
        d /= 10;
    }

    return x;
}

int form(const int a[], int n, int b[], int *nn)
{
    *nn = 0;
    for (int i = 0; i < n; i++)
    {
        b[*nn] = a[i];
        (*nn)++;

        if (a[i] > 0)
        {
            b[*nn] = rev(a[i]);
            (*nn)++;
        }
    }

    if (n == *nn)
    {
        return ERR;
    }

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
