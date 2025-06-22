#include "../01-Assignment/A-1_BST_Create.h"
#include "A-2_BST_insertion.h"

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