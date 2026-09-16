#include <assert.h>
#include <stdio.h>
#include "stack.h"

int main()
{
    Stack *stk;
    StackResult result;

    /* Create stack of size 3 */
    stk = stack_new(3);

    assert(stk != NULL);

    /* Initially stack should be empty */
    assert(stack_empty(stk));
    assert(!stack_full(stk));

    /* Push 10 */
    stack_push(stk, 10, &result);

    assert(result.status == STACK_OK);
    assert(result.data == 10);
    assert(!stack_empty(stk));

    /* Peek should give 10 */
    stack_peek(stk, &result);

    assert(result.status == STACK_OK);
    assert(result.data == 10);

    /* Push 20 */
    stack_push(stk, 20, &result);

    assert(result.status == STACK_OK);
    assert(result.data == 20);

    /* Push 30 */
    stack_push(stk, 30, &result);

    assert(result.status == STACK_OK);
    assert(result.data == 30);

    /* Stack should now be full */
    assert(stack_full(stk));
    assert(!stack_empty(stk));

    /* Try to push when stack is full */
    stack_push(stk, 40, &result);

    assert(result.status == STACK_FULL);

    /* Peek should still give 30 */
    stack_peek(stk, &result);

    assert(result.status == STACK_OK);
    assert(result.data == 30);

    /* Pop 30 */
    stack_pop(stk, &result);

    assert(result.status == STACK_OK);
    assert(result.data == 30);

    /* Pop 20 */
    stack_pop(stk, &result);

    assert(result.status == STACK_OK);
    assert(result.data == 20);

    /* Pop 10 */
    stack_pop(stk, &result);

    assert(result.status == STACK_OK);
    assert(result.data == 10);

    /* Stack should now be empty */
    assert(stack_empty(stk));
    assert(!stack_full(stk));

    /* Try to pop from empty stack */
    stack_pop(stk, &result);

    assert(result.status == STACK_EMPTY);

    printf("All stack assertions passed!\n");

    return 0;
}
