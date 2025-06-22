/*
    A-13 -> Write a C program to count the number of leaf and non-leaf nodes.
*/

#include<stdio.h>
#include "a_13.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    inorder(root);
    printf("\n");

    int leaf = 0, nonleaf = 0;
    countLeafNonLeaf (root, &leaf, &nonleaf);
    printf("\n\t Leaf Nodes: %d, Non-leaf nodes: %d \n", leaf,nonleaf);

    return 0;   
}