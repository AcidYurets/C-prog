#include "my_snprintf.h"
#include "errors.h"

int calculate_len_of_number(long long int num)
{
    int count = 0;
    while (num != 0)
    {
        count++;
        num /= NOTATION_10_BASE;
    }
    return count;
}

int calculate_len_of_number_16(long long num)
{
    int count = 0;
    while (num != 0)
    {
        count++;
        num /= NOTATION_16_BASE;
    }
    return count;
}

void int_to_str(char *s, long long int num) 
{
    if (num == 0)
    {
        s[0] = '0';
        s[1] = '\0';
    }
    else if (num < 0)
    {
        num *= -1;
        int len = calculate_len_of_number(num) + 1;
        s[len] = '\0';

        while (len >= 0)
        {
            s[--len] = num % NOTATION_10_BASE + '0';
            num /= NOTATION_10_BASE;
        }
        s[0] = '-';
    }
    else
    {
        int len = calculate_len_of_number(num);
        s[len] = '\0';

        while (len >= 0)
        {
            s[--len] = num % NOTATION_10_BASE + '0';
            num /= NOTATION_10_BASE;
        }
    }
}

void int_to_str_16(char *s, long long num) 
{
    char b[17] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    if (num == 0)
    {
        s[0] = '0';
        s[1] = '\0';
    }
    else
    {
        if (num < 0)
            num = (long long) 2 * INT_MAX + num + 2;
        int len = calculate_len_of_number_16(num);
        s[len] = '\0';

        while (len >= 0)
        {
            s[--len] = b[num % NOTATION_16_BASE];
            num /= NOTATION_16_BASE;
        }
    }
}

void operate_s(char *str, char *buffer, int *k, int n, int *write)
{ 
    for (int j = 0; str[j] != '\0'; j++)
    {
        if (*write && *k >= n)
        {
            *write = 0;
            buffer[*k] = '\0';
        }
        else if (*write && *k < n)
        {
            buffer[*k] = str[j];
        }
        (*k)++;
    }
}

void operate_c(char c, char *buffer, int *k, int *write)
{ 
    if (*write)
    {
        buffer[*k] = c;
    }
    (*k)++;
}

int my_snprintf(char *buffer, size_t n, const char *format, ...)
{
    va_list vl;
    int k = 0;
    int write = 1;
    n--;

    va_start(vl, format);

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (write && k >= n)
        {
            write = 0;
            buffer[k] = '\0';
        }
        else if (write && n == -1)
        {
            write = 0;
        }

        if (format[i] == '%')
        {
            i++;
            if (format[i] == 's')
            {
                char *str = va_arg(vl, char *);
                operate_s(str, buffer, &k, n, &write);
            }
            else if (format[i] == 'd')
            {
                int num = va_arg(vl, int);
                char str[INT_LEN];
                int_to_str(str, num);
                operate_s(str, buffer, &k, n, &write);
            }
            else if (format[i] == 'x')
            {
                long long num = va_arg(vl, long long);
                char str[INT_LEN];
                int_to_str_16(str, num);
                operate_s(str, buffer, &k, n, &write);
            }
            else if (format[i] == 'c')
            {
                char c = va_arg(vl, int);
                operate_c(c, buffer, &k, &write);
            }
        }
        else
        {
            if (write)
            {
                buffer[k] = format[i];
            }
            k++;
        }
    }

    if (write)
        buffer[k] = '\0';

    va_end(vl);
    
    return k;
}
