#include <string.h>
#include "func_lib.h"

int is_simple(int num)
{
    int rc = YES;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            rc = NO;
    return rc;
}


FUNC_DLL void FUNC_DECL generate_simple(int n, int *arr)
{
    int last_simple = 0;
    int j = 0;
    for (int i = 2; j < n; i++)
    {
        if (i > last_simple)
        {
            if (is_simple(i))
            {
                arr[j] = i;
                last_simple = i;
                j++;
            }
        }
    }
}

FUNC_DLL int FUNC_DECL modif_array(int *src, int n, int *dst, int m, int x)
{
    int rc = OK;
    int mode = 0;
    if (m == 0 || dst == NULL)
        mode = 1;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (src[i] % 2 == 0)
        {
            cnt++;
        }
    }

    if (mode == 1) rc = n + cnt;
    else
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            dst[j] = src[i];
            if (dst[j] % 2 == 0)
            {
                dst[j + 1] = x;
                j++;
            }
            j++;
        }
    }
    return rc;
}
