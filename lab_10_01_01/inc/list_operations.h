#ifndef LIST_OPERATIONS_H

node *init_list(temp *info, int n);
node *find(node *head, const void *data, int (*comparator)(const void *, const void *));
void show_list(node *head);

void free_list(node *head);
void *pop_front(node **head);
void append(node **head_a, node **head_b);
node *sort(node *head, int (*comparator)(const void*, const void*));

#endif