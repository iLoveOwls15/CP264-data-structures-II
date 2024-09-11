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




/**
 *
 *
 * your program signature
 */

#include "fibonacci.h"

/**
 *  add your comment
 */
int recursive_fibonacci(int n) {
if (n <= 1){
	return n;
}
	else {
		return recursive_fibonacci(n-2) + recursive_fibonacci(n-1);
	}



}

/**
 *  add your comment
 */
int iterative_fibonacci(int n){
    if (n <= 1) {
        return n;
    }
    int f1 = 0, f2 = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    return f2;
}

/**
 *  add your comment
 */
int dpbu_fibonacci(int *f, int n) {
f[0] = 0;
f[1] = 1;
for (int i = 2; i<= n; i++){
f[i]= f[i -1] + f[i -2];
}
return f[n];
}

/**
 *  add your comment
 */
int dptd_fibonacci(int *f, int n) {
if (n <= 1){
	return f[n];
}

f[0] = 0;
f[1] = 1;
for (int i =2; i<=n; i++){
	f[i] = f[i-2] + f[i-1];
}
return f[n];
}
