#include "lab_04.h"


int main()
{
    char line[STR_LEN + 1];

    int r = read_line(line, STR_LEN + 2);
    if (r == 0)
    {
        printf("NO");
        return 0;
    }
    
    if (r > STR_LEN)
    {
        return ERR;
    }

    char num[STR_LEN + 1];
    if (check_input(line, num))
    {
        printf("NO");
        return 0;
    }

    int ans = check_num(num);

    if (ans)
        printf("YES");
    else
        printf("NO");

    return 0;
}
