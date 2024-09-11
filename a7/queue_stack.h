/*
 -------------------------------------
 File:    queue_stack.h
 Project: a07
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-09
 -------------------------------------
 */

#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H

typedef struct node {
	void *data;
	struct node *next;
} NODE;

typedef struct queue {
	NODE *front, *rear;
} QUEUE;

void enqueue(QUEUE *qp, void *data);
void *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

typedef struct stack {
	NODE *top;
} STACK;

void push(STACK *sp, void *data);
void *pop(STACK *sp);
void clean_stack(STACK *sp);

#endif
