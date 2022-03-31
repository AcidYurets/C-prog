#include <stdio.h>
#include <math.h>

#define ERR -1

// Перевод в двоичную систему и вывод
void dec2bin(unsigned int dec, int n)
{
    unsigned int v;
    v = 1 << 31;
    for (int i = 0; i <= 31; i++)
    {
        if (dec >= v)
        {
            printf("1");
            dec -= v;
        }
        else
        {
            printf("0");
        }
        v /= 2; 
    }
}


int main()
{
    unsigned int x = 1, x_b, x_e;
    int n = 0;

    int sc = scanf("%u %d", &x, &n);

    if (sc != 2)
    {
        printf("Error: wrong input");
        return ERR;
    }
    if (n < 0)
    {
        printf("Error: n must be >= 0");
        return ERR;
    }
    printf("Result: ");

    // Сдвиг
    n = n % 32;
    x_b = x << (32 - n);
    x_e = x >> n;
    x = x_b | x_e;
    
    // Перевод
    dec2bin(x, n);

    return 0;
}
