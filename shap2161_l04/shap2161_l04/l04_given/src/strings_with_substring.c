/**
 * -------------------------------------
 * @file  strings_with_substring.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Daniel Shapovalov, 169032161, shap2161@wlu.ca
 *
 * @version 2024-02-03
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../shap2161_l04/l04_given/src/functions.h"

void strings_with_substring(strings_array *data, char *substr) {

	if (data == NULL || substr == NULL) {
	        fprintf(stderr, "Error: NULL pointer provided to strings_with_substring.\n");
	        return;
	    }
	    for (int i = 0; i < data->lines; i++) {
	        if (strstr(data->strings[i], substr) != NULL) {
	            // If the substring is found, print the string
	            printf("%s\n", data->strings[i]);
	        }
	    }
	}

