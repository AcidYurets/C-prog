#include "lab_05.h"

/*
Алгоритм работает с бинарными файлам, состоящими из целочисленных чисел типа int. В качестве алгоритма сортировки я выбрал сортировку выбором, 
т.к. необходимо минимизировать кол-во обращений к элементам файла. В файле числа сортируются по возрастанию. 
*/


int main(int argc, char **argv)
{
    FILE *f;
    
    if (argc == 4)
    {
        if (strcmp(argv[1], "c") == 0)
        {
            f = fopen(argv[3], "wb");
            if (f == NULL)
            {
                //printf("I/O error\n");
                return ERR;
            }
            char *e;
            int x = strtol(argv[2], &e, 10);
            //printf("errno: %d\nx = %d", errno, x);
            if (fill_file(f, x))
            {
                fclose(f);
                //printf("Write error\n");
                return ERR;
            }

            fclose(f);
        }
        else
        {
            //printf("Incorrect arg\n");
            return ERR;
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "p") == 0)
        {
            f = fopen(argv[2], "rb");
            if (f == NULL)
            {
                //printf("I/O error\n");
                return ERR;
            }

            fseek(f, 0, SEEK_END);
            int sz = ftell(f);
            if (sz % sizeof(int) != 0)
            {
                fclose(f);
                //printf("Invalid file\n");
                return ERR;
            }
            rewind(f);

            if (output_file(f))
            {
                fclose(f);
                //printf("Empty file\n");
                return ERR;
            }

            fclose(f);
        }
        else if (strcmp(argv[1], "s") == 0)
        {
            FILE *f;
            f = fopen(argv[2], "r+b");
            if (f == NULL)
            {
                //printf("I/O error\n");
                return ERR;
            }

            fseek(f, 0, SEEK_END);
            int sz = ftell(f);
            if (sz % sizeof(int) != 0)
            {
                fclose(f);
                //printf("Invalid file\n");
                return ERR;
            }
            rewind(f);

            if (sort(f))
            {
                fclose(f);
                //printf("Empty file\n");
                return ERR;
            }

            fclose(f);
        }
        else
        {
            //printf("Incorrect arg\n");
            return ERR;
        }
    }
    else
    {
        //printf("Incorrect arg\n");
        return ERR;
    }
    
    return 0;
}
