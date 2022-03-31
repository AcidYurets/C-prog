#include "lab_05.h"

int process(FILE *f)
{
    if (f == NULL)
    {
        return ERR;
    }

    int x = 0;
    int el = 0, l1 = 0, l2 = 0;
    int cnt_max = 0;

    x += fscanf(f, "%d", &l2);
    x += fscanf(f, "%d", &l1);
    x += fscanf(f, "%d", &el);

    if (x == 3)
    {
        if (l1 > l2 && l1 > el)
            cnt_max++;
        l2 = l1;
        l1 = el;
        while (fscanf(f, "%d", &el) == 1)
        {
            if (l1 > l2 && l1 > el)
                cnt_max++;
            l2 = l1;
            l1 = el;
        }
    }
    else
    {
        return ERR;
    }
        

    printf("%d", cnt_max);
    
    return 0;
}


int main()
{
    FILE *f = stdin;

    if (process(f))
    {
        return ERR;
    }

    return 0;
}
