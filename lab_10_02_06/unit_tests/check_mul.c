#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/list_operations.h"
#include "../inc/matrix_operations.h"
#include "../inc/check.h"


int check_mul()
{
    int err = 0;
    node_t *last, *new;

    // 2 1 и 3
    //       5
    {
        node_t *a = node_create(0, 0, 2);
        last = a;
        new = node_create(0, 1, 1);
        last->next = new;
        last = new;

        node_t *b = node_create(0, 0, 3);
        last = b;
        new = node_create(1, 0, 5);
        last->next = new;
        last = new;

        node_t *ans = node_create(0, 0, 11);
        last = ans;

        node_t *res = NULL;
        res = mul(a, b, res);

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
        free_list(b);
        free_list(res);
        free_list(ans);
    }

    // NULL и 1
    {
        node_t *b = node_create(0, 0, 1);

        node_t *a = NULL;

        node_t *res = NULL;
        res = mul(a, b, res);

        if (res != NULL)
        {
            err += 1;
        }

        free_list(a);
        free_list(b);
        free_list(res);
    }

    // 1 и NULL
    {
        node_t *a = node_create(0, 0, 1);

        node_t *b = NULL;

        node_t *res = NULL;
        res = mul(a, b, res);

        if (res != NULL)
        {
            err += 1;
        }

        free_list(a);
        free_list(b);
        free_list(res);
    }

    // NULL и NULL
    {
        node_t *a = NULL;

        node_t *b = NULL;

        node_t *res = NULL;
        res = mul(a, b, res);

        if (res != NULL)
        {
            err += 1;
        }

        free_list(a);
        free_list(b);
        free_list(res);
    }

    return err;
}