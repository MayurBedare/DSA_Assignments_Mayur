/*
    A-12 ->  Wrtie a C program to calculate the height (depth) of the BST.
             The depth of a node is the number of edges present in path from the root node of a tree to that node.
*/

#include<stdio.h>
#include "a_12.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    inorder(root);
    printf("\n");

    printf("\n\t Height of BST: %d \n", findHeight (root));

    freeTree(root);

    return 0;   
}