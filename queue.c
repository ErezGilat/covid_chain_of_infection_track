/****************
 * Erez Gilat
 ***************/


#include <stdlib.h>
#include "queue.h"
#include <stdio.h>


//the function creates a queue
Queue * createQueue()
{

    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear=NULL;
    return q;
}

//the function gets a q and if its empty it will return 1 otherwise it will return 0
int isEmpty(Queue* q)
{
    if (q->front==NULL)
        return 1;
    return 0;
}

//the function gets a queue of Trin_Ari and a pointer to a tree(k) and it adds k to the queue.
int enQueue(Queue* q, Trin_Ari * k)
{
    //creat new node
    QNode * node=(QNode *)malloc(sizeof(QNode));
    if(node==NULL){free(node);printf("Malloc Failed!\n");return 0;}
    node->key=k;
    node->next=NULL;
    if (q->rear!=NULL)
        q->rear->next=node;
    q->rear=node;
    if(q->front==NULL)
        q->front=node;
    return 1;
}

//the function gets a queue (q) and takes out the first item from the queue and returns it
Trin_Ari * deQueue(Queue* q)
{
    if (q->front==NULL)
        return NULL;
    QNode *temp=q->front;
    Trin_Ari * frontTree=temp->key;
    q->front=q->front->next;
    if(q->front==NULL)
        q->rear=NULL;
    free(temp);
    temp=NULL;
    return frontTree;
}

//the function gets a queue and destroy if , it also free all of the keys in it .
void destroyQueue(Queue* q)
{
    QNode * pointer = q->front,*temp;
    while (pointer!=NULL)
    {
        temp=pointer->next;
        free(pointer);
        pointer=temp;
    }
    free(q);
    q=NULL;
}
