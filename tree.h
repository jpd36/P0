// author: jonathan pham
// // cs4280 program translation
// // p0 due 03/01/2019
// // ~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef TREE_H
#define TREE_H
#include "node.h"
#include <stdio.h>

typedef struct {
  node_t *root;
} tree_t;

node_t * buildTree(FILE *);
void createNode(tree_t *, FILE *);
void insert(node_t *, tree_t *);
void insert2(node_t*, node_t *);
void traverseInorder(node_t *, const char []);
void traversePreorder(node_t *, const char []);
void traversePostorder(node_t *, const char []);
void printInorder(node_t *, int, FILE *);
void printPreorder(node_t *, int, FILE *);
void printPostorder(node_t *, int, FILE *);
void visitNode(node_t *, int, FILE *);
#endif
