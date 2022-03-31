#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "types.h"
#include "list_operations.h"
#include "input.h"


void show_list(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (head)
        {
            student *x = (student*) head->data;
            printf("%s\n%d\n", x->name, x->age);
			
			node *m_head = x->marks;
			while (m_head)
			{
				int *x = (int*) m_head->data;
				printf("%d\n", *x);
				m_head = m_head->next;
			}
			
            head = head->next;
        }
    }
}

void free_list(node *head)
{
    for (node *next; head; head = next)
    {
        next = head->next;
		node *m_head = ((student *)head->data)->marks;
		for (node *n; m_head; m_head = n)
		{
			n = m_head->next;
            free(m_head->data);
			free(m_head);
		}
        free(head->data);
        free(head);
    }
}

int count_marks(node *n)
{
    int cnt = 0;
    node *head = ((student*)n->data)->marks;
    while (head)
    {
        cnt++;
        head = head->next;
    }   
    return cnt;
}

node *copy_list(node *head)
{
    int *m = mark_create(*((int *)head->data));
    node *new_head = node_create(m);
    node *last = new_head;
    head = head->next;

    while (head)
    {
        m = mark_create(*((int *)head->data));
        node *new = node_create(m);
        last->next = new;
        last = new;
        head = head->next;
    }

    return new_head;
}

node *find(node *head, int cnt)
{
    node *new_head = node_create(NULL);
    node *last = new_head;

    while (head)
    {
        if (count_marks(head) > cnt) // Если количество оценок больше заданного...
        {
            node *m_head = copy_list(((student*)head->data)->marks);
            student *s = student_create(((student*)head->data)->name, ((student*)head->data)->age, m_head);
            node *new = node_create(s);
            last->next = new;
            last = new; 
        }
        head = head->next;
    }

    node *x = new_head;
	new_head = new_head->next;
	free(x);

    return new_head;
}


