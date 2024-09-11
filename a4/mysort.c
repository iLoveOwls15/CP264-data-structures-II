/**
 * -------------------------------------
 * @file  mysort.c
 * Assignment 4
 * -------------------------------------
 * @author Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2024-02-10
 *
 * -------------------------------------
 */
#include "mysort.h"

void select_sort(float *a[], int left, int right)
{
    int i, j, k;
    float *temp;

    for (i=left; i<right; i++) {

        k = i;

        for (j = i+1; j<right; j++) {

            if (*a[j] < *a[k]) {
                k = j;
            }
        }

        if (i != k) {
            temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
    }
}


void quick_sort_inc(float *a[], int left, int right) {
    int i,j;
    float pivot, *temp;

    if(left < right){
        pivot = *a[left]; //set pivot to be left index
        i = left+1;
        j = right;

        while (i <= j){ //run until i and j meet in middle
            while(i <= right && *a[i] <= pivot) i++; //run until value greater than pivot is found
            while(j >= left && *a[j] > pivot) j--; //run until value less than pivot is found
            if(i < j) { //if i has a smaller index than j, swap them
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        //swap left index and value at index j
        temp = a[left];
        a[left] = a[j];
        a[j] = temp;

        //call sorting method again, to iterate through left and right sides of array
        quick_sort_inc(a, left, j-1);
        quick_sort_inc(a, j+1, right);
    }
}
