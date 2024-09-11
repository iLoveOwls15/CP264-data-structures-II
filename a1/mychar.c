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
#include <stdio.h>
#include "mychar.h"


/**
 * Determine the type of a char character.
 *
 * @param c - char type value
 * @return - 0 if c is a digit, 1 if c is an arithmetic operator, 2 if c is an English letter; otherwise -1.
 */
int mytype(char c){
    if (c >= '0' && c <= '9') {
        return 0;
    }
    // Check if c is an arithmetic operator
    else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
        return 1;
    }
    // Check if c is an English letter
    else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 2;
    }
    // Default case for characters that don't match any criteria
    else {
        return -1;
    }
}

/**
 * Flip the case of an English character.
 *
 * @param c - char type value of ASCII code of English letter.
 * @return  -  c's upper/lower case letter if c is a lower/upper case English letter.
 */
char case_flip(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    } else if (c >= 'a' && c <= 'z') {
        return c - 32;
    } else {
        // If not an English letter, return unchanged
        return c;
    }
}

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value of ASCII code of digit character.
 * @return - its corresponding integer value if c is a digit character.
 */
int char_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0'; // Convert ASCII digit to integer value
    } else {
        return -1; // Return -1 for non-digit characters
    }
}
