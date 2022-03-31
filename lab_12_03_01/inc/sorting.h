#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_TYPE_SIZE 65

void mysort(void *arr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif