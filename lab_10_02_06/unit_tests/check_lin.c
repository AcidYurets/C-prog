#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/list_operations.h"
#include "../inc/matrix_operations.h"
#include "../inc/check.h"


int check_lin()
{
    int err = 0;
    node_t *last, *new;

    // 2 1
    // 6 7
    {
        node_t *a = node_create(0, 0, 2);
        last = a;
        new = node_create(0, 1, 1);
        last->next = new;
        last = new;
        new = node_create(1, 0, 6);
        last->next = new;
        last = new;
        new = node_create(1, 1, 7);
        last->next = new;
        last = new;

        node_t *ans = node_create(0, 0, 2);
        last = ans;
        new = node_create(0, 1, 1);
        last->next = new;
        last = new;

        node_t *res = NULL;
        res = lin(a, res);

        node_t *pres = res, *pans = ans;
        while (pres && pans)
        {
            if (pres->x == pans->x && pres->y == pans->y && pres->el == pans->el)
            {
                pres = pres->next;
                pans = pans->next;
            }
            else
            {
                err += 1;
                break;
            }
        }
        if (pres != NULL || pans != NULL)
        {
            err += 1;
        }

        free_list(a);
        free_list(res);
        free_list(ans);
    }

    // NULL
    {
        node_t *a = NULL;

        node_t *ans = NULL;

        node_t *res = NULL;
        res = lin(a, res);

        if (res != ans)
        {
            err += 1;
        }

        free_list(a);
        free_list(res);
        free_list(ans);
    }

    return err;
}