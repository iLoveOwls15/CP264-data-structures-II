/*
 -------------------------------------
 File:    expression.h
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

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "common.h"
#include "queue.h"

QUEUE infix_to_postfix(char *infixstr);

int evaluate_postfix(QUEUE queue);

int evaluate_infix(char *infixstr);

#endif
