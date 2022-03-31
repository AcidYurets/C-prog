#include <stdio.h>
#include <math.h>

#define ERR -1
#define N 10

int get_min_max(FILE *f, float *max, float *min);
int cnt_num(FILE *f, float x, int *cnt);