#include "../inc/main.h"
#include "../inc/check.h"
#include "../inc/process_goods.h"

int check_select_goods()
{
    int cnt = 0;

    {
        struct good a[] = { { .name = "a", .cost = 10 }, { .name = "b", .cost = 30 }, { .name = "c", .cost = 20 } };
        struct good ans[] = { { .name = "a", .cost = 10 }, { .name = "c", .cost = 20 } };

        struct good *goods = a;
        struct good *sel_goods = NULL;
        int n = sizeof(a) / sizeof(struct good), m = 0;
        double p = 25;
        select_goods(goods, &sel_goods, n, &m, p);

        for (int i = 0; i < m; i++)
        {
            if (strcmp(sel_goods[i].name, ans[i].name) != 0)
            {
                cnt++;
                break;
            }
        }
        if (m != 2)
        {
            cnt++;
        }

        free_goods(sel_goods, m);
    }

    {
        struct good a[] = { { .name = "a", .cost = 10 } };
        struct good ans[] = { { .name = "a", .cost = 10 } };

        struct good *goods = a;
        struct good *sel_goods = NULL;
        int n = sizeof(a) / sizeof(struct good), m = 0;
        double p = 25;
        select_goods(goods, &sel_goods, n, &m, p);

        for (int i = 0; i < m; i++)
        {
            if (strcmp(sel_goods[i].name, ans[i].name) != 0)
            {
                cnt++;
                free_goods(sel_goods, m);
                break;
            }
        }
        if (m != 1)
        {
            cnt++;
        }

        free_goods(sel_goods, m);
    }

    {
        struct good a[] = { { .name = "a", .cost = 10 } };

        struct good *goods = a;
        struct good *sel_goods = NULL;
        int n = sizeof(a) / sizeof(struct good), m = 0;
        double p = 5;
        select_goods(goods, &sel_goods, n, &m, p);

        if (m != 0)
        {
            cnt++;
        }

        free_goods(sel_goods, m);
    }

    return cnt;
}