/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {
    printf("Enter integers, one per line:\n");

    char buffer[256];  // Assuming a maximum line length of 255 characters
    int num;
    int sum = 0;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%d", &num) == 1) {
            sum += num;  // Add the first integer to the sum
        }
    }

    return sum;
}
