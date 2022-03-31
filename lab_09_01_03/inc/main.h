#ifndef MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#define OK 0
#define ERR -1
#define MEMORY_ERR -2
#define FILE_ERR -3
#define ARG_ERR -4
#define READ_ERR -5
#define READ_NUM_ERR -6


struct good
{
    char *name;
    int cost;
};

#endif