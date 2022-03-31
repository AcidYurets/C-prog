#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "types.h"
#include "input.h"
#include "list_operations.h"
#include "cmp.h"


int main(int argc, char **argv)
{
    if (argc != 3 && argc != 5)
    {
        return ARG_ERR;
    }
    int ret = OK;
    node *head = NULL;
	
	if (strcmp(argv[1], "-f") == 0)
	{
		FILE *f = fopen(argv[2], "r");
		if (f == NULL)
			ret = FILE_ERR;
		else
		{
			ret = read_file(f, &head);
			fclose(f);
		}
	}
	else
		ret = ARG_ERR;
    
    
    if (ret == OK)
    {
		if (argc == 3)
		{
			show_list(head);
		}
		else if (argc == 5)
		{
			if (strcmp(argv[3], "-m") == 0) // Я не помню какой был ключ, так что будет -m
			{
				int marks_count = atoi(argv[4]);
				node *new_head = find(head, marks_count);
				show_list(new_head);

				free_list(new_head);
			}
			else
			{
				ret = ARG_ERR;
			}
		}
        
        free_list(head);
    }

    return ret;
}
