#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/input.h"
#include "../inc/list_operations.h"
#include "../inc/cmp.h"
#include "../inc/check.h"

int check_sort()
{
    int err = 0;

    {
        temp info[] = { { .date = "1", .t = 10 }, { .date = "2", .t = 20 }, { .date = "3", .t = 5 } };
        temp ans_info[] = { { .date = "3", .t = 5 }, { .date = "1", .t = 10 }, { .date = "2", .t = 20 } };
        int n = sizeof(info) / sizeof(temp);
        int m = sizeof(ans_info) / sizeof(temp);
        node *head = init_list(info, n);
        node *ans = init_list(ans_info, m);

        node *res = sort(head, comparator);

        node *p = ans;
        node *res_free = res;
        while (res && ans)
        {
            if (((temp*) (res->data))->t == ((temp*) (ans->data))->t)
            {
                ans = ans->next;
                res = res->next;
            }
            else
            {
                err++;
                break;
            }
        }
        if (res != NULL || ans != NULL)
        {
            err++;
        }

        free_list(res_free);
        free_list(p);
    }


    {
        temp info[] = { { .date = "3", .t = 5 } };
        temp ans_info[] = { { .date = "3", .t = 5 } };
        int n = sizeof(info) / sizeof(temp);
        int m = sizeof(ans_info) / sizeof(temp);
        node *head = init_list(info, n);
        node *ans = init_list(ans_info, m);

        node *res = sort(head, comparator);

        node *p = ans;
        node *res_free = res;
        while (res && ans)
        {
            if (((temp*) (res->data))->t == ((temp*) (ans->data))->t)
            {
                ans = ans->next;
                res = res->next;
            }
            else
            {
                err++;
                break;
            }
        }
        if (res != NULL || ans != NULL)
        {
            err++;
        }

        free_list(res_free);
        free_list(p);
    }


    {
        node *head = NULL;
        node *ans = NULL;

        node *res = sort(head, comparator);

        if (res != NULL || ans != NULL)
        {
            err++;
        }
    }

    {
        node *ans = NULL;

        node *res = sort(NULL, comparator);

        if (res != NULL || ans != NULL)
        {
            err++;
        }
    }

    return err;
}