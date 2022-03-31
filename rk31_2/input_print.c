#include "main.h"

int read_nm(FILE *f, int *n, int *m)
{
	if (fscanf(f, "%d%d", n, m) != 2)
		return ERR;
	if (*n <= 1 || *n >= 100 || *n != *m)
		return ERR;
	return OK;
}

int read_matrix(FILE *f, int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int el = 0;
			if (fscanf(f, "%d", &el) != 1)
			{
				free(a);
				return ERR;
			}
			a[i][j] = el;
		}
	}

	return OK;
}

int print_matrix(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return OK;
}