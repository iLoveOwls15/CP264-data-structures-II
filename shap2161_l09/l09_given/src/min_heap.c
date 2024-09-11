/**
 * -------------------------------------
 * @file  min_heap.c
 * Minimum Heap Source Code File
 * -------------------------------------
 * @Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2024-03-11
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "min_heap.h"

#define STRING_SIZE 80

// local functions

/**
 * Swaps two data values.
 *
 * @param a pointer to data.
 * @param b pointer to data.
 */
static void heap_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

/**
 * Moves the last value in source until it is in its correct location
 * in source.
 *
 * @param source - pointer to a heap
 */
static void heapify_up(min_heap *source) {
	int i = source->count - 1;
	    while (i > 0) {
	        int parentIndex = (i - 1) / 2;
	        if (source->values[i] < source->values[parentIndex]) {
	            heap_swap(&source->values[i], &source->values[parentIndex]);
	            i = parentIndex;
	        } else {
	            break;
	        }
	    }
	}

/**
 * Moves a value down source to its correct position.
 *
 * @param source - pointer to a heap
 */
static void heapify_down(min_heap *source) {

	 int i = 0;
	    int last_index = source->count - 1;

	    while (i <= last_index) {
	        int leftChildIndex = 2 * i + 1;
	        int rightChildIndex = 2 * i + 2;
	        int smallest = i;

	        if (leftChildIndex <= last_index && source->values[leftChildIndex] < source->values[smallest]) {
	            smallest = leftChildIndex;
	        }

	        if (rightChildIndex <= last_index && source->values[rightChildIndex] < source->values[smallest]) {
	            smallest = rightChildIndex;
	        }

	        if (smallest != i) {
	            heap_swap(&source->values[i], &source->values[smallest]);
	            i = smallest;
	        } else {
	            break;
	        }
	    }
	}

// Public minimum heap functions

min_heap* min_heap_initialize(int capacity) {
    min_heap *source = malloc(sizeof *source);
    source->values = malloc(capacity * sizeof *source->values);
    source->capacity = capacity;
    source->count = 0;
    return source;
}

void min_heap_free(min_heap **source) {
    free((*source)->values);
    free(*source);
    *source = NULL;
    return;
}

void min_heap_heapify(min_heap *source, int *keys, int count) {

    for(int i = 0; i < count; i++) {
        min_heap_insert(source, keys[i]);
    }
    return;
}

int min_heap_empty(const min_heap *source) {
    return (source->count == 0);
}

int min_heap_full(const min_heap *source) {
    return (source->count == source->capacity);
}

int min_heap_count(const min_heap *source) {
    return (source->count);
}

void min_heap_insert(min_heap *source, const int value) {
    // Add new value to end of the heap.
    source->values[source->count] = value;
    source->count++;
    // Fix the heap.
    heapify_up(source);
    return;
}

int min_heap_peek(const min_heap *source) {
    return (source->values[0]);
}

int min_heap_remove(min_heap *source) {
    int value = source->values[0];
    source->count--;

    if(source->count > 0) {

        source->values[0] = source->values[source->count];

        heapify_down(source);
    }
    return value;
}

int min_heap_valid(const min_heap *source) {

    // your code here
	for (int i = 0; i <= (source->count - 2) / 2; i++) {
	        if (source->values[i] > source->values[2 * i + 1] ||
	           (2 * i + 2 < source->count && source->values[i] > source->values[2 * i + 2])) {
	            return 0;
	        }
	    }
	    return 1;
	}

int min_heap_replace(min_heap *source, int replacement) {
    int value = source->values[0];
    source->values[0] = replacement;
    heapify_down(source);
    return value;
}

void heap_sort(int *values, int count) {

    // your code here
	min_heap *heap = min_heap_initialize(count);
	    min_heap_heapify(heap, values, count);

	    for (int i = 0; i < count; i++) {
	        values[i] = min_heap_remove(heap);
	    }

	    min_heap_free(&heap);
	}

void min_heap_print(const min_heap *source) {
    printf("{");

    for(int i = 0; i < source->count; i++) {
        printf("%d, ", source->values[i]);
    }
    printf("}\n");
    return;
}
