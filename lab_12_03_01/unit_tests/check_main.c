#include "../inc/main.h"
#include "../inc/check.h"

int main()
{
    int cnt = 0;

    cnt += check_key();
    cnt += check_mysort();

    printf("Errors found: %d", cnt);

    return 0;
}