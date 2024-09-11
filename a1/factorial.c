/**
 * -------------------------------------
 * @file  file name
 * Assignment 1  Main File
 * -------------------------------------
 * @Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version the date of creating this file in format like 2024-01-08
 *
 * ------------------------------------- */

#include "factorial.h"
#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else if (n > 12) {
        printf("Overflow");
        return 0;
    } else {
        return n * factorial(n - 1);
    }
}

