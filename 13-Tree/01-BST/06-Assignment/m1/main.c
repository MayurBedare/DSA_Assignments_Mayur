/*
    A-6 ->  Wrtie a C program to create BST and Search an element in BST using iterative aproach 
*/

#include<stdio.h>
#include "a_6.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    int val;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    inorder(root);
    printf("\n");

    printf("\n\t Enter key to Search:");
    scanf("%d", & val);
    if(searchIterative (root,val))
    printf("\n\t Found \n");
    else
    printf("\n\t Not found \n");
    printf("\n");

    return 0;   
}