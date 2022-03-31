#include "../inc/main.h"
#include "../inc/process_files.h"
#include "../inc/process_goods.h"

int main(int argc, char **argv)
{
    int result = OK;
    struct good *goods = NULL, *selected_goods = NULL;
    int n = 0, m = 0;

    if (argc != 3)
        result = ERR;
    else
    {
        FILE *f;
        f = fopen(argv[1], "r");
        if (f == NULL)
            result = FILE_ERR;
        else
        {
            fclose(f);
            char *e;
            double p = strtod(argv[2], &e);
            if (*e || p <= 0)
                result = ARG_ERR;
        }
    }

    if (result == OK)
    {
        FILE *f = fopen(argv[1], "r");
        result = read_file(f, &goods, &n);
        fclose(f);

        if (result == OK)
        {
            char *e;
            double p = strtod(argv[2], &e);
            if (select_goods(goods, &selected_goods, n, &m, p))
            {
                result = MEMORY_ERR;
            }
            else
            {
                output(selected_goods, m);
                free_goods(selected_goods, m);
            }
            free_goods(goods, n);
        }
    }

    return result;
}
