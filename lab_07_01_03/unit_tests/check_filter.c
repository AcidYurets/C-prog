#include "../inc/main.h"
#include "../inc/filter.h"

int check_key()
{
    int cnt = 0;

    // Positive
    {
        int a[] = {1, 2, 3, -4, 5};
        int ans[] = {1, 2, 3};

        int *pb = a;
        int *pe = a + sizeof(a) / sizeof(int);
        int *ans_pb = NULL, *ans_pe = NULL;
        int r = key(pb, pe, &ans_pb, &ans_pe);

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
        free(ans_pb);
    }

    {
        int a[] = {1, 2, 3, 4, 5};
        int ans[] = {1, 2, 3, 4, 5};

        int *pb = a;
        int *pe = a + sizeof(a) / sizeof(int);
        int *ans_pb = NULL, *ans_pe = NULL;
        int r = key(pb, pe, &ans_pb, &ans_pe);

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
        free(ans_pb);
    }

    // Negative
    {
        int a[] = {-1, 2, 3, 4, 5};

        int *pb = a;
        int *pe = a + sizeof(a) / sizeof(int);
        int *ans_pb = NULL, *ans_pe = NULL;
        int r = key(pb, pe, &ans_pb, &ans_pe);

        if (r != EMPTY_ANS_ERR)
            cnt++;
        free(ans_pb);
    }

    {
        int *pb = NULL;
        int *pe = NULL;
        int *ans_pb = NULL, *ans_pe = NULL;
        int r = key(pb, pe, &ans_pb, &ans_pe);

        if (r != NULL_POINTER_ERR)
            cnt++;
        free(ans_pb);
    }

    {
        int a[] = {-1, 2, 3, 4, 5};

        int *pb = a;
        int *pe = a;
        int *ans_pb = NULL, *ans_pe = NULL;
        int r = key(pb, pe, &ans_pb, &ans_pe);

        if (r != EMPTY_ARR_ERR)
            cnt++;
        free(ans_pb);
    }

    return cnt;
}