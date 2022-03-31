#ifndef TYPES_H
#define TYPES_H

#define MAX_DATE_SIZE 20

typedef struct node_t node;

struct node_t
{
    void *data;
    node *next;
};

typedef struct temperature
{
    char date[MAX_DATE_SIZE];
    int t;
} temp;

#endif