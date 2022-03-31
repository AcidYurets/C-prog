#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define ERR -1
#define N 10

int sort(FILE *f);
int fill_file(FILE *f, int n);
int output_file(FILE *f);
