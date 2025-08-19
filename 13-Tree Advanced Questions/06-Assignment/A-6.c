/*
    A-6 ->  Write a C program to Merge 2 BST into a single balanced BST 
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
void createBST(BST*);
BST* insert(BST*,BST*);
BST* merge(BST**,int,int);
void print(BST*);
void freeTree(BST*);

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root1 = NULL,*root2 = NULL;

    printf("\n\t Create BST 1 : ");
    root1 = create(root1);

    printf("\n\t Create BST 2 : ");
    root2 = create(root2);

    printf("\n\n\t Printing of the given BST Tree 1 in Inorder Traversal : ");
    print(root1);

    printf("\n\n\t Printing of the given BST Tree 2 in Inorder Traversal : ");
    print(root2);
    printf("\n");

    printf("\n\t ----- Merging both BST 1 and BST 2 ----- \n");
    arr = (BST**)malloc(sizeof(BST*)*size);
    if (!arr) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    createBST(root1);
    createBST(root2);

    for (int x = 0; x < size-1; x++) {
        for (int y = x+1; y < size; y++) {
            if (arr[x]->data > arr[y]->data) {
                BST* temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }
    }

    root1 = merge(arr,0,size-1);

    printf("\n\n\t Printing of the given Merged BST Tree in Inorder Traversal : ");
    print(root1);
    printf("\n\n");

    freeTree(root1);

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
                    size--;
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

BST* merge(BST** arr,int i,int j) {
    if (i > j) return NULL;

    int mid = (i + j) / 2;

    arr[mid]->left = merge(arr, i, mid-1);
    arr[mid]->right = merge(arr, mid+1, j);

    return arr[mid];
}

void createBST(BST* root) {
    if (root == NULL)   return;

    createBST(root->left);
    arr[i++] = root;
    createBST(root->right);
}

BST* insert (BST* root,BST* nwNode) {
    if (root == NULL)   return nwNode;
    if (nwNode->data < root -> data)
        root -> left = insert(root -> left, nwNode);
    else if (nwNode->data > root -> data)
        root -> right = insert (root -> right, nwNode);
    else    printf("\n\t Duplicate Values ");

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