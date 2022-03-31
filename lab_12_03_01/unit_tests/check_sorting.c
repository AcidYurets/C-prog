#include "../inc/main.h"
#include "../inc/sorting.h"

int check_compare(const int *i, const int *j)
{
    return *i - *j;
}

int check_mysort()
{
    int cnt = 0;
    
    // Positive
    {
        int a[] = {5, 2, 3, 1, 4};
        int ans[] = {1, 2, 3, 4, 5};

        int *arr = a;
        int n = sizeof(a) / sizeof(int);
        mysort(arr, n, sizeof(int), (int (*)(const void *, const void *)) check_compare);

        for (int i = 0; i < n; i++)
        {
            if (a[i] != ans[i])
            {
                cnt++;
                break;
            }
        }
    }

    {
        int a[] = {5, 4, 3, 2, 1};
        int ans[] = {1, 2, 3, 4, 5};

        int *arr = a;
        int n = sizeof(a) / sizeof(int);
        mysort(arr, n, sizeof(int), (int (*)(const void *, const void *)) check_compare);

        for (int i = 0; i < n; i++)
        {
            if (a[i] != ans[i])
            {
                cnt++;
                break;
            }
        }
    }

    {
        int a[] = {-5, 2, 3, -1, 4, 0};
        int ans[] = {-5, -1, 0, 2, 3, 4};

        int *arr = a;
        int n = sizeof(a) / sizeof(int);
        mysort(arr, n, sizeof(int), (int (*)(const void *, const void *)) check_compare);

        for (int i = 0; i < n; i++)
        {
            if (a[i] != ans[i])
            {
                cnt++;
                break;
            }
        }
    }

    {
        int a[] = {10};
        int ans[] = {10};

        int *arr = a;
        int n = sizeof(a) / sizeof(int);
        mysort(arr, n, sizeof(int), (int (*)(const void *, const void *)) check_compare);

        for (int i = 0; i < n; i++)
        {
            if (a[i] != ans[i])
            {
                cnt++;
                break;
            }
        }
    }

    // Negative
    {
        int *arr = NULL;
        int n = 0;
        mysort(arr, n, sizeof(int), (int (*)(const void *, const void *)) check_compare);
    }

    {
        int a[] = {10};

        int *arr = a;
        int n = sizeof(a) / sizeof(int);
        mysort(arr, n, sizeof(int), NULL);
    }

    {
        int a[] = {10};

        int *arr = a;
        int n = 0;
        mysort(arr, n, sizeof(int), (int (*)(const void *, const void *)) check_compare);
    }

    {
        int a[] = {10};

        int *arr = a;
        int n = sizeof(a) / sizeof(int);
        mysort(arr, n, 0, (int (*)(const void *, const void *)) check_compare);
    }


    return cnt;
}