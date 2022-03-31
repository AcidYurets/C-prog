#ifndef INPUT_H

node *node_create(const void *data);
student *student_create(char *name, int age, node *marks);
int *mark_create(int mark);
int read_file(FILE *f, node **head);

#endif