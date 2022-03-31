#include <stdio.h>
#include <math.h>

#define ERR -1

// Подсчет суммы
double f(double x, int n)
{
    double ans = x / n;
    return ans;
}


int main()
{
    double x = 0;
    double sum = 0;
    int n = 1;
    while (x >= 0)
    {
        scanf("%lf", &x);
        if (x < 0)
        {
            break;
        }
        sum += f(x, n);
        n++;
    }

    double g = sqrt(sum);

    printf("%f", g);

    return 0;
}
