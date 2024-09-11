/**
 * -------------------------------------
 * @file  file name
 * Assignment 2  Main File
 * -------------------------------------
 * @Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version the date of creating this file in format like 2024-01-08
 *
 * ------------------------------------- */

/*
 * your program signature
 */
#include <stdio.h>
#include <math.h>
#include "matrix.h"

/**
 *  add your comment
 */
float norm(float *v, int n) {
    float normm = 0.0; // sum of squares
    for (int i = 0; i < n; i++) // loop through all elements
        normm += v[i] * v[i]; // add each element squared to sum
    return sqrt(normm); // return square root of sum
}

/**
 *  add your comment
 */
float dot_product(float *v1, float *v2, int n) {
	float result = 0;
	for (int i = 0; i < n; i++){
		result += v1[i] * v2[i];
	}
	return result;
}

/**
 *  add your comment
 */
void multiply_matrix(float *m1, float *m2, float *m3, int n) {
	 for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            m3[i * n + j] = 0.0;
	            for (int k = 0; k < n; k++) {
	                m3[i * n + j] += m1[i * n + k] * m2[k * n + j];
	            }
	        }
	    }
	}
/**
 *  add your comment
 */
void matrix_multiply_vector(float *m, float *vin, float *vout, int n) {
	for (int i = 0; i < n; i++) {
	        vout[i] = 0.0;
	        for (int j = 0; j < n; j++) {
	            vout[i] += m[i * n + j] * vin[j];
	        }
	    }
	}
