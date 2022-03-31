#include <stdio.h>


int count(int x)
{
    int mx = -1, mn = 11;
    while (x > 0)
    {
        int a = x % 10;
        x /= 10;
        if (a > mx)
            mx = a;
        if (a < mn)
            mn = a;
    }
    int sum = mx + mn;
    return sum;
}

int main()
{
	int x = 0;
    
	int s = scanf("%d", &x);

	if (s == 0)
	{
		return 1;
	}
	
	printf("%d", count(x));
	
	return 0;
}