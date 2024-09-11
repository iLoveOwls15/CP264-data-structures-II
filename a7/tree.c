/*
 -------------------------------------
 File:    tree.c
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
#include <stdlib.h>
#include "queue_stack.h"
#include "tree.h"

TPROPS tree_property(TNODE *root) {
    TPROPS props = {0, 0};

    if (root == NULL)
        return props;

    int count_nodes(TNODE *node) {
        if (node == NULL)
            return 0;
        return 1 + count_nodes(node->left) + count_nodes(node->right);
    }

    // Function to calculate the height of the tree
    int calculate_height(TNODE *node) {
        if (node == NULL)
            return 0;
        int left_height = calculate_height(node->left);
        int right_height = calculate_height(node->right);
        return (left_height > right_height) ? left_height + 1 : right_height + 1;
    }

    props.order = count_nodes(root);
    props.height = calculate_height(root);
    return props;
}
void preorder(TNODE *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TNODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
void postorder(TNODE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void bforder(TNODE *root) {
	if (root == NULL)
	    return;

	  QUEUE queue = {0};
	  enqueue(&queue, root);

	  while (queue.front) {
	    TNODE *p = dequeue(&queue);
	    printf("%c ", p->data);

	    if (p->left)
	      enqueue(&queue, p->left);
	    if (p->right)
	      enqueue(&queue, p->right);
	  }
	}

TNODE *bfs(TNODE *root, char val) {
	QUEUE queue = {0};
	  TNODE *r = NULL, *p = NULL;

	  if (root) {
	    enqueue(&queue, root);

	    while (queue.front) {
	      p = dequeue(&queue);

	      if (p->data == val) {
	        r = p;
	        break;
	      }

	      if (p->left)
	        enqueue(&queue, p->left);
	      if (p->right)
	        enqueue(&queue, p->right);
	    }
	  }

	  clean_queue(&queue);
	  return r;
	}
TNODE *dfs(TNODE *root, char key) {
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    TNODE *left_search = dfs(root->left, key);
    if (left_search != NULL)
        return left_search;

    TNODE *right_search = dfs(root->right, key);
    if (right_search != NULL)
        return right_search;

    return NULL; // Key not found
}

// the following functions are given, need to add to your program.

TNODE *new_node(char val) {
    TNODE *np = (TNODE *) malloc(sizeof(TNODE));
    if (np != NULL) {
        np->data = val;
        np->left = NULL;
        np->right = NULL;
    }
    return np;
}

void clean_tree(TNODE **rootp) {
    TNODE *p = *rootp;
    if (p) {
        if (p->left)
            clean_tree(&p->left);
        if (p->right)
            clean_tree(&p->right);
        free(p);
    }
    *rootp = NULL;
}

void insert_tree(TNODE **rootp, char val) {
    if (*rootp == NULL) {
        *rootp = new_node(val);
    } else {
        QUEUE queue = { 0 };
        TNODE *p;
        enqueue(&queue, *rootp);
        while (queue.front) {
            p = dequeue(&queue);
            if (p->left == NULL) {
                p->left = new_node(val);
                break;
            } else {
                enqueue(&queue, p->left);
            }

            if (p->right == NULL) {
                p->right = new_node(val);
                break;
            } else {
                enqueue(&queue, p->right);
            }
        }
    }
}
