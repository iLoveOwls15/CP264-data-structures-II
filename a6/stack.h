/*
 -------------------------------------
 File:    stack.h
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
#ifndef STACK_H
#define STACK_H
#include "common.h"

typedef struct stack {
  int length;
  NODE *top;
} STACK;

void push(STACK *sp, NODE *np);
NODE *pop(STACK *sp);
void clean_stack(STACK *sp);

#endif
