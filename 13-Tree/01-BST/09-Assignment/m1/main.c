/*
    A-9 ->  Wrtie a C program to create BST and Count Odd and even elements in the BST
*/

#include<stdio.h>
#include "a_9.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    int even,odd;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    inorder(root);
    printf("\n");

    even = odd = 0;
    countEvenOdd (root, & even, & odd);
    printf("\n\t Even: %d, Odd: %d \n", even,odd);

    return 0;   
}