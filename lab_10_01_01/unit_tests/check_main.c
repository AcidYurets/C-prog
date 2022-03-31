#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/input.h"
#include "../inc/list_operations.h"
#include "../inc/cmp.h"
#include "../inc/check.h"

int main()
{
    int err = 0;
    err += check_find();
    err += check_pop();
    err += check_append();
    err += check_sort();

    printf("Errors: %d", err);
    return 0;
}