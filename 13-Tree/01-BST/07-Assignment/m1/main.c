/*
    A-7 ->  Wrtie a C program to create BST and Search an element in BST using Recursion
*/

#include<stdio.h>
#include "a_7.h"

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
    if(searchRecursive (root,val))
    printf("\n\t Found \n");
    else
    printf("\n\t Not found \n");
    printf("\n");

    freeTree(root);

    return 0;   
}