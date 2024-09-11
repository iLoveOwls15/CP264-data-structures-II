/**
 * -------------------------------------
 * @file  myrecord.h
 * Assignment 4
 * -------------------------------------
 * @author Daniel Shapovalov, 169032161, shap2161@mylaurier.ca
 *
 * @version 2024-02-10
 *
 * -------------------------------------
 */
#ifndef MYRECORD_H
#define MYRECORD_H

#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    float score;
} RECORD;

typedef struct {
    int count;
    float mean;
    float stddev;
    float median;
} STATS;

char letter_grade(float score);
int import_data(RECORD dataset[], char *filename);
STATS report_data(RECORD dataset[], int n, char *filename);

#endif
