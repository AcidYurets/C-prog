#include "../inc/main.h"
#include "../inc/check.h"

int main()
{
    int cnt = 0;
    cnt += check_select_goods();

    printf("Found %d errors\n", cnt);
    return OK;
}
