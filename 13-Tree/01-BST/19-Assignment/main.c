/*
    A-19 -> Create a BST from a given set of integers perform inorder traversal of the BST using an explicit stack without recursion 
            constraints -> you must implement stack manually using structure
*/

#include<stdio.h>
#include "A-19.h"

BST **arr = NULL;
int size = 1;
int top = -1;

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Binary Tree in Inorder Traversal : \n\t Without recursion using stack of BST Structure Pointer \n\n\t");

    inorderStack(root);

    printf("\n\n");

    freeTree(root);

    return 0;   
}

/*
    Input ->    
                     5
                    / \
                   3   7
                  / \
                 2   4 
                 
    Output ->   2 3 4 5 7
*/