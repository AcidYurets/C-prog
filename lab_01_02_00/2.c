#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, h;

    scanf("%f%f%f", &a, &b, &h);
    
    float x = fabs(a - b) / 2;
    float c = sqrt(x * x + h * h);
    float p = a + b + 2 * c;

    printf("%f", p);
    
    return 0;
}
