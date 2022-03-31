#include <stdio.h>
#include <math.h>

int main()
{
    float h, t, m;

    scanf("%f%f%f", &h, &t, &m);
    
    float m_norm = h * t / 240; 
    h = h / 100;
    float bmi = m / (h * h);

    printf("%f %f", m_norm, bmi);
    
    return 0;
}