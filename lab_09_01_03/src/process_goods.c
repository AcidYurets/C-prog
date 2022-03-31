#include "../inc/main.h"
#include "../inc/process_goods.h"

int good_copy(struct good *dst, const struct good *src)
{
    int rc = OK;
    char *ptmp = strdup(src->name);
    if (ptmp)
    {
        free(dst->name);
        dst->name = ptmp;
        dst->cost = src->cost;
        rc = OK;
    }
    else
        rc = MEMORY_ERR;

    return rc;
}

void free_goods(struct good *goods, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(goods[i].name);
    }
    free(goods);
}

int сalculate_m(struct good *goods, int n, double p)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (goods[i].cost < p)
        {
            j++;
        }
    }
    return j;
}

int select_goods(struct good *goods, struct good **sel_goods, int n, int *m, double p)
{
    int rc = OK;
    *m = сalculate_m(goods, n, p);

    *sel_goods = calloc(*m, sizeof(struct good));
    if (*sel_goods)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (goods[i].cost < p)
            {
                good_copy((*sel_goods) + j, goods + i);
                j++;
            }
        }
    }
    else
    {
        rc = MEMORY_ERR;
    }

    return rc;
}