// author: jonathan pham
// // cs4280 program translation
// // p0 due 03/01/2019
// // ~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tree.h"

int main(int argc, char *argv[]) {

    /* error and abort if file argument does not exist */
    if (argc > 2) {
        printf("ERROR: Expected an optional file argument\n");
        return 1;
    }
    FILE *inFilePtr = NULL;
    char *fileName = NULL;
    /* if file exists, append .input1 to the end, open file and process*/
    if (argc == 2) {
        const char fileExt[] = ".input1";
        fileName = (char *) malloc(sizeof(argv[1]));
        strcpy(fileName, argv[1]);
        char inFile[strlen(fileName) + strlen(fileExt)];
        strcpy(inFile, fileName);
        strcat(inFile, fileExt);
        inFilePtr = fopen(inFile, "r");
	/* if file error, abort with appropriate message */
        if (!inFilePtr) {
            printf("ERROR: File %s could not be openedi\n", inFile);
            return 1;
        }
    }
    /* create out txt file for traversals */
    else {
        const char outputFileName[] = "out";
        fileName = (char *) malloc(sizeof(outputFileName));
        strcpy(fileName, outputFileName);
        inFilePtr = stdin;
    }
    node_t *root = buildTree(inFilePtr);
    traverseInorder(root, fileName);
    traversePreorder(root, fileName);
    traversePostorder(root, fileName);

    fclose(inFilePtr); // close file
    free(fileName);
 
   return 0;

}
