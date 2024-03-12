#include "evalexpr.h"

#include <ctype.h>
#include <stdlib.h>

#include "queue/queue.h"
#include "stack/stack.h"

int evaluation(struct queue *rpn, int *err)
{
    struct stack *stack = stack_init();

    while (rpn->head)
    {
        struct token *token = queue_pop(rpn);

        if (token->t == NUM)
            stack_push(stack, token);
        else
        {
            struct token *a = stack_pop(stack);
            struct token *b = stack_pop(stack);

            if (a && b)
            {
                int elt = token->data.oper.func(b->data.num, a->data.num, err);
                struct token *res = token_num_init(elt);
                stack_push(stack, res);
            }
            else
                *err = 2;

            free(a);
            free(b);
            free(token);

            if (*err != 0)
            {
                stack_destroy(stack);
                return -1;
            }
        }
    }

    int res = -1;
    if (stack->size == 1)
    {
        struct token *token = stack_pop(stack);
        res = token->data.num;
        free(token);
    }
    else
        *err = 2;

    stack_destroy(stack);
    return res;
}

int is_superior(struct oper o1, struct oper o2)
{
    switch (o1.ass)
    {
    case LEFT:
        return o1.prec <= o2.prec;
    case RIGHT:
        return o1.prec < o2.prec;
    default:
        return 0;
    }
}

struct queue *parser(struct queue *infix, int *err)
{
    struct queue *rpn = queue_init();
    struct stack *stack = stack_init();

    while (infix->head)
    {
        struct token *token = queue_pop(infix);

        if (token->t == NUM)
            queue_push(rpn, token);
        else
        {
            if (token->data.oper.ass == CLOSE)
            {
                while (stack->peek && stack->peek->data->data.oper.ass != OPEN)
                {
                    queue_push(rpn, stack_pop(stack));
                }

                if (stack->peek && stack->peek->data->data.oper.ass == OPEN)
                {
                    free(stack_pop(stack));
                    free(token);
                }
                else
                {
                    *err = 2;
                    free(token);
                    stack_destroy(stack);
                    return rpn;
                }
            }
            else
            {
                while (stack->peek
                       && is_superior(token->data.oper,
                                      stack->peek->data->data.oper))
                {
                    queue_push(rpn, stack_pop(stack));
                }
                stack_push(stack, token);
            }
        }
    }

    while (stack->peek)
    {
        if (stack->peek->data->data.oper.ass == OPEN)
        {
            *err = 2;
            stack_destroy(stack);
            return rpn;
        }
        queue_push(rpn, stack_pop(stack));
    }

    stack_destroy(stack);

    return rpn;
}

struct queue *lexer(char *str, int rpn, int *err)
{
    struct queue *infix = queue_init();

    size_t i = 0;
    while (str[i] != '\0')
    {
        int tmp = 0;
        while (str[i] != '\0' && isdigit(str[i]))
        {
            tmp *= 10;
            tmp += atoi(&str[i]);
            i++;
        }

        if (tmp != 0)
        {
            struct token *token = token_num_init(tmp);
            queue_push(infix, token);
        }

        if (!isspace(str[i]))
        {
            struct token *token = token_oper_init(str[i], rpn, err);
            queue_push(infix, token);

            if (*err != 0)
                return infix;
        }

        i++;
    }

    return infix;
}
