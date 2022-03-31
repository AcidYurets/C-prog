#ifndef PROCESS_H

int read_file(FILE *f, struct good *goods, int *n);
void output(struct good *goods, int n);
void select_goods(struct good *goods, struct good *sel_goods, int n, int *m, double p);

#endif