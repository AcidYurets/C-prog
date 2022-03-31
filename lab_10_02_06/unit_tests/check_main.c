#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/input.h"
#include "../inc/list_operations.h"
#include "../inc/matrix_operations.h"
#include "../inc/check.h"

int main()
{
    int err = 0;
    err += check_add();
    err += check_mul();
    err += check_lin();

    printf("Errors count: %d", err);
    return 0;
}