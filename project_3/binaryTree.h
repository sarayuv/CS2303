#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Adapted from Chapter 17 of C Primer Plus
// https://learning.oreilly.com/library/view/c-primer-plus/9780133432398/

struct wordNode
{
    int count;
    char word[50];
    struct wordNode * left;
    struct wordNode * right;
};

typedef struct wordNode WordNode;

struct binaryTree
{
    WordNode * root;
    int size;
};

typedef struct binaryTree BinaryTree;

/* operation: initialize a tree to empty
    preconditions: ptree points to a tree
    postconditions: the tree is initialized to empty */
void InitializeTree(BinaryTree * ptree);

/* operation: determine if tree is empty
    preconditions: ptree points to a tree
    postconditions: function returns true if tree is
                    empty and returns false otherwise */
bool TreeIsEmpty(const BinaryTree * ptree);

/* operation: determine number of items in tree
    preconditions: ptree points to a tree
    postconditions: function returns number of items in
                    tree */
int TreeItemCount(const BinaryTree * ptree);

/* operation: add an item to a tree
    preconditions: pi is address of item to be added
                    ptree points to an initialized tree
    postconditions: if possible, function adds item to
                    tree and returns true; otherwise,
                    the function returns false */
bool AddItem(char* pi, BinaryTree * ptree);

/* operation: find an item in a tree
    preconditions: pi points to an item
                    ptree points to an initialized tree
    postconditions: function returns true if item is in
                    tree and returns false otherwise */
bool InTree(char* pi, const BinaryTree* ptree);

/* operation: delete an item from a tree
    preconditions: pi is address of item to be deleted
                    ptree points to an initialized tree
    postconditions: if possible, function deletes item
                    from tree and returns true;
                    otherwise the function returns false*/
bool DeleteItem(const char* pi, BinaryTree* ptree);

/* operation: delete everything from a tree
    preconditions: ptree points to an initialized tree
    postconditions: tree is empty */
void DeleteAll(BinaryTree* ptree);

/* operation: Prints the tree in order to the termnal
    preconditions: ptree points to an initialized tree */
void printTree(const BinaryTree* root);

/* operation: Prints the tree in order to the output file
    preconditions: ptree points to an initialized tree
                    f1 points to an open output file */
void printToFile(const BinaryTree* root, FILE* f1);


/* operation: Prints the tree in order to the output file
    preconditions: ptree points to an initialized tree
                    f1 points to an open output file */
static void InOrderPrintFile(const WordNode *root, FILE *f1);


/* operation: Removes nonalpha characters and makes lowercase
    preconditions: phrase points to a character array
                    size is the lenght of the string in the character array
    postconditions: all non-alpha characters are removed */

#endif
