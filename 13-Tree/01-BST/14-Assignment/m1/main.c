/*
    A-14 -> Write a C program to print all leaf nodes of the BST.
*/

#include<stdio.h>
#include "a_14.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    inorder(root);
    printf("\n");

    printf("\n\t Leaf Nodes:");
    printLeafNodes (root);
    printf("\n");

    freeTree(root);

    return 0;   
}