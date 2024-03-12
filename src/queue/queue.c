#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

struct queue *queue_init(void)
{
    struct queue *res = calloc(1, sizeof(struct queue));
    return res;
}

void queue_destroy(struct queue *queue)
{
    while (queue->head)
    {
        struct list *tmp = queue->head;
        queue->head = queue->head->next;
        free(tmp->data);
        free(tmp);
    }
    free(queue);
}

void queue_push(struct queue *queue, struct token *elt)
{
    struct list *tmp = calloc(1, sizeof(struct list));

    tmp->data = elt;

    if (queue->size == 0)
        queue->head = tmp;
    else
        queue->tail->next = tmp;

    queue->tail = tmp;
    queue->size++;
}

struct token *queue_pop(struct queue *queue)
{
    struct list *tmp = queue->head;
    if (!tmp)
        return NULL;

    queue->size--;
    queue->head = queue->head->next;

    struct token *res = tmp->data;
    free(tmp);
    return res;
}