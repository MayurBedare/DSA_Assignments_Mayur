/*
    A-11 ->  Wrtie a C program to find the maximum element in the BST.
*/

#include<stdio.h>
#include "a_11.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    inorder(root);
    printf("\n");

    printf("\n\t Maximum element: %d \n", findMax (root));

    freeTree(root);

    return 0;   
}