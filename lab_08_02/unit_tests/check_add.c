#include "../inc/main.h"
#include "../inc/add-del_operations.h"
#include "../inc/check.h"

int check_add_row()
{
    int err = 0;
    {
        int data[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }, n = 3, m = 3;
        int ans[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {4, 5, 6} };
        int* a[4] = { data[0], data[1], data[2], data[3] };
        add_row(a, n, m);

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] != ans[i][j])
                {
                    err++;
                    break;
                }
            }
        }
    }

    {
        int data[2][3] = { {1, 2, 3} }, n = 1, m = 3;
        int ans[2][3] = { {1, 2, 3}, {1, 2, 3} };
        int* a[2] = { data[0], data[1] };
        add_row(a, n, m);

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] != ans[i][j])
                {
                    err++;
                    break;
                }
            }
        }
    }



    return err;
}
