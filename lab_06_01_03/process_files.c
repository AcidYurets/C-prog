#include "main.h"
#include "process_files.h"

int read_file(FILE *f, struct good *goods, int *n)
{
    int res = 0;
    if (fscanf(f, "%d\n", n) != 1)
        res = ERR;
    else if (*n < 1 || *n > 15)
        res = ERR;
    else
    {
        for (int i = 0; i < *n && res == 0; i++)
        {
            struct good g = { .name = "", .cost = 0 };

            fgets(g.name, NAME_LEN + 1, f);
            if (g.name[strlen(g.name) - 1] == '\n')
                g.name[strlen(g.name) - 1] = '\0';

            if (fscanf(f, "%d\n", &g.cost) != 1 || g.cost < 0)
                res = ERR;
            else
                goods[i] = g;
        }
    }
    return res;
}


void output(struct good *goods, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n%d\n", goods[i].name, goods[i].cost);
    }
}


void select_goods(struct good *goods, struct good *sel_goods, int n, int *m, double p)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (goods[i].cost < p)
        {
            sel_goods[j] = goods[i];
            j++;
        }
    }
    *m = j;
}