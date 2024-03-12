#ifndef EVALEXPR_H
#define EVALEXPR_H

#include "queue/queue.h"

/**
 * \brief Evaluate the RPN expression in queue
 *
 * \param rpn The queue representing the RPN expression
 * \param err Error parameter set at 2 on syntax error or 3 on arithmetic error
 * \return The result of the expression
 */
int evaluation(struct queue *rpn, int *err);

/**
 * \brief Parse the infix expression to RPN expression
 *
 * \param infix The queue representing the RPN expression
 * \param err Error parameter set at 2 on syntax error
 * \return The RPN expression as a queue
 */
struct queue *parser(struct queue *infix, int *err);

/**
 * \brief Lex the expression into a queue of operation or number tokens
 *
 * \param str The input expression
 * \param rpn Boolean describing the expression type
 * \param err Error parameter set at 1 on lexical error
 * \return The expression as a queue
 */
struct queue *lexer(char *str, int rpn, int *err);

#endif /* ! EVALEXPR_H */
