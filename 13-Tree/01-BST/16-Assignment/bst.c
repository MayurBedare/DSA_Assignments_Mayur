#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

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

BST* insert (BST* root, int data) {
     if(root == NULL) {
        BST* newNode = (BST*) malloc (sizeof(BST));
        newNode -> data = data;
        newNode -> left = newNode -> right = NULL;
        return newNode;
     }
     if (data < root -> data)
        root -> left = insert(root -> left, data);
    else if (root -> data)
        root -> right = insert (root -> right, data);

    return root;
}

void inorder (const BST* root) {
    if (root) {
        inorder (root -> left);
        printf(" %d ", root -> data);
        inorder (root -> right);
    }
}

void preorder (const BST* root) {
    if (root) {
        printf(" %d ", root -> data);
        preorder( root -> left);
        preorder (root -> right);
    }
}

void postorder (const BST* root) {
    if (root) {
        postorder (root -> left);
        postorder (root -> right);
        printf(" %d ", root -> data);
    }
}

int searchRecursive (const BST* root, int key) {
    if (root == NULL) return 0;
    if (root -> data == key) return 1;
    if (key < root -> data)
          return searchRecursive (root -> left, key);
    return searchRecursive (root -> right, key);
}

int searchIterative (const BST* root, int key) {
    const BST* current = root;
    while(current) {
    if (current -> data == key) return 1;
    if (key < current -> data)
        current = current -> left;
    else
        current = current -> right;
    }
    return 0;   
}
 
void countNodes (const BST* root, int* count){
    if (root) {
        (*count)++;
        countNodes(root -> left, count);
        countNodes(root -> right, count);
    }
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

void freeTree (BST* root){
    if(root){
        freeTree (root -> left);
        freeTree (root -> right);
        free (root);
    }
}

int findMax(const BST *root) {
    if (!root) return -1;
    
    while (root -> right) {
        root = root -> right;
    }

    return root -> data;
}

int findHeight(const BST *root) {
    if (!root) return 0;

    int LH = findHeight(root->left);
    int RH = findHeight(root->right);
    return(LH>RH ? LH : RH) + 1;
}

void countLeafNonLeaf(const BST *root, int *leaf , int *nonleaf) {
    if (!root) {
        if (!root->left && !root->right) {
            (*leaf)++;
        } else {
            (*nonleaf)++;
            countLeafNonLeaf(root->left,leaf,nonleaf);
            countLeafNonLeaf(root->right,leaf,nonleaf);
        }
    }
}

void printLeafNodes (const BST *root) {
    if(root) {
        if(!root->left && !root->right) {
            printf("%d",root->data);
        } else {
            printLeafNodes(root->left);
            printLeafNodes(root->right);
        }
    }
}