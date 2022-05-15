/****************
 * Erez Gilat
 ***************/


#ifndef EX6_QUEUE_H
#define EX6_QUEUE_H

#include "ex6.h"

// A linked list (LL) node to store a queue entry
typedef struct QNode {
    Trin_Ari* key;
    struct QNode* next;
}QNode;

// The queue, front stores the front node of LL and rear stores the
// last node of LL
typedef struct Queue {
    struct QNode *front;
    struct QNode *rear;
}Queue;

//creating the queue
Queue * createQueue();
//q - the queue, k- the key (element)
int enQueue(Queue* q, Trin_Ari * k);
Trin_Ari * deQueue(Queue* q);
// return 1 if empty and zero if not empty
int isEmpty(Queue* q);
//free the queue
void destroyQueue(Queue* q);


#endif //EX6_QUEUE_H
