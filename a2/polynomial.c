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
#include "polynomial.h"

#define EPSILON 1e-6




/**
 *  add your comment
 */
float horner(float *p, int n, float x)
{
float r = 0;
for (int i = 0; i <n; i++){
	r = (r*x)+(*(p + i));
}
return r;
}

/**
 *  add your comment
 */
float bisection(float *p, int n, float a, float b){
float c;
while (1) {
    c = (a + b) / 2;
    if (horner(p, n, c) == 0 || (b - a) / 2 < 1e-6 || fabs(horner(p, n, c)) < 1e-6)
        break;
    else if (horner(p, n, a) * horner(p, n, c) < 0)
        b = c;
    else
        a = c;
}
return c;
}
