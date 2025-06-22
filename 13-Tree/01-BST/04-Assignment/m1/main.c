/*
    A-4 ->  Wrtie a C program to create BST and Display the elements in the BST in PreOrder
*/

#include<stdio.h>
#include "a_4.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Preorder Traversal : \n\n\t");
    preorder(root);
    printf("\n\n");

    return 0;   
}