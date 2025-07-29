#include <stdio.h>
#include <stdlib.h>
#include "a_15.h"

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

        // if (root == NULL) {
        //     root = nw;
        // } else {
        //     p = root;
            // while(1) {
                root = insert(root,nw->data);
                // if (nw -> data < p -> data) {
                //     if (p -> left == NULL) {
                //         p -> left = nw;
                //         break;
                //     } 
                //     p = p -> left;
                // } else if (nw -> data > p -> data) {
                //     if (p -> right == NULL) {
                //         p -> right = nw;
                //         break;
                //     } 
                //     p = p -> right;
                // } else {
                //     printf("\n\t No is already exist. \n");
                //     break;
                // }
            // }
        // }
        printf("\n\t Do you want to enter more numbers ( Yes (1) / No (0) ) : ");
        scanf("%d",&ch);
    } while (ch != 0);

    return root;
}

BST* insert (BST* root, int data) {
     if(root == NULL) {
        BST* newNode = (BST*) malloc (sizeof(BST));
        newNode -> data = data;
        newNode -> left = newNode -> right = NULL;
        return newNode;
     }
     if (data < root -> data)
        root -> left = insert(root -> left, data);
    else if (data > root -> data)
        root -> right = insert (root -> right, data);
    else 
        printf("\n\t No is already exist. \n");

    return root;
}

void print(BST *root) {
    if (root) {
        print(root->left);
        printf(" %d ",root->data);
        print(root->right);
    } 
}

void freeTree(BST* root) {
    if (root == NULL)   return;
    freeTree(root->left);
    freeTree(root->right);

    free(root);
}