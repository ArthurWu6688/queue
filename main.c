#include "queue.h"

int main(){
    LinkQueue Q;
    LinkQueueInit(&Q);
    LinkQueuePush(&Q,'A');
    LinkQueuePush(&Q,'B');
    LinkQueuePush(&Q,'C');
    LinkQueuePush(&Q,'D');
    LinkQueuePush(&Q,'E');
    LinkQueueShow(Q);
    printf("front:%c\n", LinkQueueFront(Q));
    printf("Rear:%c\n", LinkQueueRear(Q));
    printf("----------------------------------------\n");


    LinkQueuePop(&Q);
    LinkQueueShow(Q);
    printf("front:%c\n", LinkQueueFront(Q));
    printf("Rear:%c\n", LinkQueueRear(Q));
    printf("----------------------------------------\n");


    LinkQueueDestroy(&Q);

    return 0;
}

#if 0
循环队列测试代码
int main(){
    CircleQueue Q;
    CircleQueueInit(&Q);
    CircleQueuePush(&Q,'A');
    CircleQueuePush(&Q,'B');
    CircleQueuePush(&Q,'C');
    CircleQueuePush(&Q,'D');
    CircleQueuePush(&Q,'E');
    CircleQueuePush(&Q,'F');
    CircleQueuePush(&Q,'G');
    CircleQueuePush(&Q,'H');
    CircleQueueShow(Q);
    printf("--------------------------------------------\n");
    CircleQueuePop(&Q);
    CircleQueuePop(&Q);
    CircleQueueShow(Q);
    printf("--------------------------------------------\n");
    CircleQueuePush(&Q,'X');
    CircleQueuePush(&Q,'Y');
    CircleQueueShow(Q);
    printf("front = %c\n", CircleQueueFront(Q));
    printf("rear = %c\n", CircleQueueRear(Q));

    CircleQueueDestroy(&Q);

    return 0;
}
#endif


#if 0
顺序队列的测试代码
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
#endif