/*  A-2 ->  Write a C program to create BST and insert an element in the BST */

#include <stdio.h>
#include <stdlib.h>
#include "A-21.h"

BST* create(BST* root) {
    BST *nw,*p = NULL;
    int ch;
    do {
        nw = (BST*)malloc(sizeof(BST));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed \n");
            exit(1);
        }

        printf("\n\t Enter the Data ie Number : ");
        scanf("%d",&(nw -> data));
        nw -> left = nw -> right = NULL;

        if (root == NULL) {
            root = nw;

        } else {
            p = root;
            while(1) {
                if (nw -> data < p -> data) {
                    if (p -> left == NULL) {
                        p -> left = nw;
                        break;
                    } 
                    p = p -> left;
                } else if (nw -> data > p -> data) {
                    if (p -> right == NULL) {
                        p -> right = nw;
                        break;
                    } 
                    p = p -> right;
                } else {
                    printf("\n\t No is already exist. \n");
                    break;
                }
            }
        }
        printf("\n\t Do you want to enter more numbers ( Yes (1) / No (0) ) : ");
        scanf("%d",&ch);
    } while (ch != 0);

    return root;
}

int lowestCommonAncestor(BST* root,int n) {
    if (root->left != NULL && root->left->data == n) {
        return root->data; 
    } else if (root->right != NULL && root->right->data == n) {
        return root->data;
    } else if (n < root->data) {
        lowestCommonAncestor(root->left,n);
    } else if (n > root->data) {
        lowestCommonAncestor(root->right,n);
    }
}

void freeTree(BST* root) {
    if (root == NULL)   return;
    freeTree(root->left);
    freeTree(root->right);

    free(root);
}