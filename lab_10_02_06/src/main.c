#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/errors.h"
#include "../inc/types.h"
#include "../inc/input.h"
#include "../inc/list_operations.h"
#include "../inc/matrix_operations.h"
#include "../inc/check.h"

int operate_out();
int operate_add_mul(char *str);
int operate_lin();

int main()
{
    int ret = OK;

    char str[MAX_OPERATION_LEN];
    scanf("%5s", str);
    if (strcmp(str, "out") == 0)
    {
        ret = operate_out();
    }
    else if (strcmp(str, "add") == 0 || strcmp(str, "mul") == 0)
    {
        ret = operate_add_mul(str);
    }
    else if (strcmp(str, "lin") == 0)
    {
        ret = operate_lin();
    }
    else
    {
        ret = WRONG_INPUT;
    }

    return ret;
}


int operate_out()
{
    int ret = OK;

    node_t *head = NULL;
    head = read_list(head);
    if (head)
    {
        ret = show_list(head);

        free_list(head);
    }
    else
        ret = READ_ERR;

    return ret;
}

int operate_add_mul(char *str)
{
    int ret = OK;

    node_t *head_a = NULL, *head_b = NULL, *res = NULL;
    head_a = read_list(head_a);
    if (head_a == NULL)
        ret = READ_ERR;
    else
        head_b = read_list(head_b);
    if (head_a && head_b)
    {
        if (strcmp(str, "add") == 0)
            res = add(head_a, head_b, res);
        else if (strcmp(str, "mul") == 0)
            res = mul(head_a, head_b, res);

        ret = show_list(res);

        free_list(head_a);
        free_list(head_b);
        free_list(res);
    }
    else
    {
        free_list(head_a);
        free_list(head_b);
        ret = READ_ERR;
    }

    return ret;
}

int operate_lin()
{
    int ret = OK;

    node_t *head = NULL, *res = NULL;
    head = read_list(head);
    if (head)
    {
        res = lin(head, res);
        if (res == NULL)
        {
            ret = READ_ERR;
        }
        else
        {
            ret = show_list(res);
        }
        free_list(head);
        free_list(res);
    }
    else
        ret = READ_ERR;

    return ret;
}
