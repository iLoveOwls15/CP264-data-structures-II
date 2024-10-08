/*
 -------------------------------------
 File:    common.h
 Project: a05
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-02
 -------------------------------------
 */
#ifndef COMMON_H
#define COMMON_H

/*
 Node structure of linked list queue and stack for postfix expression operations
 int data - represent operand, operator, or parenthesis according to the type
 int type - 0:operand; 1:operator; 2:left parenthesis 3:right parenthesis
 */
typedef struct node {
	int data;
	int type;
	struct node *next;
} NODE;

NODE *new_node(int data, int type);
void clean(NODE **npp);
void display(NODE *np);
int get_type(char c);
int get_priority(char op);

#endif
