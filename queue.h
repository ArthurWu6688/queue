//
// Created by 93539 on 2023/4/23.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define Queue_ElemType char
#define QUEUE_DEFAULT_SIZE 8

///////////////////////////////////////////////////////////////////
////顺序队列
typedef struct SeqQueue {
    Queue_ElemType *base;
    size_t capacity;
    int front;
    int rear;
} SeqQueue;

//函数声明
void SeqQueueInit(SeqQueue *psq);

void SeqQueuePush(SeqQueue *psq, Queue_ElemType value);

void SeqQueuePop(SeqQueue *psq);

bool SeqQueueFull(SeqQueue psq);

bool SeqQueueEmpty(SeqQueue psq);

void SeqQueueShow(SeqQueue psq);

Queue_ElemType SeqQueueFront(SeqQueue psq);

Queue_ElemType SeqQueueRear(SeqQueue psq);

void SeqQueueDesTroy(SeqQueue *psq);

//函数实现
void SeqQueueInit(SeqQueue *psq) {
    assert(psq != NULL);
    psq->base = (Queue_ElemType *) malloc(sizeof(Queue_ElemType) * QUEUE_DEFAULT_SIZE);
    assert(psq->base != NULL);
    psq->capacity = QUEUE_DEFAULT_SIZE;
    psq->front = psq->rear = 0;
}

bool SeqQueueFull(SeqQueue psq) {
    return psq.rear >= psq.capacity;
}

bool SeqQueueEmpty(SeqQueue psq) {
    return psq.front == psq.rear;
}

void SeqQueuePush(SeqQueue *psq, Queue_ElemType value) {
    assert(psq != NULL);
    if (SeqQueueFull(*psq)) {
        printf("队列已满，元素无法入队\n");
        return;
    } else
        psq->base[psq->rear++] = value;
}

void SeqQueueShow(SeqQueue psq) {
    for (int i = psq.front; i < psq.rear; ++i)
        printf("%c ", psq.base[i]);
    printf("\n");
}

void SeqQueuePop(SeqQueue *psq) {
    assert(psq != NULL);
    if (SeqQueueEmpty(*psq)) {
        printf("队列已空，没有元素可以出队\n");
        return;
    }
    ++psq->front;
}

Queue_ElemType SeqQueueFront(SeqQueue psq) {
    assert(!SeqQueueEmpty(psq));
    return psq.base[psq.front];
}

Queue_ElemType SeqQueueRear(SeqQueue psq) {
    assert(!SeqQueueEmpty(psq));
    return psq.base[psq.rear - 1];
}

void SeqQueueDesTroy(SeqQueue *psq) {
    assert(psq != NULL);
    free(psq->base);
    psq->base = NULL;
    psq->capacity = psq->front = psq->rear = 0;
}

#endif //QUEUE_QUEUE_H
