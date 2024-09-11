/*
 -------------------------------------
 File:    common_queue_stack.c
 Project: a9
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */

#include "common_queue_stack.h"
#include <stdlib.h>
#include <string.h>

// Queue Implementations
Queue* createQueue() {
	Queue *q = (Queue*) malloc(sizeof(Queue));
	q->front = q->rear = NULL;
	q->size = 0;
	return q;
}

void enqueue(Queue *q, char *data) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->data = strdup(data);  // Make a copy of the data
	newNode->next = NULL;
	if (q->rear == NULL) {
		q->front = q->rear = newNode;
	} else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
	q->size++;
}

char* dequeue(Queue *q) {
	if (q->front == NULL) {
		return NULL;
	}
	Node *temp = q->front;
	char *data = temp->data;
	q->front = q->front->next;
	if (q->front == NULL) {
		q->rear = NULL;
	}
	free(temp);
	q->size--;
	return data;
}

bool isQueueEmpty(Queue *q) {
	return q->size == 0;
}

void deleteQueue(Queue *q) {
	while (!isQueueEmpty(q)) {
		free(dequeue(q));  // Dequeue frees the node, here we free the data
	}
	free(q);
}

// Stack Implementations
Stack* createStack() {
	Stack *s = (Stack*) malloc(sizeof(Stack));
	s->top = NULL;
	s->size = 0;
	return s;
}

void push(Stack *s, char *data) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->data = strdup(data);  // Make a copy of the data
	newNode->next = s->top;
	s->top = newNode;
	s->size++;
}

char* pop(Stack *s) {
	if (s->top == NULL) {
		return NULL;
	}
	Node *temp = s->top;
	char *data = temp->data;
	s->top = s->top->next;
	free(temp);
	s->size--;
	return data;
}

char* peek(Stack *s) {
	if (s->top == NULL) {
		return NULL;
	}
	return s->top->data;
}

bool isStackEmpty(Stack *s) {
	return s->size == 0;
}

void deleteStack(Stack *s) {
	while (!isStackEmpty(s)) {
		free(pop(s));  // Pop frees the node, here we free the data
	}
	free(s);
}
