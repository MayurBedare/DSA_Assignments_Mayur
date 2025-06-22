/*
    A-8 ->  Write a C program to create BST and Count and Display total number of nodes
*/

#include<stdio.h>
#include "a_8.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    int count;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    inorder(root);
    printf("\n");

    count = 0;
    countNodes (root, & count);
    printf("\n\t Total nodes: %d \n", count);
    printf("\n");

    return 0;   
}