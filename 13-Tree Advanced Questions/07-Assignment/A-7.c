/*
    A-7 ->  Write a C program to Construct BST from preorder or postorder 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST* preorder(BST*);
BST* postorder(BST*);
void print(BST*);
void freeTree(BST*);

int main() {
    BST *root = NULL;
    int ch;
    printf("\n\t ***** Creating BST ***** \n");
    printf("\n\t 1. For Preorder ");
    printf("\n\t 2. For postorder ");
    printf("\n\t Enter your choice : ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        root = preorder(root);
        break;
    
    case 2:
        root = postorder(root);
        break;

    default:
        printf("\n\t Invalid Choice Entered!\n\n");
        break;
    }

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    print(root);
    printf("\n\n");

    freeTree(root);

    return 0;   
}

BST* preorder(BST* root) {
    int n;
    printf("\n\t Enter the number of elements to be entered : ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    if (!arr) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Note : Enter each elements with one space Eg. 1 2 3 ");
    printf("\n\t Enter the preorder to construct BST : ");
    for (int i = 0 ; i < n ; i++) {
        scanf("%d",&arr[i]);
    }

    BST *nw,*p = NULL;
    int ch;
    for (int i = 0 ; i < n ; i++) {
        nw = (BST*)malloc(sizeof(BST));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed \n");
            exit(1);
        }

        nw->data = arr[i];
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
    }

    return root;
}

BST* postorder(BST* root) {
    int n;
    printf("\n\t Enter the number of elements to be entered : ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    if (!arr) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Note : Enter each elements with one space Eg. 1 2 3 ");
    printf("\n\t Enter the postorder to construct BST : ");
    for (int i = 0 ; i < n ; i++) {
        scanf("%d",&arr[i]);
    }

    BST *nw,*p = NULL;
    int ch;
    for (int i = n-1 ; i >= 0 ; i--) {
        nw = (BST*)malloc(sizeof(BST));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed \n");
            exit(1);
        }

        nw->data = arr[i];
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
    }

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

