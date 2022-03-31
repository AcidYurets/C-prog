#ifndef TYPES_H

typedef struct node_t node_t;

struct node_t
{
    int x;
    int y;
    int el;
    node_t *next;
};

#endif