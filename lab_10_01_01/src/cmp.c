#include <stdio.h>
#include "../inc/types.h"
#include "../inc/cmp.h"


int comparator(const void *a1, const void *a2)
{
    temp *t1 = (temp *) a1;
    temp *t2 = (temp *) a2;
    return t1->t - t2->t;
}
