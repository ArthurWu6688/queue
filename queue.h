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

///////////////////////////////////////////////////////////////////
////循环队列
typedef struct CircleQueue {
    Queue_ElemType *base;
    size_t capacity;
    size_t front;
    size_t rear;
} CircleQueue;

//函数声明
void CircleQueueInit(CircleQueue *psq);

bool CircleQueueFull(CircleQueue psq);

bool CircleQueueEmpty(CircleQueue psq);

void CircleQueuePush(CircleQueue *psq, Queue_ElemType value);

void CircleQueuePop(CircleQueue *psq);

Queue_ElemType CircleQueueFront(CircleQueue psq);

Queue_ElemType CircleQueueRear(CircleQueue psq);

void CircleQueueDestroy(CircleQueue *psq);

//函数实现
void CircleQueueInit(CircleQueue *psq) {
    assert(psq != NULL);
    psq->base = (Queue_ElemType *) malloc(sizeof(Queue_ElemType) * (QUEUE_DEFAULT_SIZE + 1));
    assert(psq->base != NULL);
    psq->capacity = QUEUE_DEFAULT_SIZE;
    psq->front = psq->rear = 0;
}

bool CircleQueueFull(CircleQueue psq) {
    return psq.front == (psq.rear + 1) % (psq.capacity + 1);
}

bool CircleQueueEmpty(CircleQueue psq) {
    return psq.front == psq.rear;
}

void CircleQueuePush(CircleQueue *psq, Queue_ElemType value) {
    assert(psq != NULL);
    if (CircleQueueFull(*psq)) {
        printf("队列已满，元素无法入队\n");
        return;
    }
    psq->base[psq->rear] = value;
    psq->rear = (psq->rear + 1) % (psq->capacity + 1);
}

void CircleQueuePop(CircleQueue *psq) {
    assert(psq != NULL);
    if (CircleQueueEmpty(*psq)) {
        printf("队列已空，没有元素可以出队\n");
        return;
    }
    psq->front = (psq->front + 1) % (psq->capacity + 1);
}

void CircleQueueShow(CircleQueue psq) {
    for (size_t i = psq.front; i != psq.rear;) {
        printf("%c ", psq.base[i]);
        i = (i + 1) % (psq.capacity + 1);
    }
    printf("\n");
}

Queue_ElemType CircleQueueFront(CircleQueue psq) {
    if (!CircleQueueEmpty(psq))
        return psq.base[psq.front];
    return -1;
}

Queue_ElemType CircleQueueRear(CircleQueue psq) {
    if (!CircleQueueEmpty(psq))
        return psq.base[(psq.rear - 1 + psq.capacity + 1) % (psq.capacity + 1)];
    return -1;
}

void CircleQueueDestroy(CircleQueue *psq) {
    assert(psq != NULL);
    free(psq->base);
    psq->base = NULL;
    psq->rear = psq->front = psq->capacity = 0;
}

///////////////////////////////////////////////////////////////////
////链式队列
typedef struct LinkQueueNode {
    Queue_ElemType data;
    struct LinkQueueNode *next;
} LinkQueueNode;

typedef struct LinkQueue {
    LinkQueueNode *front;
    LinkQueueNode *rear;
} LinkQueue;

//函数声明
void LinkQueueInit(LinkQueue *psq);

void LinkQueuePush(LinkQueue *psq, Queue_ElemType value);

void LinkQueuePop(LinkQueue *psq);

void LinkQueueShow(LinkQueue psq);

void LinkQueueDestroy(LinkQueue *psq);

bool LinkQueueEmpty(LinkQueue psq);

Queue_ElemType LinkQueueFront(LinkQueue psq);

Queue_ElemType LinkQueueRear(LinkQueue psq);

//函数声明
void LinkQueueInit(LinkQueue *psq) {
    assert(psq != NULL);
    psq->front = psq->rear = NULL;
}

void LinkQueuePush(LinkQueue *psq, Queue_ElemType value) {
    assert(psq != NULL);
    LinkQueueNode *s = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    assert(s != NULL);
    s->data = value;
    s->next = NULL;
    if (psq->front == NULL) {
        psq->front = psq->rear = s;
    } else {
        psq->rear->next = s;
        psq->rear = s;
    }
}

void LinkQueuePop(LinkQueue *psq) {
    assert(psq != NULL);
    LinkQueueNode *p = psq->front;
    psq->front = p->next;
    free(p);
}

void LinkQueueShow(LinkQueue psq) {
    LinkQueueNode *p = psq.front;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

void LinkQueueDestroy(LinkQueue *psq) {
    assert(psq != NULL);
    while (psq->front != NULL) {
        LinkQueueNode *p = psq->front;
        psq->front = p->next;
        free(p);
    }
}

bool LinkQueueEmpty(LinkQueue psq) {
    return psq.front == NULL;
}

Queue_ElemType LinkQueueFront(LinkQueue psq){
    if(!LinkQueueEmpty(psq))
        return psq.front->data;
    return -1;
}

Queue_ElemType LinkQueueRear(LinkQueue psq){
    if(!LinkQueueEmpty(psq))
        return psq.rear->data;
    return -1;
}

#endif //QUEUE_QUEUE_H
