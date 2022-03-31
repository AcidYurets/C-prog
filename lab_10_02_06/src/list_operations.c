#include <stdio.h>
#include <stdlib.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/list_operations.h"


node_t *node_create(int x, int y, int el)
{
    node_t *new = malloc(sizeof(node_t));

    if (new)
    {
        new->x = x;
        new->y = y;
        new->el = el;
        new->next = NULL;        
    }
        
    return new;
}


int show_list(node_t *head)
{
    int rn = OK;
    if (head == NULL)
    {
        rn = EMPTY_LIST;
    }
    else
    {
        while (head->next)
        {
            printf("%d %d %d ", head->x, head->y, head->el);
            head = head->next;
        }
        printf("%d %d %d", head->x, head->y, head->el);
        head = head->next;
        printf("\n");
    }

    return rn;
}

void free_list(node_t *head)
{
    for (node_t *next; head; head = next)
    {
        next = head->next;
        free(head);
    }
}
