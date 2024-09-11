/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2023-09-09
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {
    printf("Enter three comma-separated integers: ");

    int num1, num2, num3;
    char comma;
    if (scanf("%d,%d,%d%c", &num1, &num2, &num3, &comma) != 4 || comma != '\n') {
        printf("The integers were not properly entered.\n");
        // Clear input buffer in case of incorrect input
        while (getchar() != '\n');
        return 0;
    }

    return num1 + num2 + num3;
}
