#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define INT_LEN 13
#define NOTATION_16_BASE 16
#define NOTATION_10_BASE 10

int my_snprintf(char *str, size_t size, const char *format, ...);

int check_my_snprintf();

#endif
