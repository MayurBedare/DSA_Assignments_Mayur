/*
    A-15 ->  Write a C program to create BST and insert an element in the BST using recursion
             (Call insert function from create function)
*/

#include<stdio.h>
#include "a_15.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    int val;

    root = create(root);

    // printf(" \n\t Enter value : ");
    // scanf("%d",&val);

    // root = insert(root,val);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    print(root);
    printf("\n\n");

    freeTree(root);

    return 0;   
}