#include <stdio.h>
#include <math.h>

#define ERR -1
#define N 10

int input(int *a, int *b)
{
    int x = 0;
    size_t n = (b - a);

    while (a < b)
    {
        x += scanf("%d", a);
        a++;
    }
    
    if (n == 0)
        return ERR;

    if (x != n)
        return ERR;
    return 0;
}


int count(int *a, int *b, int *ans)
{
    int cnt = 1;
    while (a < b)
    {
        cnt *= *a;
        *ans += cnt;
        
        if (*a < 0)
            break;
        a++;
    }
    return 0;
}


int main()
{
    int a[N];
    int n = 0, ans = 0;

    scanf("%d", &n);
    int *b = (a + n);

    if (input(a, b))
    {
        return ERR;
    }

    if (count(a, b, &ans))
    {
        return ERR;
    }

    printf("%d", ans);

    return 0;
}
