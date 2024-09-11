/*
 -------------------------------------
 File:    stack.c
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
#include "stack.h"

void push(STACK *sp, NODE *np) {
    np->next = sp->top;
    sp->top = np;
    sp->length++;
}

NODE *pop(STACK *sp) {
    NODE *p = sp->top;
    if(!p){
        printf("UNDERFLOW");
    } else {
        sp->top = p->next;
        p->next = NULL;
        sp->length--;
    }
    return p;
}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->length=0;
}
