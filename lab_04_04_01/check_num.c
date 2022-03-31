#include "lab_04.h"


int is_digit(char a)
{
    return a >= '0' && a <= '9';
}


char *get_number_end(char *number_begin)
{
    while (is_digit(*number_begin))
        number_begin++;

    return number_begin;
}


int check_num(char *str)
{
    int result = 1;

    if (*str == '+' || *str == '-')
        str++;

    if (*str == '.')
    {
        str++;
        char *number_end = get_number_end(str);

        if (number_end - str > 0)
        {
            str = number_end;
        }
        else
        {
            result = 0;
        }
    }
    else if (is_digit(*str))
    {
        str = get_number_end(str);
 
        if (*str == '.')
        {
            str++;
            str = get_number_end(str);
        }
    }
    else
    {
        result = 0;
    }

    if (result && (*str == 'e' || *str == 'E'))
    {
        str++;

        if (*str == '+' || *str == '-')
            str++;

        char *number_end = get_number_end(str);

        if (number_end - str > 0)
        {
            str = number_end;
        }
        else
        {
            result = 0;
        }
    }

    result = result && *str == '\0';

    return result;
}
