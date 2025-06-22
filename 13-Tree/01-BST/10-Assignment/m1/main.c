/*
    A-10 ->  Write a C program to create BST and Deallocate memory by freeing all nodes in the BST
*/

#include<stdio.h>
#include "a_10.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    inorder(root);
    printf("\n");

    freeTree (root);
    printf("\n\t Existing...\n");

    return 0;   
}