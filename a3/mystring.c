/**
 * -------------------------------------
 * @file  mystring.c
 * Assignment 3 String Operations, Word Processing
 * -------------------------------------
 * @author Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2024-02-10
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <ctype.h>
#include "mystring.h"


/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.
 *
 * @param s - char pointer to a str
 * @return - return the number of words.
 */
int str_words(char *s){
int count = 0;
    int in_word = 0;

    while (*s) {
        if (isalpha(*s)) {
            if (!in_word) {
                in_word = 1;
                count++;
            }
        } else if (isspace(*s) || *s == ',' || *s == '.') {
            in_word = 0;
        }
        s++;
    }
    return count;
}
/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a str
 * @return - return the number of actual flips.
 */
int str_lower(char *s) {

	int flips = 0; //initialize to 0
	    while (*s) {
	        if (isupper(*s)) {
	            *s = tolower(*s);
	            flips++;
	        }
	        s++;
	    }
	    return flips;
}
/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a str
 */
void str_trim(char *s) {
    char *p = s; //pinter action
    int in_space = 0;

    while (*s) {
        if (isspace(*s)) {
            if (!in_space) {
                *p++ = ' ';
                in_space = 1;
            }
        } else {
            *p++ = *s;
            in_space = 0;
        }
        s++;
    }

    if (in_space && p != s) {
        p--;
    }
    *p = '\0';
}
