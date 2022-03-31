#include "../inc/main.h"
#include "../inc/process_files.h"
#include "../inc/process_goods.h"

int read_file(FILE *f, struct good **goods, int *n)
{
    int res = 0;
    if (fscanf(f, "%d\n", n) != 1)
        res = READ_NUM_ERR;
    else if (*n < 1)
        res = READ_NUM_ERR;
    else
    {
        *goods = calloc(*n, sizeof(struct good));
        if (*goods)
        {
            for (int i = 0; i < *n && res == OK; i++)
            {
                struct good g = { .name = NULL, .cost = 0 };

                size_t mem_len = 0;
                ssize_t read;
                if ((read = getline(&g.name, &mem_len, f)) == -1)
                {
                    res = MEMORY_ERR;
                }
                else
                {
                    if (g.name[read - 1] == '\n')
                        g.name[read - 1] = '\0';

                    if (fscanf(f, "%d\n", &g.cost) != 1 || g.cost < 0)
                    {
                        res = READ_ERR;
                        free_goods(*goods, *n);
                    } 
                    else
                    {
                        good_copy((*goods) + i, &g);
                    }
                    free(g.name);
                }
            }
        }
        else
        {
            res = MEMORY_ERR;
        }
    }

    return res;
}


void output(struct good *goods, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n%d\n", goods[i].name, goods[i].cost);
    }
}

