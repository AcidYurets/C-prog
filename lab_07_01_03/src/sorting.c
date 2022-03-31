#include "../inc/main.h"
#include "../inc/sorting.h"
#include "../inc/files_processing.h"

//#include <sys/time.h>
//#include <inttypes.h>


int compare(const void *i, const void *j)
{
    const int *a = i, *b = j;
    return *a - *b;
}

void assign(char *a, char *b, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        *a = *b;
        a++;
        b++;
    }
}


void mysort(void *arr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    char key[MAX_TYPE_SIZE];
    
    char *data = (char*) arr;
    for (int i = 1; i < num; i++)
    {
        assign(key, data + i * size, size);
        int l = 0, r = i;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (compare(key, data + mid * size) < 0)
                r = mid;
            else
                l = mid + 1;
        }
        for (int j = i; j >= l + 1; j--)
        {
            assign(data + j * size, data + (j - 1) * size, size);
        }
        
        assign(data + l * size, key, size);
    }
}