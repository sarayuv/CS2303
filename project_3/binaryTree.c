#include "binaryTree.h"

/* protototypes for local functions */
static WordNode *MakeNode(char *pi);
static bool ToLeft(const char *i1, const char *i2);
static bool ToRight(const char *i1, const char *i2);
static void AddNode(WordNode *new_node, WordNode *root);
static int SeekItem(char *pi, const BinaryTree *ptree);
static void DeleteAllNodes(WordNode *ptr);
static void InOrderPrint(const WordNode *root);
static bool IsWord(const char *i1, const char *i2);
static void InOrderPrintFile(const WordNode *root, FILE *f1);
static int cleanUpWord(char *phrase, int size);
/*****************************************************
 * void InitializeTree(BinaryTree * ptree)
 *   Initialize a tree to empty
 * Input:
 *   ptree: points to a tree
 *******************************************************/
void InitializeTree(BinaryTree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

/*****************************************************
 * int TreeItemCount(const BinaryTree* ptree)
 *   Determine number of items in tree
 * Input:
 *   ptree: points to a tree
 * Returns:
 *   The number of items in the tree
 ******************************************************/
int TreeItemCount(const BinaryTree *ptree)
{
    return ptree->size;
}

/*****************************************************
 * bool TreeIsEmpty(const BinaryTree* ptree
 *   Determines if the tree is empty
 * Input:
 *   ptree: points to a tree
 * Returns:
 *   true if tree is empty returns false otherwise
 ******************************************************/
bool TreeIsEmpty(const BinaryTree *ptree)
{
    return (ptree->size == 0);
}

/*****************************************************
 * bool AddItem(const char* newWord, BinaryTree* ptree)
 *   Adds newWord to the tree
 * Input:
 *   newWord: character array of the word to add
 *   ptree: points to a tree
 * Returns:
 *   true if word was added to the tree.
 *   returns false otherwise
 * Calls: SeekItem, MakeNode, AddNode
 ******************************************************/
bool AddItem(char *newWord, BinaryTree *ptree)
{

    // make word lowercase and remove punctuation
    cleanUpWord(newWord, strlen(newWord));

    // See if word is already in the tree
    if (SeekItem(newWord, ptree) == 1)
    {
        return 0; // word was not added to tree
    }
    else
    {
        // Add word
        WordNode *new_node;
        new_node = MakeNode(newWord); /* points to new node */

        if (new_node == NULL)
        {
            fprintf(stderr, "Couldn't create node\n");
            return 0;
        }
        else
        {
            ptree->size++;

            if (ptree->root == NULL)            /* case 1: tree is empty */
                ptree->root = new_node;         /* new node is tree root */
            else                                /* case 2: not empty */
                AddNode(new_node, ptree->root); /* add node to tree */
            return 1;                           /* successful return */
        }
    }
}

/*****************************************************
 * static WordNode* MakeNode(const char* newWord)
 *   Makes a new node
 * Input:
 *   newWord: character array of the word to add
 * Returns:
 *   A node with newWord
 * Precondition: Assumes node is not already on the tree
 ******************************************************/
static WordNode *MakeNode(char *newWord)
{
    cleanUpWord(newWord, strlen(newWord));
    // create a new node on the heap
    WordNode *new_node = (WordNode *)malloc(sizeof(WordNode));

    // if node was create, set initial values
    if (new_node != NULL)
    {
        strcpy(new_node->word, newWord);
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->count = 1;
    }
    return new_node;
}

/*****************************************************
 * static void AddNode(WordNode* new_node, WordNode* root)
 *   Recursive function to add new_node to the tree
 * Input:
 *   new_node: The node to be added to the tree
 *   ptree: points to a tree
 * Calls: ToLeft, ToRight, IsWord, AddNode
 ******************************************************/
static void AddNode(WordNode *new_node, WordNode *root)
{

    // Go down the tree, finding the place to add the node
    // see if the word belongs on the left
    if (ToLeft(new_node->word, root->word))
    {
        if (root->left == NULL)    /* empty subtree */
            root->left = new_node; /* so add node here */
        else
            AddNode(new_node, root->left); /* else process subtree*/
    }
    // Otherwise try the right
    else if (ToRight(new_node->word, root->word))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    // check if the word matches this node
    else if (IsWord(new_node->word, root->word))
    {
        root->count++;
    }
    else
    {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

/*****************************************************
 * static bool ToLeft(const char* i1, const char* i2)
 *   See if the node containing i1 should go left of i2
 * Input:
 *   i1: character array of word in new node
 *   i2: character array of word in current node
 * Returns:
 *   true if i1 < i2, false otherwise
 ******************************************************/
static bool ToLeft(const char *i1, const char *i2)
{
    if (strcmp(i1, i2) < 0)
        return true;
    else
        return false;
}

/*****************************************************
 * static bool ToRight(const char* i1, const char* i2)
 *   See if the node containing i1 should go right of i2
 * Input:
 *   i1: character array of word in new node
 *   i2: character array of word in current node
 * Returns:
 *   true if i1 > i2, false otherwise
 ******************************************************/
static bool ToRight(const char *i1, const char *i2)
{
    if (strcmp(i1, i2) > 0)
        return true;
    else
        return false;
}

/*****************************************************
 * static bool IsWord(const char* i1, const char* i2)
 *   See i1 and i2 are the same word
 * Input:
 *   i1: character array of word in new node
 *   i2: character array of word in current node
 * Returns:
 *   true if i1 == i2, false otherwise
 ******************************************************/
static bool IsWord(const char *i1, const char *i2)
{
    if (strcmp(i1, i2) == 0)
        return true;
    else
        return false;
}

/*****************************************************
 * static int SeekItem(const char* newWord, const BinaryTree* ptree)
 *   looks for newWord in the tree
 * Input:
 *   newWord: The word to be added to the tree
 *   ptree: points to a tree
 * Returns:
 *   0 if word is not in the tree
 *   1 if it is in the tree
 * Calls: ToLeft, ToRight
 ******************************************************/
static int SeekItem(char *newWord, const BinaryTree *ptree)
{
    cleanUpWord(newWord, strlen(newWord));

    // create a pointer to the start of the tree
    WordNode *searchNode = ptree->root;
    if (searchNode == NULL)
        return 0; /* early return */

    while (searchNode != NULL)
    {
        // if newWord is < the word in searchNode, go left
        if (ToLeft(newWord, (searchNode->word)))
        {
            searchNode = searchNode->left;
        }
        // if newWord is > the word in searchNode, go left
        else if (ToRight(newWord, searchNode->word))
        {
            searchNode = searchNode->right;
        }
        else
        {
            /* must be same if not to left or right */
            searchNode->count = searchNode->count + 1;
            return 1;
        }
    }
    return 0; /* successful return */
}

/*****************************************************
 * bool InTree(const char* newWord, const BinaryTree* ptree)
 *   looks for newWord in the tree
 *
 * Input:
 *   newWord: The word to be added to the tree
 *   ptree: points to a tree
 * Returns:
 *   false if word is not in the tree
 *   true if it is in the tree
 * Calls: SeekItem
 ******************************************************/
bool InTree(char *newWord, const BinaryTree *ptree)
{
    cleanUpWord(newWord, strlen(newWord));
    if (SeekItem(newWord, ptree) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*****************************************************
 * void printTree (const BinaryTree* ptree)
 *   Prints the tree in order
 * Input:
 *   ptree: points to a tree
 * Calls: InOrderPrint
 ******************************************************/
void printTree(const BinaryTree *ptree)
{
    if (ptree != NULL)
        InOrderPrint(ptree->root);
}

/*****************************************************
 * static void InOrderPrint(const WordNode* root)
 *   Prints the tree in order
 * Input:
 *   root: current Node
 * Calls: InOrderPrint
 ******************************************************/
static void InOrderPrint(const WordNode *root)
{

    if (root != NULL)
    {
        InOrderPrint(root->left);
        printf("%d %s\n", root->count, root->word);
        InOrderPrint(root->right);
    }
}

/*****************************************************
 * void DeleteAll(BinaryTree* ptree)
 *   Deletes every node in the tree
 * Input:
 *   ptree: the tree to delete
 * Calls: DeleteAllNodes
 ******************************************************/
void DeleteAll(BinaryTree *ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

/*****************************************************
 * void DeleteAllNodes(WordNode* root)
 *   Deletes every node in a subtree
 * Input:
 *   root: the current node
 * Calls: DeleteAllNodes
 ******************************************************/
static void DeleteAllNodes(WordNode *root)
{
    WordNode *pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

/*****************************************************
 * void printTree (const BinaryTree* ptree, FILE* f1)
 *   Prints the tree in order to the file
 * Input:
 *   ptree: points to a tree
 *   f1: pointer to open outputfile
 * Calls: InOrderPrintFile
 ******************************************************/
void printToFile(const BinaryTree *ptree, FILE *f1)
{
    if (ptree != NULL) {
        InOrderPrintFile(ptree->root, f1);
    }
}

/***********************************************************
 * cleanUpWord(char* phrase, int size)
 *   Removes all punctuation and spaces from the phrase
 *   makes all letters lowercase
 * Input:
 *   phrase: character array of a phrase
 *   size: the number of characters in the array
 * Output:
 *   returns the number of characters in the new phrase
 ***********************************************************/
int cleanUpWord(char *phrase, int size)
{

    // remove spaces and punctuation and numbers
    for (int i = 0; i < size; i++)
    {
        // if this character is not a letter
        if (isalpha(phrase[i]) == 0)
        {
            // shift everything to the left in the array
            for (int j = i; j < size; j++)
            {
                phrase[j] = phrase[j + 1];
            }
            size = size - 1;
            i = i - 1;
        }
    }
    // make everything lowercase
    for (int i = 0; i < size; i++)
    {
        phrase[i] = tolower(phrase[i]);
    }
    return size;
}

/*****************************************************
 * static void InOrderPrintFile(const WordNode* root, FILE* f1)
 *   Prints the tree in order
 * Input:
 *   root: current Node
 *   f1: Open output file
 * Calls: InOrderPrintFile
 ******************************************************/
void InOrderPrintFile(const WordNode *root, FILE *f1) {
    if (root != NULL) {
        InOrderPrintFile(root->left, f1);
        fprintf(f1, "%d\t%s\n", root->count, root->word);
        InOrderPrintFile(root->right, f1);
    }
}

