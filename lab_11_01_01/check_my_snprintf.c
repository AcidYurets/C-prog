#include "my_snprintf.h"
#include "errors.h"
#include <string.h>

int check_my_snprintf()
{
    int err = 0;

    {
        char buffer1[100], buffer2[100];

        char c = '}';

        int rc1 = my_snprintf(buffer1, 8, "ab{a%cba", c);
        int rc2 = snprintf(buffer2, 8, "ab{a%cba", c);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        char c = '}';

        int rc1 = my_snprintf(buffer1, 10, "%c", c);
        int rc2 = snprintf(buffer2, 10, "%c", c);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        char s[] = "string";

        int rc1 = my_snprintf(buffer1, 20, "str: %s", s);
        int rc2 = snprintf(buffer2, 20, "str: %s", s);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        char s[] = "string";

        int rc1 = my_snprintf(buffer1, 10, "str: %s", s);
        int rc2 = snprintf(buffer2, 10, "str: %s", s);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        int x = 154;

        int rc1 = my_snprintf(buffer1, 10, "int: %d", x);
        int rc2 = snprintf(buffer2, 10, "int: %d", x);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        int x = -154;

        int rc1 = my_snprintf(buffer1, 8, "int: %d", x);
        int rc2 = snprintf(buffer2, 8, "int: %d", x);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        int x = 0;

        int rc1 = my_snprintf(buffer1, 10, "int: %d", x);
        int rc2 = snprintf(buffer2, 10, "int: %d", x);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        int x = 154;

        int rc1 = my_snprintf(buffer1, 20, "int16: %x", x);
        int rc2 = snprintf(buffer2, 20, "int16: %x", x);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        int x = 142;

        int rc1 = my_snprintf(buffer1, 25, "int16: %x", x);
        int rc2 = snprintf(buffer2, 25, "int16: %x", x);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        int x = -1;

        int rc1 = my_snprintf(buffer1, 25, "int16: %x", x);
        int rc2 = snprintf(buffer2, 25, "int16: %x", x);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }

    {
        char buffer1[100], buffer2[100];

        int x = -2100745800;

        int rc1 = my_snprintf(buffer1, 25, "int16: %x", x);
        int rc2 = snprintf(buffer2, 25, "int16: %x", x);

        int ch = 0;
        for (int i = 0; i < strlen(buffer1) || i < strlen(buffer2); i++)
        {
            if (buffer1[i] != buffer2[i])
            {
                ch++;
            }
        }
        if (ch != 0 || rc1 != rc2)
        {
            err++;
        }
    }
    
    return err;
}