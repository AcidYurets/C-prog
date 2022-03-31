#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define ERR -1
#define ARG_ERR 53
#define N 10
#define NAME_LEN 31
#define PROD_LEN 16
#define NUM_LEN 20

struct goods
{
    char name[NAME_LEN];
    char producer[PROD_LEN];
    unsigned int cost;
    unsigned int amount;
};

int sort(FILE *fi, FILE *fo);
int insert(FILE *f);
int output(FILE *f, char str[]);