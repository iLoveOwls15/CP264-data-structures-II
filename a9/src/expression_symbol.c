/*
 -------------------------------------
 File:    expression_symbol.c
 Project: a9
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */

#include "expression_symbol.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Auxiliary functions you might need for expression handling
// e.g., is_operator, precedence, apply_operation, etc.

int evaluate_infix_symbol(HASHTABLE *ht, char *infixstr) {
	// Convert infix to postfix using the hashtable for symbol resolution
	char *postfix = infix_to_postfix_symbol(ht, infixstr);
	// Evaluate the postfix expression
	int result = evaluate_postfix(postfix);
	free(postfix);
	return result;
}

char* infix_to_postfix_symbol(HASHTABLE *ht, char *infixstr) {
	// Implement the conversion from infix to postfix notation
	// Use the hashtable for symbol resolution
	// This will be a simplified version, consider using a stack for operators

	// Example placeholder implementation
	char *postfix = malloc(strlen(infixstr) + 1); // Adjust size as needed
	strcpy(postfix, infixstr); // Placeholder copy, replace with actual conversion logic
	return postfix;
}

int evaluate_postfix(char *postfix) {
	// Implement postfix evaluation
	// This will be a simplified version, consider using a stack for operands

	// Example placeholder implementation
	return 0; // Placeholder, replace with actual evaluation logic
}

HASHDATA evaluate_statement(HASHTABLE *ht, char *statement) {
	// Parse the statement, evaluate the expression, and update the hashtable

	// Example placeholder implementation
	HASHDATA data = { .key = "x", .value = 0 }; // Placeholder, replace with actual logic
	return data;
}
