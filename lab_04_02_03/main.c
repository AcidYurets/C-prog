#include "lab_04_01.h"


int main()
{
    int n = 0, m = 0, k = 0;
    char line1[STR_LEN + 1], line2[STR_LEN + 1];

    int r1 = read_line(line1, STR_LEN + 1);
    int r2 = read_line(line2, STR_LEN + 1);
    if (r1 == 0 || r2 == 0)
    {
        return ERR;
    }

    char arr1[STR_LEN+1][WORD_LEN+1], arr2[STR_LEN+1][WORD_LEN+1], ans[STR_LEN+1][WORD_LEN+1];

    split(arr1, &n, line1);
    split(arr2, &m, line2);

    get_arr(arr1, arr2, ans, n, m, &k);

    if (k == 0)
    {
        return ERR;
    }

    printf("Result: ");
    output(ans, k);

    return 0;
}
