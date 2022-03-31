#include <stdio.h>
#include <stdlib.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/list_operations.h"


node *node_create(const void *data)
{
    node *new = malloc(sizeof(node));

    if (new)
    {
        new->data = (void*) data;
        new->next = NULL;        
    }
        
    return new;
}

node *init_list(temp *info, int n)
{
    node *head = node_create(info);
    node *last = head;

    for (int i = 1; i < n; i++)
    {
        node *new = node_create(info + i);
        last->next = new;
        last = new; 
    }

    return head;
}


void show_list(node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while (head)
        {
            temp *x = (temp*) head->data;
            printf("%s\n%d\n", x->date, x->t);
            head = head->next;
        }
    }
}

void free_list(node *head)
{
    for (node *next; head; head = next)
    {
        next = head->next;
        free(head);
    }
}


node *find(node *head, const void *data, int (*comparator)(const void *, const void *))
{
    node *elem = NULL;

    while (head && !elem)
    {
        if (comparator(head->data, data) == 0)
            elem = head;
        else
            head = head->next;
    }

    return elem;
}

void *pop_front(node **head)
{
    if (head == NULL || *head == NULL)
        return NULL;

    node *del = *head;
    *head = del->next;
    void *data = del->data;

    free(del);

    return data;
}


void append(node **head_a, node **head_b)
{
    if (head_a == NULL || head_b == NULL || *head_b == NULL)
        return;

    if (*head_a == NULL)
    {
        *head_a = *head_b;
        *head_b = NULL;
    }
    else
    {
        node *cur = *head_a;

        while (cur->next)
            cur = cur->next;
        
        cur->next = *head_b;

        *head_b = NULL;
    }
}


void sorted_insert(node **head, node *element, int (*comparator)(const void*, const void*))
{
    if (*head == NULL)
        *head = element;
    else if (comparator((*head)->data, element->data) > 0)
    {
        element->next = *head;
        *head = element;
    }
    else
    {
        node *cur = *head;
        while (cur->next && comparator(cur->next->data, element->data) < 0)
            cur = cur->next;
        element->next = cur->next;
        cur->next = element;
    }
}

node *sort(node *head, int (*comparator)(const void*, const void*))
{
    node *sorted = NULL;
    while (head)
    {
        node *new = head;
        head = head->next;
        new->next = NULL;
        sorted_insert(&sorted, new, comparator);
    }

    return sorted;
}