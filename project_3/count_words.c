#include <stdio.h>
#include "binaryTree.h"

// prototypes
WordNode* find_max(WordNode* start);
WordNode* find_min(WordNode* start);

int main(int argc, char *argv[]) {
    // initialize a binary tree
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    InitializeTree(tree);

    // initilize a character array for words
    char word[20];

    // open the output file all_counts.txt
    FILE* outputF = fopen("all_counts.txt", "w");
    if (outputF == NULL) {
        printf("File not found.\n");
        return 0;
    }
    
    // open each file
    for (int i = 1; i < argc; i++) {
        FILE* f = fopen(argv[i], "r");
        if (f == NULL) {
            printf("File not found.");
            return 0;
        }

        // scan each word and add to binary tree
        while(fscanf(f, "%s", word) == 1) {
            AddItem(word, &*tree);
        }

        // close file
        fclose(f);
    }

    // call the printToFile function and print tree to the output file
    fprintf(outputF, "Counts\tWord\n");
    printToFile(tree, outputF);

    fclose(outputF);

    // call find_max and find_min and print results to the terminal
    WordNode* most_final = find_max(tree->root);
    WordNode* least_final = find_min(tree->root);

    if (most_final == NULL) {
        printf("Error");
    } else {
        printf("The most common word is \"%s\".\n", most_final->word);

    }

    if (least_final == NULL) {
        printf("Error");
    } else {
        printf("The least common word is \"%s\".\n", least_final->word);
    }
    
    // clear memory
    DeleteAll(tree);
    free(tree);

    return 1;
}

WordNode* find_max(WordNode* start) {
    if (start == NULL) {
        return NULL;
    }

    // initialize variables
    WordNode* mostWord = NULL;
    int maxCount = 0;

    // declare current and last to use for traversal
    WordNode* current = start;
    WordNode* last = NULL;

    // traverse tree and update maxCount and mostWord
    while (current != NULL) {
        if (current->left == NULL) {
            if (current->count > maxCount) {
                maxCount = current->count;
                mostWord = current;
            }

            current = current->right;
        } else {
            last = current->left;
            while (last->right != NULL && last->right != current) {
                last = last->right;
            }

            if (last->right == NULL) {
                last->right = current;
                current = current->left;
            } else {
                last->right = NULL;
                if (current->count > maxCount) {
                    maxCount = current->count;
                    mostWord = current;
                }

                current = current->right;
            }
        }
    }

    return mostWord;
}

WordNode* find_min(WordNode* start) {
    if (start == NULL) {
        return NULL;
    }

    // initialize variables
    WordNode* leastWord = start;
    int minCount = start->count;

    // declare current and last to use for traversal
    WordNode* current = start;
    WordNode* last = NULL;

    // traverse tree and update minCount and leastWord
    while (current != NULL) {
        if (current->left == NULL) {
            if (current->count < minCount) {
                minCount = current->count;
                leastWord = current;
            }

            current = current->right;
        } else {
            last = current->left;
            while (last->right != NULL && last->right != current) {
                last = last->right;
            }

            if (last->right == NULL) {
                last->right = current;
                current = current->left;
            } else {
                last->right = NULL;
                if (current->count < minCount) {
                    minCount = current->count;
                    leastWord = current;
                }

                current = current->right;
            }
        }
    }

    return leastWord;
}
