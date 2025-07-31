/*
    A-22 -> Write a C program to print all nodes in a given range [k1,k2]
*/

#include<stdio.h>
#include "A-22.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    int k1,k2;

    root = create(root);

    printf("\n\t Enter value k1 and k2 : ");
    scanf("%d %d",&k1,&k2);

    printf("\n\t The nodes present in a given range [%d,%d] : ",k1,k2);
    printRange(root,k1,k2);
    printf("\n\n");

    freeTree(root);

    return 0;   
}