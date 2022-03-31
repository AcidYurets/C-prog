#include <windows.h>
#include "../inc/main.h"
#include "../inc/filter.h"

typedef int (__cdecl *fn_key_t)(int*, int*, int*, int*);

int check_key()
{
    HMODULE hlib;
    fn_key_t fkey;
    int cnt = 0;

    hlib = LoadLibrary("libkey.dll");
    if (!hlib)
    {
        printf("Cannot open library.\n");
    }

    fkey = (fn_key_t) GetProcAddress(hlib, "key");
    if (!fkey)
    {
        printf("Can not load function.\n");
    }

    // Positive
    {
        int a[] = {1, 2, 3, -4, 5};
        int ans[] = {1, 2, 3};

        int *pb = a;
        int *pe = a + sizeof(a) / sizeof(int);
        int ans_pb[3], *ans_pe = ans_pb + 3;
        int r = fkey(pb, pe, ans_pb, ans_pe);

        int ind = 0;
        if (r != 0)
            cnt++;
        for (int *i = ans_pb; i != ans_pe; i++)
        {
            if (*i != ans[ind])
            {
                cnt++;
                break;
            }
            ind++;
        }
    }

    {
        int a[] = {1, 2, 3, 4, 5};
        int ans[] = {1, 2, 3, 4, 5};

        int *pb = a;
        int *pe = a + sizeof(a) / sizeof(int);
        int ans_pb[5], *ans_pe = ans_pb + 5;
        int r = fkey(pb, pe, ans_pb, ans_pe);

        int ind = 0;
        if (r != 0)
            cnt++;
        for (int *i = ans_pb; i != ans_pe; i++)
        {
            if (*i != ans[ind])
            {
                cnt++;
                break;
            }
            ind++;
        }
    }

    // Negative
    {
        int a[] = {-1, 2, 3, 4, 5};

        int *pb = a;
        int *pe = a + sizeof(a) / sizeof(int);
        int *ans_pb = NULL, *ans_pe = NULL;
        int r = fkey(pb, pe, ans_pb, ans_pe);

        if (r != EMPTY_ANS_ERR)
            cnt++;
    }

    {
        int *pb = NULL;
        int *pe = NULL;
        int *ans_pb = NULL, *ans_pe = NULL;
        int r = fkey(pb, pe, ans_pb, ans_pe);

        if (r != NULL_POINTER_ERR)
            cnt++;
    }

    {
        int a[] = {-1, 2, 3, 4, 5};

        int *pb = a;
        int *pe = a;
        int *ans_pb = NULL, *ans_pe = NULL;
        int r = fkey(pb, pe, ans_pb, ans_pe);

        if (r != EMPTY_ARR_ERR)
            cnt++;
    }

    return cnt;
}