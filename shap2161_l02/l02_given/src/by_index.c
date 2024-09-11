/**
 * -------------------------------------
 * @file  by_index.c
 * Lab 2 Index Functions Source Code File
 * -------------------------------------
 * @author Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2024-01-06
 *
 * -------------------------------------
 */
#include "by_index.h"

void fill_values_by_index(int values[], int size) {

    for(int i = 0; i < size; i++) {
        values[i] = i + 1;
    }
}

void fill_squares_by_index(int values[], long int squares[], int size) {

    for(int i = 0; i < size; i++) {
    	values[i] = i+1;
    	squares[i] = i+1 * i+1;
    }

}

void print_by_index(int values[], long int squares[], int size) {
    printf("Value  Square\n");
    printf("-----  ----------\n");
	for(int i = 0; i < size; i++) {
	    	values[i] = i+1;
	    	squares[i] = (i+1) * (i+1);
	    	printf("%5d%12d\n",values[i], squares[i]);
	    }
}

