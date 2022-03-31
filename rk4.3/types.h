#ifndef TYPES_H

#define TYPES_H

typedef struct node_t node;

struct node_t
{
    void *data;
    node *next;
};

typedef struct student_t
{
    char name[255];
	int age;
	node *marks; // Список оценок
    
} student;


#endif