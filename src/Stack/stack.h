#ifndef INCLUDED_STACK_H
#define INCLUDED_STACK_H

#include <stdint.h>

#define MAX_DEPTH 32

struct _stack {
    uint32_t size;
    int32_t top;
    float data[MAX_DEPTH];
};

typedef struct _stack Stack;

/* Status codes */
#define RESULT_INVALID 0
#define STACK_OK       1
#define STACK_FULL     2
#define STACK_EMPTY    4

struct _stack_result {
    float data;
    uint32_t status;
};

typedef struct _stack_result StackResult;

/* Stack ADT interface */

Stack *stack_new(uint32_t size);

uint32_t stack_full(const Stack *stk);

uint32_t stack_empty(const Stack *stk);

Stack *stack_push(Stack *stk, float data, StackResult *result);

Stack *stack_pop(Stack *stk, StackResult *result);

Stack *stack_peek(const Stack *stk, StackResult *result);

#endif
