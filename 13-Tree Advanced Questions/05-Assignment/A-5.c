/*
    A-5 ->  Write a C program to Convert an unbalanced BST to balanced BST 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST **arr = NULL;
int size = 0,i = 0;

BST* create(BST *root);
void createArrBST(BST*);
int calHeight(BST*);
BST* convert2BalTree(BST**,int,int);
void print(BST*);
void freeTree(BST*);

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    int lh = calHeight(root->left);
    int rh = calHeight(root->right);
    
    if (lh - rh <= 1 && rh - lh <= 1) {
        printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
        print(root);
        printf("\n\n");
        printf("\n\t The given BST is balanced . No need to balanced it... \n\n");
        exit(0);
    } else {
        printf("\n\t The given BST is not balanced.. \n");
        printf("\n\t ----- Balancing the given BST ----- \n");
        arr = (BST**)malloc(sizeof(BST*)*size);
        if (!arr) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        createArrBST(root);
        root = convert2BalTree(arr,0,size-1);

        printf("\n\t The given tree is now balanced ------ \n");
        printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
        print(root);
        printf("\n\n");
            
        free(arr);
        arr = NULL;
    } 


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
                    size--;
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

int calHeight(BST* root) {
    if (root == NULL)   return -1;

    int lh = 0,rh = 0;
    lh = calHeight(root->left);
    rh = calHeight(root->right);

    if (lh > rh)    return 1+lh;
    else    return 1+rh;
}

void createArrBST(BST* root) {
    if (root == NULL)   return;

    createArrBST(root->left);
    arr[i++] = root;
    createArrBST(root->right);
}

BST* convert2BalTree(BST** arr,int i,int j) {
    if (i > j) return NULL;

    int mid = (i + j) / 2;

    arr[mid]->left = convert2BalTree(arr, i, mid-1);
    arr[mid]->right = convert2BalTree(arr, mid+1, j);

    return arr[mid];
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

 

