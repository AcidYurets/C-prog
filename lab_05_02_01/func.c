#include "lab_05.h"

int get_min_max(FILE *f, float *max, float *min)
{
    float num = 0;

    if (fscanf(f, "%f", max) == 1)
    {
        *min = *max;
        while (fscanf(f, "%f", &num) == 1)
        {
            //printf("%f ", num);
            if (num > *max)
                *max = num;
            if (num < *min)
                *min = num;
        }


        return 0;
    }

    return ERR;
}

int cnt_num(FILE *f, float x, int *cnt)
{
    float num = 0;
    *cnt = 0;

    while (fscanf(f, "%f", &num) == 1)
    {
        //printf("%f ", num);
        if (num > x)
        {
            (*cnt)++;
        }
    }

    return 0;
}
