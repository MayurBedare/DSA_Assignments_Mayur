/*
    A-3 ->  Wrtie a C program to create BST and Display the elements in the BST in InOrder
*/

#include<stdio.h>
#include "a_3.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    inorder(root);
    printf("\n\n");

    return 0;   
}