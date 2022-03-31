#include <stdio.h>
#include <stdlib.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/list_operations.h"
#include "../inc/matrix_operations.h"

void find_nm(node_t *head, int *n, int *m)
{
    while (head)
    {
        if (head->x + 1 > *n)
        {
            *n = head->x + 1;
        }
        if (head->y + 1 > *m)
        {
            *m = head->y + 1;
        }
        head = head->next;
    }
}

node_t *add(node_t *head_a, node_t *head_b, node_t *res)
{
    res = node_create(-1, -1, 0);
    node_t *last = res;
    while (head_a || head_b)
    {
        if ((!head_b && head_a) || (head_b && head_a && (head_a->x < head_b->x || (head_a->x == head_b->x && head_a->y < head_b->y))))
        {
            node_t *new = node_create(head_a->x, head_a->y, head_a->el);
            last->next = new;
            last = new; 
            head_a = head_a->next;
        }
        else if ((head_b && head_a) && (head_a->x == head_b->x && head_a->y == head_b->y))
        {
            int ans = head_a->el + head_b->el;
            if (ans != 0)
            {
                node_t *new = node_create(head_a->x, head_a->y, ans);
                last->next = new;
                last = new; 
            }
            head_a = head_a->next;
            head_b = head_b->next;
        }
        else
        {
            node_t *new = node_create(head_b->x, head_b->y, head_b->el);
            last->next = new;
            last = new; 
            head_b = head_b->next;
        }
    }

    node_t *old = res;
    res = res->next;
    free(old);

    return res;
}


node_t *mul(node_t *head_a, node_t *head_b, node_t *res)
{
    int na = 0, nb = 0, ma = 0, mb = 0;
    find_nm(head_a, &na, &ma);
    find_nm(head_b, &nb, &mb);

    res = node_create(-1, -1, 0);
    node_t *last = res;

    // Размеры: (na, k) и (k, mb) => (na, mb)
    for (int i = 0; i < na; i++)
    {
        for (int j = 0; j < mb; j++)
        {
            int sum = 0;
            node_t *p1 = head_a;
            while (p1)
            {
                if (p1->x == i)
                {
                    node_t *p2 = head_b;
                    while (p2)
                    {
                        if (p2->y == j && p2->x == p1->y)
                        {
                            sum += p1->el * p2->el;
                        }
                        p2 = p2->next;
                    }
                }
                p1 = p1->next;
            }
            if (sum != 0)
            {
                node_t *new = node_create(i, j, sum);
                last->next = new;
                last = new; 
            }
        }
    }

    node_t *old = res;
    res = res->next;
    free(old);

    return res;
}

node_t *lin(node_t *head, node_t *res)
{
    if (head == NULL)
        return NULL;
        
    res = node_create(-1, -1, 0);
    node_t *last = res;

    node_t *p = head;
    int max = head->el, line = -1;
    while (p)
    {
        if (p->el > max)
        {
            max = p->el;
            line = p->x;
        }
        p = p->next;
    }

    p = head;
    while (p)
    {
        if (p->x != line)
        {
            node_t *new = node_create(p->x, p->y, p->el);
            last->next = new;
            last = new; 
        }
        p = p->next;
    }
    node_t *old = res;
    res = res->next;
    free(old);

    return res;
}
