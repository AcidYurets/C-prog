#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "types.h"
#include "input.h"


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

student *student_create(char *name, int age, node *marks)
{
    student *new = malloc(sizeof(student));

    if (new)
    {
		strcpy(new->name, name);
        new->age = age;
        new->marks = marks;        
    }
        
    return new;
}

int *mark_create(int mark)
{
    int *new = malloc(sizeof(int));

    if (new)
    {
		*new = mark;
    }
        
    return new;
}


int read_file(FILE *f, node **head)
{
	*head = node_create(NULL);
    node *last = *head;
	
    for (int i = 0; i <= 50; i++)
    {
		char name[255];
		int age = 0;
		if (fscanf(f, "%254s", name) != 1)
		{
			break;
		}
		fscanf(f, "%d", &age);
		
		node *m_head = node_create(NULL);
		node *m_last = m_head;
		for (int j = 0; j <= 10; j++)
		{
			int mark = 0;
			if (fscanf(f, "%d", &mark) != 1)
			{
				break;
			}
			int *m = mark_create(mark);
			node *m_new = node_create(m);
			m_last->next = m_new;
			m_last = m_new;
		}
		node *x = m_head;
		m_head = m_head->next;
		free(x);
		
		student *s = student_create(name, age, m_head);
		node *new = node_create(s);
        last->next = new;
        last = new; 
    }
	
	node *x = *head;
	*head = (*head)->next;
	free(x);

    return OK;
}