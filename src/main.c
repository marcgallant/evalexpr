#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "evalexpr.h"

int main(int argc, char *argv[])
{
    int rpn = 0;
    if (argc == 2)
    {
        if (strcmp(argv[1], "-rpn"))
            return 4;
        rpn = 1;
    }

    int err = 0;
    char buf[100] = { 0 };

    size_t size = fread(buf, sizeof(char), 1000, stdin);
    if (size == 0)
        return 0;

    struct queue *queue;
    if (!rpn)
    {
        struct queue *infix = lexer(buf, rpn, &err);
        if (err != 0)
        {
            queue_destroy(infix);
            return err;
        }

        queue = parser(infix, &err);
        queue_destroy(infix);
    }
    else
        queue = lexer(buf, rpn, &err);

    if (err != 0)
    {
        queue_destroy(queue);
        return err;
    }

    int res = evaluation(queue, &err);
    queue_destroy(queue);

    if (err != 0)
        return err;

    printf("%d\n", res);

    return 0;
}
