#include "lab_05.h"

int get_num_by_pos(int pos, FILE *f)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    int el = 0;
    fread(&el, sizeof(int), 1, f);

    return el;
}

void put_num_to_pos(int pos, int num, FILE *f)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, f);
}

int sort(FILE *f)
{
    int x = 0, n = 0;
    while (fread(&x, sizeof(int), 1, f) == 1)
    {
        n++;
    }
    
    if (n == 0)
    {
        return ERR;
    }

    for (int i = 0; i < n - 1; i++) 
    {
        int min_ind = i;
        
        for (int j = i + 1; j < n; j++) 
        {
            if (get_num_by_pos(j, f) < get_num_by_pos(min_ind, f)) 
            {
                min_ind = j;
            }
        }

        if (min_ind != i) 
        {
            int x = get_num_by_pos(i, f);
            int y = get_num_by_pos(min_ind, f);
            put_num_to_pos(i, y, f);
            put_num_to_pos(min_ind, x, f);
        }
    }

    return 0;
}