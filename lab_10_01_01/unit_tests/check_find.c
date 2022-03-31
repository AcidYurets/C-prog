#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/input.h"
#include "../inc/list_operations.h"
#include "../inc/cmp.h"
#include "../inc/check.h"

int check_find()
{
    int err = 0;

    {
        temp info[3] = { { .date = "1", .t = 10 }, { .date = "2", .t = 20 }, { .date = "3", .t = 5 } };
        temp data = { .date = "2", .t = 20 };
        temp ans_info[3] = { { .date = "2", .t = 20 }, { .date = "3", .t = 5 } };
        int n = sizeof(info) / sizeof(temp);
        int m = sizeof(ans_info) / sizeof(temp);
        node *head = init_list(info, n);
        node *ans = init_list(ans_info, m);

        node *res = find(head, &data, comparator);

        node *p = ans;
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

        free_list(head);
        free_list(p);
    }


    {
        temp info[] = { { .date = "2", .t = 20 }, { .date = "2", .t = 20 }, { .date = "2", .t = 20 } };
        temp data = { .date = "2", .t = 20 };
        temp ans_info[] = { { .date = "2", .t = 20 }, { .date = "2", .t = 20 }, { .date = "2", .t = 20 } };
        int n = sizeof(info) / sizeof(temp);
        int m = sizeof(ans_info) / sizeof(temp);
        node *head = init_list(info, n);
        node *ans = init_list(ans_info, m);

        node *res = find(head, &data, comparator);

        node *p = ans;
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
        free_list(head);
        free_list(p);
    }


    {
        temp info[] = { { .date = "2", .t = 20 } };
        temp data = { .date = "2", .t = 20 };
        temp ans_info[] = { { .date = "2", .t = 20 } };
        int n = sizeof(info) / sizeof(temp);
        int m = sizeof(ans_info) / sizeof(temp);
        node *head = init_list(info, n);
        node *ans = init_list(ans_info, m);

        node *res = find(head, &data, comparator);

        node *p = ans;
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
        free_list(head);
        free_list(p);
    }

    {
        temp info[] = { { .date = "2", .t = 20 } };
        temp data = { .date = "2", .t = 21 };
        int n = sizeof(info) / sizeof(temp);
        node *head = init_list(info, n);
        node *ans = NULL;

        node *res = find(head, &data, comparator);

        node *p = ans;
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
        free_list(head);
        free_list(p);
    }

    {
        temp data = { .date = "2", .t = 21 };
        node *head = NULL;
        node *ans = NULL;

        node *res = find(head, &data, comparator);
    
        node *p = ans;
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
        free_list(head);
        free_list(p);
    }

    return err;
}