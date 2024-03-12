#include "token.h"

#include <stdlib.h>

struct token *token_num_init(int elt)
{
    struct token *token = malloc(sizeof(struct token));

    union value v;
    v.num = elt;

    token->t = NUM;
    token->data = v;

    return token;
}

struct token *token_oper_init(char c, int rpn, int *err)
{
    struct token *token = malloc(sizeof(struct token));

    union value v;
    v.oper = oper_init(c, rpn, err);

    token->t = OPER;
    token->data = v;

    return token;
}
