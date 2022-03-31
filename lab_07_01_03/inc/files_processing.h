#ifndef FILES_H
#include <stdio.h>
#include <stdlib.h>

int read_file(FILE *f, int **pb, int **pe);
void write_file(FILE *f, int *pb, int *pe);

#endif