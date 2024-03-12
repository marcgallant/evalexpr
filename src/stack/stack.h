#ifndef STACK_H
#define STACK_H

#include <stddef.h>

#include "list/list.h"

struct stack
{
    struct list *peek;
    size_t size;
};

/**
 * \brief Allocate a stack on the head
 *
 * \return The allocated stack
 */
struct stack *stack_init(void);

/**
 * \brief Push at the peek of the stack
 *
 * \param stack The stack to push into
 * \param elt The token to push
 */
void stack_push(struct stack *stack, struct token *elt);

/**
 * \brief Pop at the peek of the stack
 *
 * \param stack The stack to pop into
 * \return The popped element or NULL on empty stack
 */
struct token *stack_pop(struct stack *stack);

/**
 * \brief Destroy the stack
 *
 * Free all the elements contained and the stack itself
 *
 * \param stack The stack to destroy
 */
void stack_destroy(struct stack *stack);

#endif /* !STACK_H */
