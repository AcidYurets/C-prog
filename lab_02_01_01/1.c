#include <stdio.h>
#include <math.h>

#define ERR -1
#define N 10

int input(int a[], int *n)
{
	scanf("%d", n);
	
	int x = 0;
	for (int i = 0; i < *n; i++)
		x += scanf("%d", &a[i]);
	if (x != *n)
		return ERR;
	return 0;
}

void output(const int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int count(const int a[], int n, int *ans)
{
	*ans = 1; 
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2)
		{
			*ans *= a[i];
			cnt++;
		}
	}
	
	if (cnt == 0)
		return ERR;

	return 0;
}

int main()
{
	int a[N];
	int n = 0, x;

	if (input(a, &n))
	{
		return ERR;
	}

	if (count(a, n, &x))
	{
		return ERR;
	}

	printf("%d", x);

	return 0;
}
