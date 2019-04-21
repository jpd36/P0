// author: jonathan pham
// // cs4280 program translation
// // p0 due 03/01/2019
// // ~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tree.h"

static const int WORD_SIZE = 16;

/* open file and create node within this function */
void createNode(tree_t *bst, FILE *inputFile) {
    char input[WORD_SIZE];
    fscanf(inputFile, "%s", input);
    node_t *newNode = (node_t *) malloc(sizeof(node_t));
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->key = strlen(input);
    strcpy(newNode->words, input);
    insert(newNode, bst);
}

/* while not end of file, build tree */
node_t * buildTree(FILE *inputFile) {
    tree_t bst = { .root = NULL };
    while (!feof(inputFile)) {
        createNode(&bst, inputFile);
    }
    return bst.root;
}

/* insert node into bst */
void insert(node_t *newNode, tree_t *bst) {
    if (bst->root == NULL) {
        bst->root = newNode;
    }
    else {
        insert2(newNode, bst->root);
    }
}

/* function to insert additional node from keyboard input into bst */
void insert2(node_t *newNode, node_t *currentNode) {
    if (newNode->key > currentNode->key) {
        if (currentNode->rightChild == NULL) {
            currentNode->rightChild = newNode;
        }
        else {
            insert2(newNode, currentNode->rightChild);
        }
    }
    else if (newNode->key == currentNode->key) {
        if (strstr(currentNode->words, newNode->words) == NULL) {
            strcat(currentNode->words, " ");
            strcat(currentNode->words, newNode->words);
        }
    }
    else {
        if (currentNode->leftChild == NULL) {
            currentNode->leftChild = newNode;
        }
        else {
            insert2(newNode, currentNode->leftChild);
        }
    }
}

/* traverse inorder function */
void traverseInorder(node_t *n, const char fileName[]) {
    const char fileExt[] = ".inorder";
    char outFile[strlen(fileName) + strlen(fileExt)];
    strcpy(outFile, fileName);
    strcat(outFile, fileExt);
    FILE *outFilePtr = fopen(outFile, "w");
    if (!outFilePtr) {
        printf("error: file %s could not be opened", outFile);
        exit(1);
    }
    printInorder(n, 0, outFilePtr);
    fclose(outFilePtr);
}

/* traverse preorder function */
void traversePreorder(node_t *n, const char fileName[]) {
    const char fileExt[] = ".preorder";
    char outFile[strlen(fileName) + strlen(fileExt)];
    strcpy(outFile, fileName);
    strcat(outFile, fileExt);
    FILE *outFilePtr = fopen(outFile, "w");
    if (!outFilePtr) {
        printf("error: file %s could not be opened", outFile);
        exit(1);
    }
    printPreorder(n, 0, outFilePtr);
    fclose(outFilePtr);
}

/* traverse postorder function*/
void traversePostorder(node_t *n, const char fileName[]) {
    const char fileExt[] = ".postorder";
    char outFile[strlen(fileName) + strlen(fileExt)];
    strcpy(outFile, fileName);
    strcat(outFile, fileExt);
    FILE *outFilePtr = fopen(outFile, "w");
    if (!outFilePtr) {
        printf("error: file %s could not be opened", outFile);
        exit(1);
    }
    printPostorder(n, 0, outFilePtr);
    fclose(outFilePtr);
}

/* print inorder traversal & depth to .txt file */
void printInorder(node_t *n, int depth, FILE *outFilePtr) {
    if (n != NULL) {
        printInorder(n->leftChild, depth + 1, outFilePtr);
        visitNode(n, depth, outFilePtr);
        printInorder(n->rightChild, depth + 1, outFilePtr);
    }
}

/* print preorder traversal & depth to .txt file */
void printPreorder(node_t *n, int depth, FILE *outFilePtr) {
    if (n != NULL) {
        visitNode(n, depth, outFilePtr);
        printPreorder(n->leftChild, depth + 1, outFilePtr);
        printPreorder(n->rightChild, depth + 1, outFilePtr);
    }
}

/* print postorder traversal & depth to .txt file */
void printPostorder(node_t *n, int depth, FILE *outFilePtr) {
    if (n != NULL) {
        printPostorder(n->leftChild, depth + 1, outFilePtr);
        printPostorder(n->rightChild, depth + 1, outFilePtr);
        visitNode(n, depth, outFilePtr);
    }
}

/* print node corresponding depth spaces*/
void visitNode(node_t *n, int depth, FILE *outFilePtr) {
    fprintf(outFilePtr, "%*s%d %s\n", depth * 2, "", n->key, n->words);
}
