#include <stdio.h>

#define ERR -1

// Функция возвращает частное a и d. В a после ее выполнения хранится остаток от этого деления.
int div(int *a, int *d) 
{
	int ans = 0;
	while (*a >= *d)
	{
		*a -= *d;
		ans += 1;
	}
	return ans;
}


int main()
{
	int a = 0, d = 0;
	int x = scanf("%d%d", &a, &d);
	
	if (x != 2)
	{
		return ERR;
	}
	if (a <= 0 || d <= 0)
	{
		return ERR;
	}
	int q = div(&a, &d);
	int r = a;

	printf("%d %d", q, r);

	return 0;	
}

