#include "lab_05.h"

int fill_file(FILE *f, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 1000;
        int w = fwrite(&x, sizeof(int), 1, f);
        if (w != 1)
        {
            return ERR;
        }
    }
    return 0;
}

int output_file(FILE *f)
{
    int cnt = 0;
    int x = 0;
    while (fread(&x, sizeof(int), 1, f) == 1)
    {
        cnt++;
        printf("%d ", x);
    }

    if (cnt == 0)
    {
        return ERR;
    }

    return 0;
}