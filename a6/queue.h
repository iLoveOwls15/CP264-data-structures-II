/*
 -------------------------------------
 File:    queue.h
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

#ifndef QUEUE_H
#define QUEUE_H
#include "common.h"

typedef struct queue {
  int length;
  NODE *front;
  NODE *rear;
} QUEUE;

void enqueue(QUEUE *qp, NODE *np);
NODE *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

#endif
