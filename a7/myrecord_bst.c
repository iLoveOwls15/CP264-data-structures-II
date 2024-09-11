/*
 -------------------------------------
 File:    myrecord_bst.c
 Project: a07
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-09
 -------------------------------------
 */
#include <stdio.h>
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_record(BSTDS *ds, RECORD record) {
    bst_insert(&(ds->root), record);
    ds->count++;
    ds->mean = (ds->mean * (ds->count - 1) + record.score) / ds->count;

    float sum_squares = ds->stddev * ds->stddev * (ds->count - 1);
    sum_squares += (record.score - ds->mean) * (record.score - ds->mean);
    ds->stddev = sqrt(sum_squares / ds->count);
}

void remove_record(BSTDS *ds, char *name) {
    BSTNODE *node = bst_search(ds->root, name);
    if (node != NULL) {
        bst_delete(&(ds->root), name);
        ds->count--;
        float sum = 0;
        BSTNODE *current = ds->root;
        while (current != NULL) {
            sum += current->data.score;
            current = current->right;
        }
        ds->mean = sum / ds->count;

        sum = 0;
        current = ds->root;
        while (current != NULL) {
            sum += (current->data.score - ds->mean) * (current->data.score - ds->mean);
            current = current->right;
        }
        ds->stddev = sqrt(sum / ds->count);
    }
}

void clean_bstds(BSTDS *ds) {
  clean_bst(&ds->root);
  ds->count = 0;
  ds->mean = 0;
  ds->stddev = 0;
}
