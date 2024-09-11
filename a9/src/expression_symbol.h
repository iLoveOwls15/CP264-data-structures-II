/*
 -------------------------------------
 File:    expression_symbol.h
 Project: a9
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */
#ifndef EXPRESSION_SYMBOL_H_
#define EXPRESSION_SYMBOL_H_

#include "hash.h"

typedef struct {
	char *expression;
} EXPRESSION;

/* Function to evaluate a symbolic infix expression and return the result. */
int evaluate_infix_symbol(HASHTABLE *ht, char *infixstr);

/* Function to convert an infix symbolic expression to postfix notation. */
char* infix_to_postfix_symbol(HASHTABLE *ht, char *infixstr);

/* Function to evaluate a postfix expression and return the result. */
int evaluate_postfix(char *postfix);

/* Function to evaluate a statement like "b = (a+3)*2;" and return the result as a HASHDATA type. */
HASHDATA evaluate_statement(HASHTABLE *ht, char *statement);

#endif // EXPRESSION_SYMBOL_H
