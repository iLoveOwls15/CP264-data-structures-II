/*
 -------------------------------------
 File:    hash.c
 Project: a9
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */

#include "hash.h"
#include <stdlib.h>
#include <string.h>

int hash(char *key, int size) {
	unsigned long hash = 5381;
	int c;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash % size;
}

HASHTABLE* new_hashtable(int size) {
	HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
	ht->size = size;
	ht->count = 0;
	ht->hna = (HASHNODE**) malloc(sizeof(HASHNODE*) * size);
	for (int i = 0; i < size; i++) {
		ht->hna[i] = NULL;
	}
	return ht;
}

int hashtable_insert(HASHTABLE *ht, char *key, int value) {
	int index = hash(key, ht->size);
	HASHNODE *new_node = (HASHNODE*) malloc(sizeof(HASHNODE));
	strcpy(new_node->key, key);
	new_node->value = value;
	new_node->next = NULL;

	HASHNODE *current = ht->hna[index];
	HASHNODE *prev = NULL;
	while (current != NULL && strcmp(current->key, key) < 0) {
		prev = current;
		current = current->next;
	}

	if (current != NULL && strcmp(current->key, key) == 0) {
		current->value = value;
		free(new_node);
		return 0;
	}

	if (prev == NULL) {
		new_node->next = ht->hna[index];
		ht->hna[index] = new_node;
	} else {
		new_node->next = current;
		prev->next = new_node;
	}

	ht->count++;
	return 1;
}

HASHNODE* hashtable_search(HASHTABLE *ht, char *key) {
	int index = hash(key, ht->size);
	HASHNODE *current = ht->hna[index];
	while (current != NULL && strcmp(current->key, key) != 0) {
		current = current->next;
	}
	return current;
}

int hashtable_delete(HASHTABLE *ht, char *key) {
	int index = hash(key, ht->size);
	HASHNODE *current = ht->hna[index];
	HASHNODE *prev = NULL;

	while (current != NULL && strcmp(current->key, key) != 0) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) {
		return 0;
	}

	if (prev == NULL) {
		ht->hna[index] = current->next;
	} else {
		prev->next = current->next;
	}

	free(current);
	ht->count--;
	return 1;
}

void hashtable_clean(HASHTABLE **ht) {
	for (int i = 0; i < (*ht)->size; i++) {
		HASHNODE *current = (*ht)->hna[i];
		while (current != NULL) {
			HASHNODE *temp = current;
			current = current->next;
			free(temp);
		}
	}
	free((*ht)->hna);
	free(*ht);
	*ht = NULL;
}
