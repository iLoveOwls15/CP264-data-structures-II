/**
 * -------------------------------------
 * @file  graph_am.c
 * Adjacency Matrix Graph Code File
 * -------------------------------------
 * @author Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2024-03-14
 *
 * -------------------------------------
 */
#include "graph_am.h"

// Initializes an adjacency matrix graph.
graph_am* graph_am_initialize(int size) {
    graph_am *source = malloc(sizeof *source);
    source->size = size;
    // Initialize values to zeroes.
    source->values = calloc(size * size, sizeof *source->values);
    return source;
}

void graph_am_free(graph_am **source) {
    // Free up the data array.
    free((*source)->values);
    (*source)->values = NULL;
    free(*source);
    *source = NULL;
    return;
}

int graph_am_add_vertice(graph_am *source, const graph_am_pair *pair) {
    int added; // Declare 'added' here

    if (pair->row < 0 || pair->row >= source->size || pair->col < 0 || pair->col >= source->size) {
        return 0; // Vertex index out of range
    }

    if (*(source->values + pair->row * source->size + pair->col) == 0) {
        *(source->values + pair->row * source->size + pair->col) = 1; // Add the edge

        added = 1;
    }
     else {
        added = 0;
    }

    return added; // Return 'added' here
}

int graph_am_remove_vertice(graph_am *source, const graph_am_pair *pair) {
    int removed;

    if (pair->row < 0 || pair->row >= source->size || pair->col < 0 || pair->col >= source->size)
        removed = 0; // Vertex index out of range
    else {
        int *value = source->values + pair->row * source->size + pair->col;
        if (*value == 1) {
            *value = 0; // Remove the edge
            removed = 1; // Vertex removed successfully
        } else {
            removed = 0; // No edge exists to remove
        }
    }

    return removed;
}


graph_am* graph_am_create(int size, const graph_am_pair pairs[], int count) {
    graph_am *source = graph_am_initialize(size);

    // your code here

    return source;
}

void graph_am_neighbours(const graph_am *source, int vertex, int vertices[], int *count) {

    // your code here

    return;
}

int graph_am_degree(const graph_am *source, int vertex) {
    int connected = 0;

    // your code here

    return connected;
}

void graph_am_breadth_traversal(const graph_am *source, int vertex, int vertices[], int *count) {

    // your code here

    return;
}

void graph_am_depth_traversal(const graph_am *source, int vertex, int vertices[], int *count) {

    // your code here

    return;
}

// Prints the contents of an adjacency matrix graph.
void graph_am_print(const graph_am *source) {
    // Print the column numbers.
    printf("    ");

    for(int i = 0; i < source->size; i++)
        printf("%3d", i);
    printf("\n");
    printf("    ");
    for(int i = 0; i < source->size; i++)
        printf("---");
    printf("\n");

    // Print the row numbers and rows.
    for(int i = 0; i < source->size; i++) {
        printf("%3d|", i);

        for(int j = 0; j < source->size; j++) {
            // find item using offsets
            printf("%3d", *(source->values + i * source->size + j));
        }
        printf("\n");
    }
}
