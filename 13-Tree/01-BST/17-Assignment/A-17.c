#include <stdio.h>
#include <stdlib.h>
#include "A-17.h"

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

void delete(BST *root, int no) {
    BST* temp;
    if (no == root -> data) {
        if (root->left == NULL && root -> right == NULL) {
            free(root);
            root = NULL;
            return;
        }
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            int t = root->left->data;
            root->left->data = root->data;
            root->data = t;
            free(root->left);
            root->left = NULL;
            return;
        }
        if (root->right != NULL && root->right->left == NULL && root->right->right == NULL) {
            int t = root->right->data;
            root->right->data = root->data;
            root->data = t;
            free(root->right);
            root->right = NULL;
            return;
        }
        if (root->left != NULL && root -> left -> right != NULL) {
            temp = root->left->right;
            if (temp -> left == NULL && temp -> right == NULL) {
                int t = temp -> data;
                temp -> data = root->data;
                root->data = t;
                free(temp);
                temp = NULL;
                return;
            } else {
                delete(temp,temp->data);
            }
        } else {
            int t = root->data;
            root->data = root->left->data;
            root->left->data = t;
            free(root->left);
            root->left = NULL;
            return;
        }

        if (root->right != NULL && root -> right -> left != NULL) {
            temp = root->right->left;
            if (temp -> left == NULL && temp -> right == NULL) {
                int t = temp -> data;
                temp -> data = root->data;
                root->data = t;
                free(temp);
                temp = NULL;
                return;
            } else {
                delete(temp,temp->data);
            }
        } else {
            int t = root->data;
            root->data = root->right->data;
            root->right->data = t;
            free(root->right);
            root->right = NULL;
            return;
        }
    } else if (no < root->data) {
        delete(root->left,no);
    } else if (no > root->data) {
        delete(root->right,no);
    } else {
        printf("\n\t The given No. does not exist! \n\n");
    }
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