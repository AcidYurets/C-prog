#include "main.h"
#include "checking.h"

int check_args(char **argv)
{
    int res = 0;
    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
        res = ERR;
    else
    {
        fclose(f);
        char *e;
        double p = strtod(argv[2], &e);
        if (*e || p <= 0)
            res = ERR;
    }
    return res;
}