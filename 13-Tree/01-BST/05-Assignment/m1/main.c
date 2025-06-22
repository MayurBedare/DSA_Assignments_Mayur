/*
    A-5 ->  Wrtie a C program to create BST and Display the elements in the BST in PostOrder
*/

#include<stdio.h>
#include "a_5.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Postorder Traversal : \n\n\t");
    postorder(root);
    printf("\n\n");

    return 0;   
}