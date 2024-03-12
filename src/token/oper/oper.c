#include "oper.h"

#include <stdlib.h>

int my_add(int a, int b, int *err)
{
    *err = 0;
    return a + b;
}

int my_sub(int a, int b, int *err)
{
    *err = 0;
    return a - b;
}

int my_mul(int a, int b, int *err)
{
    *err = 0;
    return a * b;
}

int my_div(int a, int b, int *err)
{
    if (b != 0)
        return a / b;

    *err = 3;
    return -1;
}

int my_mod(int a, int b, int *err)
{
    if (b != 0)
        return a % b;

    *err = 3;
    return -1;
}

static int pow_rec(int a, int b)
{
    if (b == 0)
        return 1;

    int tmp = pow_rec(a, b / 2);

    if (b % 2 == 0)
        return tmp * tmp;

    return tmp * tmp * a;
}

int my_pow(int a, int b, int *err)
{
    if (b >= 0)
        return pow_rec(a, b);

    *err = 3;
    return -1;
}

struct oper oper_init(char c, int rpn, int *err)
{
    switch (c)
    {
    case '+': {
        struct oper op = { .prec = 1, .ass = LEFT, .func = my_add };
        return op;
    }
    case '-': {
        struct oper op = { .prec = 1, .ass = LEFT, .func = my_sub };
        return op;
    }
    case '*': {
        struct oper op2 = { .prec = 2, .ass = LEFT, .func = my_mul };
        return op2;
    }
    case '/': {
        struct oper op = { .prec = 2, .ass = LEFT, .func = my_div };
        return op;
    }
    case '%': {
        struct oper op = { .prec = 2, .ass = LEFT, .func = my_mod };
        return op;
    }
    case '^': {
        struct oper op = { .prec = 3, .ass = RIGHT, .func = my_pow };
        return op;
    }
    default: {
        if (c == '(' && !rpn)
        {
            struct oper op = { .prec = 0, .ass = OPEN, .func = NULL };
            return op;
        }
        else if (c == ')' && !rpn)
        {
            struct oper op = { .prec = 4, .ass = CLOSE, .func = NULL };
            return op;
        }

        *err = 1;
        struct oper op = { .prec = -1, .ass = CLOSE, .func = NULL };
        return op;
    }
    }
}
