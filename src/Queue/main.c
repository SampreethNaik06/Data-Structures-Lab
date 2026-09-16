#include <assert.h>
#include <stdio.h>
#include "queue.h"

int main()
{
    Queue *q;
    QueueResult result;

    /* Create queue of size 3 */
    q = queue_new(3);

    assert(q != NULL);

    /* Initially queue should be empty */
    assert(queue_empty(q));
    assert(!queue_full(q));

    /* Add 10 */
    queue_add(q, 10, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 10);

    /* Add 20 */
    queue_add(q, 20, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 20);

    /* Add 30 */
    queue_add(q, 30, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 30);

    /* Queue should now be full */
    assert(queue_full(q));
    assert(!queue_empty(q));

    /* Try to add when queue is full */
    queue_add(q, 40, &result);

    assert(result.status == QUEUE_FULL);

    /* Remove 10 */
    queue_remove(q, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 10);

    /* Remove 20 */
    queue_remove(q, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 20);

    /* Remove 30 */
    queue_remove(q, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 30);

    /* Queue should now be empty */
    assert(queue_empty(q));
    assert(!queue_full(q));

    /* Try to remove from empty queue */
    queue_remove(q, &result);

    assert(result.status == QUEUE_EMPTY);

    printf("All queue assertions passed!\n");

    return 0;
}
