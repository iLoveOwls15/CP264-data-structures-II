/*
 -------------------------------------
 File:    common_queue_stack.h
 Project: a9
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */
#ifndef COMMON_QUEUE_STACK_H_
#define COMMON_QUEUE_STACK_H_

#include <stdbool.h>

typedef struct node {
	char *data;
	struct node *next;
} Node;

typedef struct {
	Node *front;
	Node *rear;
	int size;
} Queue;

typedef struct {
	Node *top;
	int size;
} Stack;

// Queue functions
Queue* createQueue();
void enqueue(Queue *q, char *data);
char* dequeue(Queue *q);
bool isQueueEmpty(Queue *q);
void deleteQueue(Queue *q);

// Stack functions
Stack* createStack();
void push(Stack *s, char *data);
char* pop(Stack *s);
char* peek(Stack *s);
bool isStackEmpty(Stack *s);
void deleteStack(Stack *s);

#endif // COMMON_QUEUE_STACK_H
