#include <stdio.h>
#include <stdlib.h>
#include "a_9.h"

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

void countEvenOdd (const BST* root, int* even, int * odd){
    if (root){
        if(root -> data % 2 == 0)
           (*even)++;
        else
           (*odd)++;
        countEvenOdd (root -> left, even,odd);
        countEvenOdd (root -> right, even,odd);
    }
}

void inorder(BST *root) {
    if (root) {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    } 
}