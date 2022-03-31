#include "main.h"
#include "process_files.h"
#include "checking.h"

int main(int argc, char **argv)
{
    int result = OK;
    struct good selected_goods[N], goods[N];
    int m = 0, n = 0;

    if (argc != 3)
        result = ERR;
    else
    {
        if (check_args(argv))
            result = ERR;
    }
    
    if (result == OK)
    {
        FILE *f;
        f = fopen(argv[1], "r");
        char *e;
        double p = strtod(argv[2], &e);

        result = read_file(f, goods, &n);
        fclose(f);

        if (!result)
        {
            select_goods(goods, selected_goods, n, &m, p);
        } 
        output(selected_goods, m);
    }

    return result;
}
