#include <stdio.h>
#include <math.h>

#define ERR -1
#define EPS 1e-8

// Вычисление s
double calc_s(double x, double eps)
{
    double first_x = x;
    double s = 0;
    double n = 1;
    int cnt_n = 1;
    while (fabs(x / n) > eps)
    {
        s += x / n;
        x *= first_x * first_x;
        n *= -1 * (cnt_n + 1) * (cnt_n + 2);
        cnt_n += 2;
    }
    return s;
}


int main()
{
    double x = 1, eps = 1;

    int sc = scanf("%lf%lf", &x, &eps);
    
    if (sc != 2)
    {
        return ERR;
    }
    if (eps <= 0 || eps > 1)
    {
        return ERR;
    }

    double s = calc_s(x, eps);
    double f = sin(x);

    if (fabs(f) <= 0.000001)
    {
        return ERR;
    }
		

    // Вычисление погрешностей
    double abs_err, rel_err;
    abs_err = fabs(f - s);
    rel_err = abs_err / fabs(f);

    printf("%f %f %f %f", s, f, abs_err, rel_err);
    
    return 0;
}
