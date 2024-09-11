/*
 -------------------------------------
 File:    myrecord_sllist.c
 Project: a05
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap216@mylaurier.ca
 Version  2024-02-17
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"

NODE *sll_search(SLL *sllp, char *name) {
	if (sllp == NULL || sllp->start == NULL) {
			return NULL;
		}

		NODE *current = sllp->start;
		while (current != NULL) {
			if (strcmp(current->data.name, name) == 0) {
				return current;
			}
			current = current->next;
		}
		return NULL;
}

void sll_insert(SLL *sllp, char *name, float score) {
// your code
	if (sllp == NULL)
			return;

		NODE *newNode = malloc(sizeof(NODE));
		if (newNode == NULL)
			return;

		strncpy(newNode->data.name, name, sizeof(newNode->data.name) - 1);
		newNode->data.name[sizeof(newNode->data.name) - 1] = '\0';
		newNode->data.score = score;
		newNode->next = NULL;

		if (sllp->start == NULL || strcmp(sllp->start->data.name, name) > 0) {
			newNode->next = sllp->start;
			sllp->start = newNode;
		} else {
			NODE *current = sllp->start;
			while (current->next != NULL
					&& strcmp(current->next->data.name, name) < 0) {
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
		}

		sllp->length++;
}

int sll_delete(SLL *sllp, char *name) {
// your code
	if (sllp == NULL || sllp->start == NULL) {
			return 0;
		}

		NODE *prev = NULL;
		NODE *current = sllp->start;
		while (current != NULL && strcmp(current->data.name, name) != 0) {
			prev = current;
			current = current->next;
		}
		if (current == NULL) {
			return 0;
		}
		if (prev == NULL) {
			sllp->start = current->next;
		} else {
			prev->next = current->next;
		}

		free(current);
		sllp->length--;
		return 1;
}

void sll_clean(SLL *sllp) {
    NODE *temp, *ptr = sllp->start;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    sllp->start = NULL;
    sllp->length = 0;
}
