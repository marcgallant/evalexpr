#ifndef TOKEN_H
#define TOKEN_H

#include "oper/oper.h"

union value
{
    int num;
    struct oper oper;
};

enum tag
{
    NUM,
    OPER
};

struct token
{
    enum tag t;
    union value data;
};

/**
 * \brief Initialize a number token on the heap
 *
 * \param elt Value of the token
 * \return The allocated token
 */
struct token*token_num_init(int elt);

/**
 * \brief Initialize a operator token on the heap
 *
 * \param c Character representing the operator
 * \param rpn Boolean describing the expression type
 * \param err Error parameter set to 1 on lexing error
 * \return The allocated token
 */
struct token *token_oper_init(char c, int rpn, int *err);

#endif /* ! TOKEN_H */
