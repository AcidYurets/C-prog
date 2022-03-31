#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ERR -1
#define STR_LEN 101
#define N 1300

struct data
{
    char city_name[STR_LEN];
    char region[STR_LEN];
    char fed_okc[STR_LEN];
    int population;
    int year;
};

int main()
{
    FILE *fi, *fo;

    fi = fopen("in.txt", "r");
    fo = fopen("out.txt", "w");

    char num[6], *e;

    fgets(num, 6, fi);
    int n = strtol(num, &e, 10);

    struct data d[N];

    for (int i = 0; i < n; i++)
    {
        char name[STR_LEN], reg[STR_LEN], okr[STR_LEN], pop_s[STR_LEN], y_s[STR_LEN];
        int pop, y;
        fgets(name, STR_LEN, fi);
        fgets(reg, STR_LEN, fi);
        fgets(okr, STR_LEN, fi);
        fgets(pop_s, STR_LEN, fi);
        fgets(y_s, STR_LEN, fi);

        pop = strtol(pop_s, &e, 10);
        y = strtol(y_s, &e, 10);
        strcpy(d[i].city_name, name);
        strcpy(d[i].region, reg);
        strcpy(d[i].fed_okc, okr);
        d[i].population = pop;
        d[i].year = y;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += d[i].population;
    }
    int ans1 = cnt / n;
    fprintf(fo, "%d\n", ans1);

    int ind = 0, max = 0; 
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; d[i].city_name[j] != '\0'; j++)
        {
            
            if (d[i].city_name[j] == 's')
            {
                cnt++;
            }
            //printf("%c ", d[i].city_name[j]);
        }
        //printf("%d\n", ind);

        if (cnt > max)
        {
            max = cnt;
            ind = i;
        }
    }
    //printf("%s", d[ind].city_name);
    fprintf(fo, "%d\n", d[ind].year);
    
    //printf("%s %s %s %d %d", d[2].city_name, d[2].region, d[2].fed_okc, d[2].population, d[2].year);

    fclose(fi);
    fclose(fo);

    return 0;
}
