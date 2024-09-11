/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {
    printf("Enter %d values for an array of int \n", size);

    char buffer[256];
    int value;
    int count = 0;

    while (count < size) {
        printf("Value for index %d: ", count);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &value) == 1) {
                array[count++] = value;
            } else {
                printf("Not a valid integer\n");
            }
        }
    }
}
