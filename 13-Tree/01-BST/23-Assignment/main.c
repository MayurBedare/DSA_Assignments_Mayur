/*
    A-23 -> Write a C program to Print path from root to given node [target node]
*/

#include<stdio.h>
#include "A-23.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    int val;

    root = create(root);

    printf(" \n\t Enter value of target node : ");
    scanf("%d",&val);
    
    printf("\n\t Printing path from root to target node ie. %d : \n \n\t",val);
    printPath(root,val);
    printf("\n\n");

    freeTree(root);

    return 0;   
}