#include <assert.h>
#include <stdlib.h>
#include "stack.h"

/*
 * We deal with small size stack data structure.
 * Stack object are passed to function by reference,
 * which is more efficient than passing them by value.
 */

Stack *stack_new(uint32_t size)
{
    size = (size > 0 && size < MAX_DEPTH) ? size : MAX_DEPTH;

    Stack *s = malloc(sizeof(Stack));

    assert(s != NULL);

    s->size = size;
    s->top = -1;

    return s;
}

uint32_t stack_full(const Stack *stk)
{
    assert(stk != NULL);

    return ((stk->top + 1) == stk->size);
}

uint32_t stack_empty(const Stack *stk)
{
    assert(stk != NULL);

    return (stk->top == -1);
}

Stack *stack_push(Stack *stk, float data, StackResult *result)
{
    assert(stk != NULL);

    if ((stk->top + 1) < stk->size)
    {
        stk->data[++stk->top] = data;

        result->data = data;
        result->status = STACK_OK;
    }
    else
    {
        result->data = data;
        result->status = STACK_FULL;
    }

    return stk;
}

Stack *stack_pop(Stack *stk, StackResult *result)
{
    assert(stk != NULL);

    if (stk->top > -1)
    {
        result->data = stk->data[stk->top];
        result->status = STACK_OK;

        --stk->top;
    }
    else
    {
        result->status = STACK_EMPTY;
    }

    return stk;
}

Stack *stack_peek(const Stack *stk, StackResult *result)
{
    assert(stk != NULL);

    if (stk->top > -1)
    {
        result->data = stk->data[stk->top];
        result->status = STACK_OK;
    }
    else
    {
        result->status = STACK_EMPTY;
    }

    return (Stack *)stk;
}
