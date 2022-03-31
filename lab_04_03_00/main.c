#include "lab_04.h"


int main()
{
    int n = 0, m = 0;
    char line[STR_LEN + 1];

    int r = read_line(line, STR_LEN + 1);
    if (r == 0)
    {
        return ERR;
    }


    char arr[STR_LEN+1][WORD_LEN+1], ans[STR_LEN+1][WORD_LEN+1];

    split(arr, &n, line);
    fill_arr(arr, ans, n, &m);

    if (m == 0)
    {
        return ERR;
    }

    printf("Result: ");
    output(ans, m);

    return 0;
}
