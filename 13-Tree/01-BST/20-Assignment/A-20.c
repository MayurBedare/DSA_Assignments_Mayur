#include <stdio.h>
#include <stdlib.h>
#include "A-20.h"

BST* createBinaryTree(BST* root) {
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
            char dir[10];
            printf("\n\t Tell me these node is be attached to left or right (l/r) : ");
            scanf(" %s",&dir);

            p = root;
            for (int i = 0 ; dir[i] != '\0' && p != NULL ; i++) {
                if (dir[i] == 'l') {
                    if (p -> left == NULL) {
                        p -> left = nw;
                        break;
                    } 
                    p = p -> left;
                } else {
                    if (p -> right == NULL) {
                        p -> right = nw;
                        break;
                    } 
                    p = p -> right;
                } 
            }
        }
        printf("\n\t Do you want to enter more numbers ( Yes (1) / No (0) ) : ");
        scanf("%d",&ch);
    } while (ch != 0);

    return root;
}

int validateTree(BST *root, int val) {
    if (root == NULL) return 0; 

    int check = 0;

    if (root->left != NULL) {
        if (flag == 0) {
            if (root->left->data >= val)    check = 1;
        } else {
            if (root->left->data <= val)    check = 1;
        }
        if (check == 0) {
            if (root->left->data <= root->data)    check = validateTree(root->left, root->data);
            else    check = 1;
        }
        else    goto invalid;
    }

    if (root->right != NULL) {
        if (root->data == val)  flag = 1;
        if (flag == 0) {
            if (root->right->data >= val)   check = 1;
        } else {
            if (root->right->data <= val)   check = 1;
        }
        if (check == 0) {
            if (root->right->data >= root->data)   check = validateTree(root->right, root->data);
            else    check = 1;
        }
        else    goto invalid;
    }

    return 0; 

invalid:
    return 1; 
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