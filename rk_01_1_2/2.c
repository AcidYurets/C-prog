#include <stdio.h>

#define N 100

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int inp(int a[], int *n)
{
    int s = scanf("%d", n);
    if (s == 0)
	{
		return 1;
	}

    s = 0;
    for (int i = 0; i < *n; i++)
    {
        s += scanf("%d", &a[i]);
    }
    if (s != *n)
    {
        return 1;
    }
    return 0;
}

void out(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void del(int a[], int ind, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (i >= ind)
        {
            //printf("%d ", a[i]);
            swap(&a[i], &a[i + 1]);
        }
    }

}

void change(int a[], int k, int *n)
{
    int cnt = 0;
    for (int i = 0; i < *n; i++)
    {
        if (a[i] % k == 0)
        {
            if (cnt % 2 == 1)
            {
                del(a, i, *n);
                *n -= 1;
                i -= 1;
            }
            cnt++;
        }
    }
}

int main()
{
    int a[N], n;

	if (inp(a, &n))
    {
        return 1;
    }

    int k = 0;
    scanf("%d", &k);

    change(a, k, &n);

    out(a, n);
	
	return 0;
}