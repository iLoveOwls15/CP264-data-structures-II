/**
 * -------------------------------------
 * @file  strings_length.c
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

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length) {
	if (data == NULL || fp_short == NULL || fp_long == NULL) {
	        fprintf(stderr, "Error: One or more NULL pointers provided to strings_length.\n");
	        return;
	    }

	    for (int i = 0; i < data->lines; i++) {
	        if (strlen(data->strings[i]) < length) {
	            fprintf(fp_short, "%s\n", data->strings[i]);
	        } else {
	            fprintf(fp_long, "%s\n", data->strings[i]);
	        }
	    }
	}
