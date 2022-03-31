#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/input.h"
#include "../inc/list_operations.h"
#include "../inc/cmp.h"

// Аргументы: имя файла и операция (find, pop_f, append, ). Вывод производится на экран.
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return ARG_ERR;
    }
    int ret = OK;
    temp info[100];
    int n = 0;
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        ret = FILE_ERR;
    else
    {
        ret = read_file(f, info, &n);
        fclose(f);
    }
    
    if (ret == OK)
    {
        node *head = init_list(info, n);
        printf("List:\n");
        show_list(head);

        if (strcmp(argv[2], "find") == 0)
        {
            printf("Enter temperature to find:\n");
            temp new = { .date = "", .t = 0 };
            if (scanf("%d", &(new.t)) != 1)
            {
                ret = READ_ERR;
            }
            else
            {
                node *ans = find(head, (void*) &new, comparator);
                if (ans == NULL)
                {
                    printf("Not found!");
                }
                else
                {
                    printf("A day with this temperature: %s\n", ((temp*) ans->data)->date);
                }
            }
        }
        else if (strcmp(argv[2], "pop_f") == 0)
        {
            temp *data = pop_front(&head);
            if (data == NULL)
                printf("Can't pop data!\n");
            else
                printf("Poped data:\n%s\n%d\n", data->date, data->t);
        }
        else if (strcmp(argv[2], "append") == 0)
        {
            node *head_2 = init_list(info, n);
            append(&head, &head_2);
            printf("Appended list:\n");
            show_list(head);
        }
        else if (strcmp(argv[2], "sort") == 0)
        {
            head = sort(head, comparator);
            printf("Sorted list:\n");
            show_list(head);
        }

        
        free_list(head);
    }

    return ret;
}
