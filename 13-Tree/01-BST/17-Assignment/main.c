/*
    A-17 -> Write a C program to Delete a node from BST & maintain BST properties
*/

#include<stdio.h>
#include "A-17.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    int val;

    root = create(root);

    print(root);
    printf("\n\n");

    printf("\n\t Enter the no. to be deleted from the given tree : ");
    scanf("%d",&val);

    delete(root,val);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    print(root);
    printf("\n\n");

    freeTree(root);

    return 0;   
}