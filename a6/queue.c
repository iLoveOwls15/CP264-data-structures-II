/*
 -------------------------------------
 File:    queue.c
 Project: a05
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-02
 -------------------------------------
 */


/*
 * your program signature
 */

#include <stdio.h>
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
    np->next = NULL;
    if(qp->front){
        qp->rear->next = np;
        qp->rear = np;
    } else {
        qp->front = np;
        qp->rear = np;
    }
    qp->length++;
}

NODE *dequeue(QUEUE *qp) {
    NODE *p = qp->front;
    if(p){
        qp->front = p->next;
        p->next = NULL;
        if(!qp->front){
            qp->rear = NULL;
        }
        qp->length--;
    } else {
        printf("UNDERFLOW");
    }
    return p;
}

void clean_queue(QUEUE *qp) {
  clean(&(qp->front));
  qp->front = NULL;
  qp->rear = NULL;
  qp->length=0;
}
