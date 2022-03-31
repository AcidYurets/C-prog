#include <stdio.h>
#include <stdlib.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/input.h"
#include "../inc/list_operations.h"


node_t *read_list(node_t *head)
{
    int err = 0;
    head = NULL;
    node_t *last = NULL;
    int n = 0, m = 0, check = 0;
    if (scanf("%d%d", &n, &m) == 2 && n > 0 && m > 0)
    {
        for (int i = 0; i < n && !err; i++)
        {
            for (int j = 0; j < m && !err; j++)
            {
                int el = 0;
                if (scanf("%d", &el) != 1)
                {
                    err = 1;
                    free_list(head);
                    head = NULL;
                }
                else
                {
                    if (el != 0)
                    {
                        if (check == 0)
                        {
                            head = node_create(i, j, el);
                            last = head;
                            check = 1;
                        }      
                        else
                        {
                            node_t *new = node_create(i, j, el);
                            last->next = new;
                            last = new; 
                        }
                    }
                }
            }
        }
    }

    
    return head;
}
