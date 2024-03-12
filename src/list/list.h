#ifndef LIST_H
#define LIST_H

#include "token/token.h"

struct list
{
    struct token *data;
    struct list *next;
};

#endif /* ! LIST_H */
