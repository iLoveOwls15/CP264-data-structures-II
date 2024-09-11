/*
 * your program signature
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avl.h"
#include "myrecord_avl.h"

void merge_avl(AVLNODE **dest_rootp, AVLNODE **source_rootp)
{
    if (!*source_rootp)
    {
        return;
    }
    else
    {
    	merge_avl(dest_rootp, &(*source_rootp)->left);
    	merge_avl(dest_rootp, &(*source_rootp)->right);

        char *name = strdup((*source_rootp)->data.name);
        float score = (*source_rootp)->data.score;
        insert(dest_rootp, name, score);
        return;
    }
}
void merge_avlds(AVLDS *dest, AVLDS *source);
{
return;
}


void clean_avlds(AVLDS *ds) {
    clean_avl(&ds->root);
    ds->count = 0;
    ds->mean = 0;
    ds->stddev = 0;
}

// the following functions are adapted from a7q3
void add_record(AVLDS *tree, RECORD data) {
  if (avl_search(tree->root, data.name) == NULL) {
    avl_insert(&(tree->root), data);
    int count = tree->count;
    float mean = tree->mean;
    float stddev = tree->stddev;
    tree->count = count + 1;
    tree->mean =  (mean*count + data.score) / (count+1.0);
    tree->stddev = sqrt(data.score*data.score/(count+1.0) + (stddev * stddev + mean * mean) * (count/(count+1.0)) - tree->mean * tree->mean );
  } else {
    printf("record exits");
  }
}

void remove_record(AVLDS *tree, char *name) {
  AVLNODE *np = NULL;
  if ( (np = avl_search(tree->root, name)) != NULL) {
    float score = np->data.score;
    avl_delete(&(tree->root), name);
    float count = tree->count;
    float mean = tree->mean;
    float stddev = tree->stddev;
    tree->count = count - 1;
    if (count >= 3) {
      tree->mean =  (mean*count - score) / (count-1.0);
      tree->stddev = sqrt( (stddev * stddev + mean * mean) * (count/(count-1.0)) - score*score/(count-1.0) - tree->mean * tree->mean );
    }
    else if (count == 2) {
        tree->mean = mean*count - score;
        tree->stddev = 0;
   }
   else {
        tree->mean = 0;
        tree->stddev = 0;
    }
  } else {
    printf("record does not exit");
  }
}
