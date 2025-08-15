/*
    A-20 -> Write a C program of a binary tree to check if it is a valid BST 
*/

#include<stdio.h>
#include "A-20.h"

int flag = 0;

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = createBinaryTree(root);

    printf("\n\t Printing of the given Binary Tree in Inorder Traversal : \n\n\t");
    print(root);
    printf("\n");

    if (!validateTree(root,root->data))  printf("\n\t The given Binary Tree is a Valid BST \n\n");
    else    printf("\n\t The given Binary Tree is not a Valid BST \n\n");

    freeTree(root);

    return 0;   
}

/*
    Input ->    
                     5
                    / \
                   2   8
                  / \
                 1   6 -> is wrong!
                 
    Output -> So Not Valid BST
*/