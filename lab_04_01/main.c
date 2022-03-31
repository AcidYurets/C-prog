#include "lab_04_01.h"


int main()
{
    char str[STR_LEN + 1];
    
    read_line(str, STR_LEN + 1);

    if (!(my_strpbrk(str, " abcd") == strpbrk(str, " abcd")))
    {
        return ERR;
    }

    return 0;
}
