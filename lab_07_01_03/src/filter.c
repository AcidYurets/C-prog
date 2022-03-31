#include "../inc/main.h"
#include "../inc/filter.h"


void copy_array(const int *pb_src, int **pb_dst, int **pe_dst)
{
    int x = 0;
    for (int *i = *pb_dst; i != *pe_dst; i++)
    {
        *i = *(pb_src + x);
        x++;
    }
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL || pb_dst == NULL || pe_dst == NULL)
        return NULL_POINTER_ERR;
    
    if (pb_src >= pe_src)
        return EMPTY_ARR_ERR;
    
    int res = OK;
    
    int n = pe_src - pb_src - 1;
    for (int *i = (int*) (pe_src - 2); i != pb_src - 1 && *(i + 1) >= 0; i--)
    {
        n--;
    }

    int src_len = pe_src - pb_src;
    if (*pb_src >= 0 && n == 0)
    {
        n = src_len;
        *pb_dst = (int*) malloc(src_len * sizeof(int));
        if (*pb_dst == NULL)
            res = MEMORY_ERR;
        else
            *pe_dst = *pb_dst + n;
        
        copy_array(pb_src, pb_dst, pe_dst);
    }
    else if (n == 0)
        res = EMPTY_ANS_ERR; 
    else
    {
        *pb_dst = (int*) malloc(n * sizeof(int));
        if (*pb_dst == NULL)
            res = MEMORY_ERR;
        else
        {
            *pe_dst = *pb_dst + n;
            copy_array(pb_src, pb_dst, pe_dst); 
        }
    } 
    return res;
}
