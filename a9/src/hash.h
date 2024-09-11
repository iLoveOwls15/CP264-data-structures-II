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
#ifndef HASH_H_
#define HASH_H_

typedef struct {
	char key[20];
	int value;
} HASHDATA;

typedef struct hashnode {
	char key[20];
	int value;
	struct hashnode *next;
} HASHNODE;

typedef struct hashtable {
	HASHNODE **hna;
	int size;
	int count;
} HASHTABLE;

int hash(char *key, int size);
HASHTABLE* new_hashtable(int size);
int hashtable_insert(HASHTABLE *ht, char *key, int value);
HASHNODE* hashtable_search(HASHTABLE *ht, char *key);
int hashtable_delete(HASHTABLE *ht, char *key);
void hashtable_clean(HASHTABLE **ht);

#endif
