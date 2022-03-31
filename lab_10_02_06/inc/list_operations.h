#ifndef LIST_OPERATIONS_H

node_t *node_create(int x, int y, int el);
int show_list(node_t *head);
void free_list(node_t *head);

#endif