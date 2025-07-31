/*
    A-2 ->  Write a C program to  Kth largest/smallest element in Binary Search Tree 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

int arr[20];
int top = -1;

BST* create(BST *root);
void freeTree(BST*);
void printKthLS(BST*);

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    int kl,ks;

    root = create(root);

    printKthLS(root);
    
    printf("\n\n\t Enter Kth value to find smallest elment : ");
    scanf("%d",&ks);

    printf("\n\t Enter Kth value to find smallest elment : ");
    scanf("%d",&kl);
    
    printf("\n\t The %dth smalles element in the given BST : %d \n",ks,arr[ks-1]);

    printf("\n\t The %dth smalles element in the given BST : %d \n\n",kl,arr[top-kl+1]);

    freeTree(root);

    return 0;   
}

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

void printKthLS(BST* root) {
    if (root) {
        printKthLS(root->left);
        arr[++top] = root->data;
        printKthLS(root->right);
    }
}

void freeTree(BST* root) {
    if (root == NULL)   return;
    freeTree(root->left);
    freeTree(root->right);

    free(root);
}
