#include "A_2.h"

bst* create(bst* root) {
    bst *nw,*p = NULL;
    int ch;
    do {
        nw = (bst*)malloc(sizeof(bst));
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

void print(bst* root) {
    if (root) {
        print(root->left);
        printf(" %d ",root->data);
        print(root->right);
    } 
}

void freeTree(bst* root) {
    if (root == NULL)   return;

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

void insert(bst* root) {
    bst *nw,*p = NULL;
    nw = (bst*)malloc(sizeof(bst));
    if (nw == NULL) {
        printf("\n\t Memory Allocation Failed \n");
        exit(1);
    }

    printf("\n\t Enter the Data ie Number : ");
    scanf("%d",&(nw -> data));
    nw -> left = nw -> right = NULL;

    while (1) {
        p = root;
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