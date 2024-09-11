/*
 -------------------------------------
 File:    dllist.c
 Project: a05
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-02-17
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

NODE *new_node(char data) {
	NODE *node = (NODE*) malloc(sizeof(NODE));

	if (node == NULL)
		return NULL;

	node->data = value;
	node->prev = NULL;
	node->next = NULL;

	return node;
}
void dll_insert_start(DLL *dllp, NODE *np) {
	if (dllp == NULL || np == NULL) {
		return;
	}
	if (dllp->start == NULL) {
		dllp->start = np;
		dllp->end = np;
	} else {
		np->next = dllp->start;
		dllp->start->prev = np;
		dllp->start = np;
	}
	dllp->length++;
}


void dll_insert_end(DLL *dllp, NODE *np) {
	if (dllp == NULL || np == NULL) {
			return;
		}

		np->next = NULL;
		np->prev = dllp->end;

		if (dllp->start == NULL) {
			dllp->start = np;
			dllp->end = np;
		} else {
			dllp->end->next = np;
			dllp->end = np;
		}
		dllp->length++;
	}


void dll_delete_start(DLL *dllp) {
	if (dllp == NULL) {
		return;
	}

	NODE *temp = dllp->start;
	if (dllp->start == dllp->end) {
		dllp->start = NULL;
		dllp->end = NULL;
	} else {
		dllp->start = dllp->start->next;
		dllp->start->prev = NULL;
	}
	free(temp);
	dllp->length--;

}

void dll_delete_end(DLL *dllp) {

	if (dllp == NULL) {
		return;
	}

	NODE *temp = dllp->end;
	if (dllp->start == dllp->end) {
		dllp->start = NULL;
		dllp->end = NULL;
	} else {
		dllp->end = dllp->end->prev;
		dllp->end->next = NULL;
	}
	free(temp);
	dllp->length--;
}



void dll_clean(DLL *dllp) {
	void dll_clean(DLL *dllp) {
		NODE *temp, *ptr = dllp->start;
		while (ptr != NULL) {
			temp = ptr;
			ptr = ptr->next;
			free(temp);
		}
		dllp->start = NULL;
		dllp->length = 0;
	}
