#include "../inc/main.h"
#include "../inc/check.h"

int main()
{
    int err = 0;
    err += check_delete_row();
    err += check_add_row();

    printf("Err: %d", err);
    return 0;
}

