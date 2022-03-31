#include <windows.h>
#include "../inc/main.h"
#include "../inc/files_processing.h"
#include "../inc/filter.h"
#include "../inc/sorting.h"

typedef int (__cdecl *fn_key_t)(int*, int*, int*, int*);

int main(int argc, char **argv)
{
    HMODULE hlib;
    fn_key_t fkey;

    int res = OK, err = ERR;
    int *data_pb = NULL, *data_pe = NULL, *memory_begin = NULL, *memory_filtered = NULL; // Указатели на начало и конец динамич. массива
    FILE *fi, *fo;


    hlib = LoadLibrary("libkey.dll");
    if (!hlib)
    {
        printf("Cannot open library.\n");
        res = LOAD_ERR;
    }
    else if (args_check(argc, argv))
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
        fkey = (fn_key_t) GetProcAddress(hlib, "key");
        if (!fkey)
        {
            printf("Can not load function.\n");

            res = LOAD_ERR;
        }
        // Определяем, необходима ли фильтрация
        if (argc == 4)
        {
            int *filtered_pb = NULL, *filtered_pe = NULL;
            int rc = fkey(data_pb, data_pe, NULL, NULL);
            if (rc > 0)
            {
                filtered_pb  = (int*) malloc(rc * sizeof(int));
                if (filtered_pb == NULL)
                    res = MEMORY_ERR;
                else
                {
                    filtered_pe = filtered_pb + rc;
                    err = fkey(data_pb, data_pe, filtered_pb, filtered_pe);
                    if (err < 0)
                        res = err;
                    else
                    {
                        memory_filtered = filtered_pb;
                        data_pb = filtered_pb;
                        data_pe = filtered_pe;
                    }   
                }
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
    FreeLibrary(hlib);
    

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

int compare(const void *i, const void *j)
{
    const int *a = i, *b = j;
    return *a - *b;
}


