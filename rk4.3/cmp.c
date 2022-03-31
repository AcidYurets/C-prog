#include <stdio.h>
#include "types.h"
#include "cmp.h"


int comparator(const void *a1, const void *a2)
{
    student *t1 = (student *) a1;
    student *t2 = (student *) a2;
    return t1->age - t2->age;
}
