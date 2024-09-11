/**
 * -------------------------------------
 * @file  file name
 * Assignment 1  Header File
 * -------------------------------------
 * @Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version the date of creating this file in format like 2024-01-08
 *
 * ------------------------------------- */


#ifndef MYCHAR_H
#define MYCHAR_H

/**
 * Determine the type of a char character.
 *
 * @param c - char type value
 * @return - 0 if c is a digit, 1 if c is an arithmetic operator, 2 if c is an English letter; otherwise -1.
 */
int mytype(char c);

char case_flip(char c);

int char_to_int(char c);

#endif  // MYCHAR_H
