#include "main.h"

void fill_arr(int *b, int **a, int n, int m)
{
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			b[len] = a[i][j];
			len++;
		}
	}
}

void fill_snake(int **a, int *b, int n)
{
	int i = 0, j = n - 1, ind = 0;
	int  r = 0;
	while (1)
	{
		if (j > 0)
		{
			a[i][j--] = b[ind++];
			r = n - j - 1;
			for (int k = 0; k < r; k++)
			{
				a[i++][j++] = b[ind++];
			}
		}
		else if (i < n - 1)
		{
			a[i++][j] = b[ind++];
			r = n - i - 1;
			for (int k = 0; k < r; k++)
			{
				a[i++][j++] = b[ind++];
			}
		}
		else
			break;

		if (i < n - 1)
		{
			a[i++][j] = b[ind++];
			r = i;
			for (int k = 0; k < r; k++)
			{
				a[i--][j--] = b[ind++];
			}
		}
		else if (j > 0)
		{
			a[i][j--] = b[ind++];
			r = j;
			for (int k = 0; k < r; k++)
			{
				a[i--][j--] = b[ind++];
			}
		}
		else
			break;
	}
	a[n - 1][0] = b[ind];
}
