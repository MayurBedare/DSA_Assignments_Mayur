#include <stdio.h>
#include <stdlib.h>
#include "A-19.h"

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
        nw -> visited = 0;

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
        size++;
    } while (ch != 0);

    return root;
}

void inorderStack(BST* root) {
    BST* temp = NULL;
   
    arr = (BST**)malloc(sizeof(BST*));
    if (!arr) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    arr[++top] = root;

    while (top != -1) {
        temp = arr[top];
        if (temp->visited == 0) {
            temp->visited = 1;
            if (temp->left == NULL && temp->right == NULL) {
                printf(" %d ",temp->data);
                --top;
            } else if (temp->right == NULL) {
                arr[++top] = temp->left;
            } else if (temp->left == NULL) {
                int t = top;
                arr[++top] = temp;
                arr[t] = temp->right;
            } else {
                int t = top;
                arr[++top] = temp;
                arr[++top] = temp->left;
                arr[t] = temp->right;
            }
        } else {
            printf(" %d ",temp->data);
            --top;
        }
    }

    free(arr);
    arr = NULL;
}

void freeTree(BST* root) {
    if (root == NULL)   return;
    freeTree(root->left);
    freeTree(root->right);

    free(root);
}