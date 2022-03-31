#include "lab_05.h"


int main(int argc, char **argv)
{
    FILE *f;
    
    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("I/O error\n");

        return ERR;
    }

    float min = 0, max = 0;
    int cnt = 0;
    
    if (get_min_max(f, &max, &min))
    {
        printf("Empty file\n");

        return ERR;
    }

    float x = (min + max) / 2;
    //printf("%f", x);

    rewind(f);

    if (cnt_num(f, x, &cnt))
    {
        return ERR;
    }
    
    printf("%d", cnt);

    fclose(f);

    return 0;
}
