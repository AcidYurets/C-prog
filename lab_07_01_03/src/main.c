#include "../inc/main.h"
#include "../inc/files_processing.h"
#include "../inc/filter.h"
#include "../inc/sorting.h"

int args_check(int argc, char **argv);

int main(int argc, char **argv)
{
    int res = OK, err = ERR;
    int *data_pb = NULL, *data_pe = NULL, *memory_begin = NULL, *memory_filtered = NULL; // Указатели на начало и конец динамич. массива
    FILE *fi, *fo;

    if (args_check(argc, argv))
    {
        res = ARG_ERR;
    }
    else
    {
        fi = fopen(*(argv + 1), "r");
        fo = fopen(*(argv + 2), "w");

        if ((err = read_file(fi, &data_pb, &data_pe)))
            res = err;
        memory_begin = data_pb;
    }

    if (!res)
    {
        // Определяем, необходима ли фильтрация
        if (argc == 4)
        {
            int *filtered_pb = NULL, *filtered_pe = NULL;
            if ((err = key(data_pb, data_pe, &filtered_pb, &filtered_pe)))
                res = err;
            else
            {
                memory_filtered = filtered_pb;
                data_pb = filtered_pb;
                data_pe = filtered_pe;
            }
        }
    }

    if (!res)
    {
        int n = data_pe - data_pb;
        mysort(data_pb, n, sizeof(int), compare);
        write_file(fo, data_pb, data_pe);
        
        fclose(fi);
        fclose(fo);
    }

    free(memory_begin);
    free(memory_filtered);
    

    return res;
}


int args_check(int argc, char **argv)
{
    int res = OK;
    if (argc == 3 || argc == 4)
    {
        FILE *f;
        f = fopen(*(argv + 1), "r");
        if (f == NULL)
            res = ERR;
        else
        {
            fclose(f);
            if (argc == 4)
            {
                if (strcmp(*(argv + 3), "f") != 0)
                {
                    res = ERR;
                }
            }
        }
    }
    else
        res = ERR;

    return res;
}
