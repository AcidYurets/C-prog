#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <inttypes.h>
#include <sys/time.h>

#define ERR -1
#define SIZE 50000
#define N 1000

int rand();
int srand();

void process_1(int *a, int n, int *ans)
{
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        cnt *= a[i];
        *ans += cnt;
        
        if (a[i] < 0)
            break;
    }
}

void process_2(int *a, int n, int *ans)
{
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        cnt *= *(a + i);
        *ans += cnt;
        
        if (*(a + i) < 0)
            break;
    }
}


int process_3(int *a, int *b, int *ans)
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


void output(const int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int main(void)
{
    int a[SIZE], *b;
    int an = 0, bn = 0, ans = 0;

    //scanf("%d", &an);
    an = SIZE;
    int i, r;

    srand(time(NULL));

    for (i = 0; i < an; i++)
    {
        r = rand();
        r = r % 10;
        a[i] = r;
    }

    struct timeval tv_start, tv_stop;
    int64_t sum = 0;

    for (i = 0; i < N; i++)
    {
        b = a, bn = an;
        gettimeofday(&tv_start, NULL);
        process_1(b, bn, &ans);
        gettimeofday(&tv_stop, NULL);
        sum += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    }
    double time = sum / N;

    printf("%f\n", time);

    sum = 0;


    for (i = 0; i < N; i++)
    {
        b = a, bn = an;
        gettimeofday(&tv_start, NULL);
        process_2(b, bn, &ans);
        gettimeofday(&tv_stop, NULL);
        sum += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    }
    time = sum / N;

    printf("%f\n", time);

    sum = 0;


    for (i = 0; i < N; i++)
    {
        b = a, bn = an;
        gettimeofday(&tv_start, NULL);
        int *c = (b + bn);
        process_3(b, c, &ans);
        gettimeofday(&tv_stop, NULL);
        sum += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    }
    time = sum / N;

    printf("%f", time);

    return 0;
}
