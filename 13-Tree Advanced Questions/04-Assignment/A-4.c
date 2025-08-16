/*
    A-4 ->  Write a C program to check 2 BST are identitical or not 
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST* create(BST *root);
void print(BST*);
bool isSameTree(BST*,BST*);
void freeTree(BST*);

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root1 = NULL,*root2 = NULL;

    printf("\n\t Create BST 1 : ");
    root1 = create(root1);

    printf("\n\t Create BST 2 : ");
    root2 = create(root2);

    printf("\n\n\t Printing of the given Tree in Inorder Traversal : ");
    print(root1);

    printf("\n\n\t Printing of the given Tree in Inorder Traversal : ");
    print(root2);
    printf("\n");

    if (isSameTree(root1,root2))    printf("\n\t The given 2 BST are identical \n\n");
    else    printf("\n\t The given 2 BST are not identical \n\n");

    freeTree(root1);
    freeTree(root2);

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

bool isSameTree(BST* p, BST* q) {   
    if (p != NULL && q != NULL) {
        if (p->data != q->data)   return false;
        bool check;
        check = isSameTree(p->left,q->left);
        if (check == false)  return false;
        check = isSameTree(p->right,q->right);
        if (check == false)  return false;
    } 
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
        return false;
    }

    return true;
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


