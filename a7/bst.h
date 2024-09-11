/*
 -------------------------------------
 File:    bst.h
 Project: a07
 file description
 -------------------------------------
 Author:  Daniel Shapovalov
 ID:      169032161
 Email:   shap2161@mylaurier.ca
 Version  2024-03-09
 -------------------------------------
 */
#ifndef BST_H
#define BST_H

typedef struct record {
  char name[20];
  float score;
} RECORD;

typedef struct bstnode {
  RECORD data;
    struct bstnode *left;
    struct bstnode *right;
} BSTNODE;


BSTNODE *bst_search(BSTNODE *root, char *key);

void bst_insert(BSTNODE **rootp, RECORD data);

void bst_delete(BSTNODE **rootp, char *key);


BSTNODE *new_node(RECORD data);
BSTNODE *extract_smallest_node(BSTNODE **rootp);
void clean_bst(BSTNODE **rootp);

#endif
