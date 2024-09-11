/**
 * -------------------------------------
 * @file  queue_array.c
 * Lab 4 Array-Based queue Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2023-09-25
 *
 * -------------------------------------
 */
#include "../../../shap2161_l04/l04_given/html/queue_array.h"

// Functions

// Initializes a queue.
void queue_initialize(queue_struct *queue, data_type_string to_string, data_type_copy copy) {
    queue->capacity = QUEUE_INIT;
    queue->count = 0;
    queue->front = -1;
    queue->rear = 0;
    queue->to_string = to_string;
    queue->copy = copy;
    return;
}

// Determines if a queue is empty.
bool queue_empty(const queue_struct *queue) {
    return (queue->front == -1);
}

// Determines if the queue is full.
bool queue_full(const queue_struct *queue) {
    return (queue->count == queue->capacity);
}

// Returns the number of items in the queue.
int queue_count(const queue_struct *queue) {
    return (queue->count);
}

// Inserts an item into a queue.
bool queue_insert(queue_struct *queue, data_type *item) {
    bool inserted = false;

    if(queue->count < queue->capacity) {
        queue->copy(&(queue->items[queue->rear]), item);
        queue->count++;

        if(queue->count == queue->capacity) {
            // queue is now full
            queue->rear = -1;
        } else {
            if(queue->count == 1) {
                // Added first item
                queue->front = queue->rear;
            }
            queue->rear = (queue->rear + 1) % queue->capacity;
        }
        inserted = true;
    }
    return inserted;
}

// Returns a copy of the front of a queue.
bool queue_peek(const queue_struct *queue, data_type *item) {
    bool peeked = false;

    if(queue->count > 0) {
        queue->copy(item, &(queue->items[queue->front]));
        peeked = true;
    }
    return peeked;
}

// Returns and removes the item on the front of a queue.
bool queue_remove(queue_struct *queue, data_type *item) {
    bool removed = false;

    if(queue->count > 0) {
        // Get the value from the front
        *item = queue->items[queue->front];
        queue->count--;

        if(queue->count == 0) {
            // removed the last item
            queue->front = -1;
        } else {
            if(queue->count == (queue->capacity - 1)) {
                // Have freed up a space in a full array
                queue->rear = queue->front;
            }
            queue->front = (queue->front + 1) % queue->capacity;
        }
        removed = true;
    }
    return removed;
}

// Prints the items in a queue from front to bottom.
void queue_display(const queue_struct *queue, char string[], size_t size) {
    // Walk through queue using indexes.
    int i = 0;
    int index = queue->front;

    while(i < queue->count) {
        printf("%s\n", queue->to_string(&(queue->items[index]), string, size));
        index = (index + 1) % queue->capacity;
        i++;
    }
    return;
}
