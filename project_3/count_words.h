#include <stdio.h>
#include "binaryTree.h"

/*
WordNode* find_max(WordNode* start)
    traverses through a given binary tree and finds the WordNode with the most count from a file

Parameters:
    start: a pointer to the Wordnode for the highest root in the binary tree
Returns:
    a WordNode for the most common word in the tree
*/
extern WordNode* find_max(WordNode* start);

/*
WordNode* find_min(WordNode* start)
    traverses through a given binary tree and finds the WordNode with the least count from a file

Parameters:
    start: a Wordnode for the highest root in the binary tree
Returns:
    a WordNode for the least common word in the tree
*/
extern WordNode* find_min(WordNode* start);
