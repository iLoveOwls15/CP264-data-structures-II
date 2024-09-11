/*
 -------------------------------------
 File:    heap.c
 Project: a9
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-23
 -------------------------------------
 */

#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

static void swap(HEAPDATA *a, HEAPDATA *b) {
	HEAPDATA temp = *a;
	*a = *b;
	*b = temp;
}

static void heapify_down(HEAP *heap, int idx) {
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < heap->size && heap->hda[left].key < heap->hda[smallest].key)
		smallest = left;

	if (right < heap->size && heap->hda[right].key < heap->hda[smallest].key)
		smallest = right;

	if (smallest != idx) {
		swap(&heap->hda[idx], &heap->hda[smallest]);
		heapify_down(heap, smallest);
	}
}

static void heapify_up(HEAP *heap, int idx) {
	if (idx && heap->hda[(idx - 1) / 2].key > heap->hda[idx].key) {
		swap(&heap->hda[idx], &heap->hda[(idx - 1) / 2]);
		heapify_up(heap, (idx - 1) / 2);
	}
}

HEAP* new_heap(int capacity) {
	HEAP *heap = (HEAP*) malloc(sizeof(HEAP));
	heap->size = 0;
	heap->capacity = capacity;
	heap->hda = (HEAPDATA*) malloc(capacity * sizeof(HEAPDATA));
	return heap;
}

void heap_insert(HEAP *heap, HEAPDATA data) {
	if (heap->size == heap->capacity) {
		heap->capacity *= 2;
		heap->hda = realloc(heap->hda, heap->capacity * sizeof(HEAPDATA));
	}

	heap->hda[heap->size] = data;
	heapify_up(heap, heap->size);
	heap->size++;
}

HEAPDATA heap_find_min(HEAP *heap) {
	if (heap->size == 0) {
		printf("Heap is empty\n");
		return (HEAPDATA ) { 0 } ; // Returning an empty HEAPDATA; adjust as per your error handling
			}
			return heap->hda[0];
		}

		HEAPDATA heap_extract_min(HEAP *heap) {
			if (heap->size == 0) {
				printf("Heap is empty\n");
				return (HEAPDATA ) { 0 } ; // Returning an empty HEAPDATA; adjust as per your error handling
					}

					HEAPDATA root = heap->hda[0];
					heap->hda[0] = heap->hda[heap->size - 1];
					heap->size--;
					heapify_down(heap, 0);

					if (heap->size <= (heap->capacity / 4)
							&& heap->capacity > 4) {
						heap->capacity /= 2;
						heap->hda = realloc(heap->hda,
								heap->capacity * sizeof(HEAPDATA));
					}

					return root;
				}

				int heap_change_key(HEAP *heap, int index, KEYTYPE new_key) {
					if (index < 0 || index >= heap->size) {
						printf("Index out of bounds\n");
						return -1;  // adjust as per your error handling
					}

					heap->hda[index].key = new_key;
					heapify_up(heap, index);
					heapify_down(heap, index);
					return index; // This implementation returns the same index; adjust based on your needs
				}

				int heap_search_data(HEAP *heap, VALUETYPE val) {
					for (int i = 0; i < heap->size; i++) {
						if (heap->hda[i].value == val) {
							return i;  // Return the index of the first match
						}
					}
					return -1;  // Value not found
				}

				void heap_clean(HEAP **heapp) {
					if (heapp && *heapp) {
						free((*heapp)->hda);
						free(*heapp);
						*heapp = NULL;
					}
				}
