// author: jonathan pham
// // cs4280 program translation
// // p0 due 03/01/2019
// // ~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef NODE_H
#define NODE_H

typedef struct node_t {
  int key;
  char words[128];
  struct node_t *leftChild;
  struct node_t *rightChild;
} node_t;

#endif
