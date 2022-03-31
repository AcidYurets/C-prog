#ifndef PROCESS_GOODS_H

void free_goods(struct good *goods, int n);
int good_copy(struct good *dst, const struct good *src);
int select_goods(struct good *goods, struct good **sel_goods, int n, int *m, double p);

#endif


