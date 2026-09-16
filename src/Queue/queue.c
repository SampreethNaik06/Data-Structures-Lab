#include <assert.h>
#include <stdlib.h>
#include "queue.h"

Queue *queue_new(uint32_t size)
{
    size = (size > 0 && size < MAX_QUEUE_LEN)
           ? size
           : MAX_QUEUE_LEN;

    Queue *q = malloc(sizeof(Queue));

    assert(q != NULL);

    q->size = size;
    q->count = 0;
    q->head = 0;
    q->tail = 0;

    return q;
}

uint32_t queue_full(const Queue *q)
{
    assert(q != NULL);

    return q->count == q->size;
}

uint32_t queue_empty(const Queue *q)
{
    assert(q != NULL);

    return q->count == 0;
}

Queue *queue_add(Queue *q, int32_t data, QueueResult *result)
{
    assert(q != NULL);
    assert(result != NULL);

    if (q->count < q->size)
    {
        q->q[q->tail] = data;

        q->tail = (q->tail + 1) % q->size;

        q->count++;

        result->data = data;
        result->status = QUEUE_OK;
    }
    else
    {
        result->data = data;
        result->status = QUEUE_FULL;
    }

    return q;
}

Queue *queue_remove(Queue *q, QueueResult *result)
{
    assert(q != NULL);
    assert(result != NULL);

    if (q->count > 0)
    {
        result->data = q->q[q->head];

        q->head = (q->head + 1) % q->size;

        q->count--;

        result->status = QUEUE_OK;
    }
    else
    {
        result->status = QUEUE_EMPTY;
    }

    return q;
}
