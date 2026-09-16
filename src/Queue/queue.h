#ifndef INCLUDED_QUEUE_H
#define INCLUDED_QUEUE_H

#include <stdint.h>

#define MAX_QUEUE_LEN 32

struct _queue {
    uint32_t size;
    uint32_t count;
    uint32_t head;
    uint32_t tail;
    int32_t q[MAX_QUEUE_LEN];
};

typedef struct _queue Queue;

#define QUEUE_OK    1
#define QUEUE_FULL  2
#define QUEUE_EMPTY 4

struct _queue_result {
    int32_t data;
    uint32_t status;
};

typedef struct _queue_result QueueResult;

/* Queue ADT interface */

Queue *queue_new(uint32_t size);

uint32_t queue_full(const Queue *q);

uint32_t queue_empty(const Queue *q);

Queue *queue_add(Queue *q, int32_t data, QueueResult *result);

Queue *queue_remove(Queue *q, QueueResult *result);

#endif
