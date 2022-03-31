#include "main.h"

int cmp(const void *a, const void *b)
{
	int *a1 = (int*) a;
	int *b1 = (int*) b;
	return *a1 - *b1;
}

int main(int argc, char **argv)
{
	int res = OK;
	if (argc == 2)
	{
		int **a = NULL;
		int n = 0, m = 0;
		FILE *f = fopen(argv[1], "r");
		if (f == NULL)
			return ERR;
		if (read_nm(f, &n, &m))
			return ERR;
		// printf("%d %d\n", n, m);
		a = allocate_matrix(n, m);
		
		if (read_matrix(f, a, n, m))
			return ERR;
		
		int *b = NULL;
		b = malloc(n * m * sizeof(int));
		fill_arr(b, a, n, m);
		int len = n * m;
		
		// Сортировка
		qsort(b, len, sizeof(int), cmp);
		
		/*for (int i = 0; i < len; i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");*/
		
		fill_snake(a, b, n);
		
		print_matrix(a, n, m);
		free(a);
		free(b);
	}
	
	return 0;
}