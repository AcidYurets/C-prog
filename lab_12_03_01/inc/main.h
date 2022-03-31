#ifndef MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 0
#define ERR -1
#define ARG_ERR -2
#define READ_ERR -3
#define KEY_ERR -4
#define SORT_ERR -5
#define MEMORY_ERR -6
#define NULL_POINTER_ERR -7
#define EMPTY_ARR_ERR -8
#define EMPTY_ANS_ERR -9
#define ZERO_SIZE_ERR -10
#define LOAD_ERR -11

int args_check(int argc, char **argv);
int compare(const void *i, const void *j);
int allocation_count(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst);

#endif