#include <stdio.h>
#include <math.h>

#define ERR -1

// Подсчет площади по формуле Герона
float square(float a, float b, float c)
{
    float p = (a + b + c) / 2;
    float s = sqrtf(p * (p - a) * (p - b) * (p - c));
    return s;
}

// Проверка треугольника на вырожденность 
int check(float a, float b, float c)
{
    if (a + b <= c || c + b <= a || a + c <= b)
    {
        return 1;
    }
    return 0;
}


int main()
{
    float xa, ya, xb, yb, xc, yc;

    int x = scanf("%f%f%f%f%f%f", &xa, &ya, &xb, &yb, &xc, &yc);
    
    if (x != 6)
    {
        return ERR;
    }
    
    float ab, bc, ac;
    ab = sqrtf((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    bc = sqrtf((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb));
    ac = sqrtf((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));

    if (check(ab, bc, ac))
    {
        return ERR;
    }

    float s = square(ab, bc, ac);
     

    printf("%f", s);
    
    return 0;
}
