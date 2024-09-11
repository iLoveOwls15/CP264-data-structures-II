/*
 -------------------------------------
 File:    heap.h
 Project: a9
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */
#ifndef HEAP_H_
#define HEAP_H_

typedef int KEYTYPE;
typedef int VALUETYPE;

typedef struct {
	KEYTYPE key;
	VALUETYPE value;
} HEAPDATA;

typedef struct heap {
	unsigned int size;
	unsigned int capacity;
	HEAPDATA *hda; // Heap Data Array
} HEAP;

HEAP* new_heap(int capacity);
void heap_insert(HEAP *heap, HEAPDATA data);
HEAPDATA heap_find_min(HEAP *heap);
HEAPDATA heap_extract_min(HEAP *heap);
int heap_change_key(HEAP *heap, int index, KEYTYPE new_key);
int heap_search_data(HEAP *heap, VALUETYPE val);
void heap_clean(HEAP **heapp);

#endif
