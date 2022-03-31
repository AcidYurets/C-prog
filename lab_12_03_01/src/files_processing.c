#include "../inc/main.h"
#include "../inc/files_processing.h"

// Динамически выделяет память и записывает в нее данные из файла
IO_DLL int IO_DECL read_file(FILE *f, int **pb, int **pe)
{
    int n = 0, x = 0;
    int res = OK;
    while (fscanf(f, "%d", &x) == 1)
        n++;
    if (!(feof(f) && n != 0))
        res = READ_ERR;
    else
    {
        *pb = (int*) malloc(n * sizeof(int));
        if (*pb == NULL)
            res = MEMORY_ERR;
        else
        {
            *pe = *pb + n;

            rewind(f);
            for (int *i = *pb; i != *pe; i++)
            {
                fscanf(f, "%d", i);
            }
        }
    }
    return res;
}

IO_DLL void IO_DECL write_file(FILE *f, int *pb, int *pe)
{
    for (int *i = pb; i != pe - 1; i++)
    {
        fprintf(f, "%d ", *i);
    }
    fprintf(f, "%d\n", *(pe - 1));
}
