/**
 * -------------------------------------
 * @file  mystring.c
 * Assignment 3 String Operations, Word Processing
 * -------------------------------------
 * @author Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2024-02-02
 *
 * -------------------------------------
 */
#ifndef MYWORD_H
#define MYWORD_H
#include <stdio.h>

typedef enum {
    FALSE = 0,
    TRUE = 1
} BOOLEAN;


typedef struct {
    char word[20];
    int count;
} WORD;


typedef struct {
    int line_count;
    int word_count;
    int keyword_count;
} WORDSTATS;


int create_dictionary(FILE *fp, char *dictionary);
BOOLEAN contain_word(char *dictionary, char *word);
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary);

#endif
