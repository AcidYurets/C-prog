#include "lab_05.h"

int read_line(char *s, int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n - 1)
            s[i++] = ch;
    s[i] = '\0';
    return i;
}

struct goods get_num_by_pos(int pos, FILE *f)
{
    struct goods g = { "A", "B", 0, 0 };
    memset(&g, 0, sizeof(g));

    fseek(f, pos * sizeof(g), SEEK_SET);
    fread(&g, sizeof(g), 1, f);

    return g;
}

void put_num_to_pos(int pos, struct goods g, FILE *f)
{
    fseek(f, pos * sizeof(g), SEEK_SET);
    fwrite(&g, sizeof(g), 1, f);
}

int sort(FILE *fi, FILE *fo)
{
    struct goods g = { "A", "B", 0, 0 };
    memset(&g, 0, sizeof(g));

    // Посчитаем кол-во записей
    int n = 0;
    while (fread(&g, sizeof(g), 1, fi) == 1)
    {
        fwrite(&g, sizeof(g), 1, fo);
        n++;
    }
    //printf(feof(fi))
    if (n == 0)
    {
        return ERR;
    }

    rewind(fo);
    
    for (int i = 0; i < n - 1; i++) 
    {
        int max_ind = i;
        
        for (int j = i + 1; j < n; j++) 
        {
            struct goods g1 = get_num_by_pos(j, fo), g2 = get_num_by_pos(max_ind, fo);
            if (g1.cost > g2.cost) 
            {
                max_ind = j;
            }
            else if (g1.cost == g2.cost && g1.amount > g2.amount)
            {
                max_ind = j;
            }
        }

        if (max_ind != i) 
        {
            struct goods x = get_num_by_pos(i, fo);
            struct goods y = get_num_by_pos(max_ind, fo);
            put_num_to_pos(i, y, fo);
            put_num_to_pos(max_ind, x, fo);
        }
    }

    return 0;
}


int insert(FILE *f)
{
    struct goods g = { "A", "B", 0, 0 };
    memset(&g, 0, sizeof(g));

    // Посчитаем кол-во записей
    int n = 0;
    while (fread(&g, sizeof(g), 1, f) == 1)
    {
        n++;
    }
    if (n == 0)
    {
        return ERR;
    }
    rewind(f);


    struct goods new = { "A", "B", 0, 0 };
    memset(&new, 0, sizeof(new));

    if (read_line(new.name, NAME_LEN + 1) > 30)
    {
        return ERR;
    }
    if (read_line(new.producer, PROD_LEN + 1) > 15)
    {
        return ERR;
    }
    if (scanf("%u", &(new.cost)) != 1)
    {
        return ERR;
    }
    if (scanf("%u", &(new.amount)) != 1)
    {
        return ERR;
    }

    int ins = 0;
    for (int i = n - 1; i >= 0; i--) 
    {
        struct goods g = get_num_by_pos(i, f);

        if (g.cost < new.cost || (g.cost == new.cost && g.amount < new.amount))
        {
            struct goods x = get_num_by_pos(i, f);
            put_num_to_pos(i + 1, x, f);
        }
        else
        {
            put_num_to_pos(i + 1, new, f);
            ins = 1;
            break;
        }
    }
    if (!ins)
    {
        put_num_to_pos(0, new, f);
    }

    return 0;
}


int output(FILE *f, char str[])
{
    struct goods g = { "A", "B", 0, 0 };
    memset(&g, 0, sizeof(g));

    if (fseek(f, 0, SEEK_END))
    {
        return ERR;
    }
    int sz = ftell(f);
    if (sz % sizeof(g) != 0 || sz <= 0)
    {
        return ERR;
    }

    rewind(f);

    // Посчитаем кол-во записей
    int cnt = 0;
    while (fread(&g, sizeof(g), 1, f) == 1)
    {
        cnt++;
    }
    if (cnt == 0)
    {
        return ERR;
    }

    rewind(f);

    cnt = 0;
    while (fread(&g, sizeof(g), 1, f) == 1)
    {
        int l = strlen(str);
        int len_name = strlen(g.name);
        int check = 1;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] != g.name[len_name - l + i])
            {
                check = 0;
            }
        }

        if (check)
        {
            cnt++;
            printf("%s\n%s\n%d\n%d\n", g.name, g.producer, g.cost, g.amount);
        }
    }
    if (cnt == 0)
    {
        return ERR;
    }

    return 0;
}
