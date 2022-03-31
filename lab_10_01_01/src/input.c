#include <stdio.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/input.h"


int read_file(FILE *f, temp *info, int *n)
{
    if (fscanf(f, "%d", n) == 1)
    {
        for (int i = 0; i < *n; i++)
        {
            fscanf(f, "%s", (info + i)->date);
            fscanf(f, "%d", &((info + i)->t));
        }
    }
    else
        return READ_ERR;

    return OK;
}