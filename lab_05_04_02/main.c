#include "lab_05.h"


int main(int argc, char **argv)
{
    FILE *f, *fi, *fo;
    
    if (argc == 4)
    {
        if (strcmp(argv[1], "sb") == 0)
        {
            fi = fopen(argv[2], "rb");
            fo = fopen(argv[3], "w+b");
            if (fi == NULL || fo == NULL)
            {
                //printf("I/O error\n");
                return ERR;
            }

            if (sort(fi, fo))
            {
                fclose(fi);
                fclose(fo);
                //printf("Write error\n");
                return ERR;
            }

            fclose(fi);
            fclose(fo);
        }
        else if (strcmp(argv[1], "fb") == 0)
        {
            f = fopen(argv[2], "rb");
            if (f == NULL)
            {
                //printf("I/O error\n");
                return ERR;
            }

            if (output(f, argv[3]))
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
            return ARG_ERR;
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "ab") == 0)
        {
            f = fopen(argv[2], "r+b");
            if (f == NULL)
            {
                //printf("I/O error\n");
                return ERR;
            }

            if (insert(f))
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
            return ARG_ERR;
        }
    }
    else
    {
        //printf("Incorrect arg\n");
        return ARG_ERR;
    }
    
    return 0;
}
