#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/input.h"
#include "../inc/list_operations.h"
#include "../inc/cmp.h"
#include "../inc/check.h"

int check_append()
{
    int err = 0;

    {
        temp info2[3] = { { .date = "2", .t = 20 } };
        temp ans_info[3] = { { .date = "2", .t = 20 } };
        int n2 = sizeof(info2) / sizeof(temp);
        int m = sizeof(ans_info) / sizeof(temp);
        node *head1 = NULL;
        node *head2 = init_list(info2, n2);
        node *ans = init_list(ans_info, m);

        append(&head1, &head2);
        node *res = head1;

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

        free_list(head1);
        free_list(p);
    }


    {
        temp info1[3] = { { .date = "1", .t = 10 } };
        temp ans_info[3] = { { .date = "1", .t = 10 } };
        int n1 = sizeof(info1) / sizeof(temp);
        int m = sizeof(ans_info) / sizeof(temp);
        node *head1 = init_list(info1, n1);
        node *head2 = NULL;
        node *ans = init_list(ans_info, m);

        append(&head1, &head2);
        node *res = head1;

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

        free_list(head1);
        free_list(p);
    }


    {
        node *head1 = NULL;
        node *head2 = NULL;
        node *ans = NULL;

        append(&head1, &head2);
        node *res = head1;

        if (res != ans)
        {
            err++;
        }
    }

    return err;
}