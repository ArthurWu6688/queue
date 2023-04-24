#include "queue.h"

int main(){
    SeqQueue Q;
    SeqQueueInit(&Q);
    SeqQueuePush(&Q,'A');
    SeqQueuePush(&Q,'B');
    SeqQueuePush(&Q,'C');
    SeqQueuePush(&Q,'D');
    SeqQueuePush(&Q,'E');
    SeqQueueShow(Q);
    printf("front %c\n", SeqQueueFront(Q));
    printf("rear %c\n", SeqQueueRear(Q));
    printf("------------------------\n");
    SeqQueuePop(&Q);
    SeqQueuePop(&Q);
    SeqQueueShow(Q);
    printf("front %c\n", SeqQueueFront(Q));
    printf("rear %c\n", SeqQueueRear(Q));

    SeqQueueDesTroy(&Q);

    return 0;
}