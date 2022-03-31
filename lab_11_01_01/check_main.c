#include "my_snprintf.h"
#include "errors.h"

int main()
{
    int err = 0;

    err += check_my_snprintf();

    printf("Errors count: %d", err);

    return 0;
}
