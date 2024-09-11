/*
 -------------------------------------
 File:    bigint.c
 Project: a05
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-02-17
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

/*
 * Define BIGINT as DLL
 */
typedef DLL BIGINT;

/*
 * Creates and returns BIGINT object by converting the digit string.
 */
BIGINT bigint(char *p) {
	BIGINT bn = { 0 };
	if (p == NULL)
		return bn;
	else if (!(*p >= '0' && *p <= '9')) { // not begin with digits
		return bn;
	} else if (*p == '0' && *(p + 1) == '\0') { // just "0"
		dll_insert_end(&bn, new_node(*p - '0'));
		return bn;
	} else {
		while (*p) {
			if (*p >= '0' && *p <= '9') {
				dll_insert_end(&bn, new_node(*p - '0'));
			} else {
				dll_clean(&bn);
				break;
			}
			p++;
		}
		return bn;
	}
}
/*
 * Add two BIGINT operants and returns the sum in BIGINT type.
 * @param oprand1  - first operand of BIGINT type.
 * @param oprand2  - second operand of BIGINT type.
 * @return - the sum of oprand1 and oprand2 in BIGINT type.
 */
BIGINT bigint_add(BIGINT oprand1, BIGINT oprand2) {

	BIGINT result = { 0, NULL, NULL };
	int carry = 0;

	NODE *ptr1 = oprand1.end;
	NODE *ptr2 = oprand2.end;

	while (ptr1 != NULL || ptr2 != NULL || carry != 0) {
		int sum = carry;
		if (ptr1 != NULL) {
			sum += ptr1->data;
			ptr1 = ptr1->prev;
		}
		if (ptr2 != NULL) {
			sum += ptr2->data;
			ptr2 = ptr2->prev;
		}

		carry = sum / 10;
		dll_insert_start(&result, new_node(sum % 10));

	}
	return result;
}
/*
 * Compute and return Fibonacci(n)
 * @param n - input positive integer
 * @return  - Fibonacci(n) in BIGINT type
 */
BIGINT bigint_fibonacci(int n) {

	if (n <= 0) {
		return bigint("0");
	} else if (n == 1) {
		return bigint("1");
	}

	BIGINT a = bigint("0");
	BIGINT b = bigint("1");
	BIGINT c = { 0, NULL, NULL };

	for (int i = 2; i <= n; ++i) {
		c = bigint_add(a, b);
		dll_clean(&a);
		a = b;
		b = c;
	}

	dll_clean(&a);
	return b;
}
