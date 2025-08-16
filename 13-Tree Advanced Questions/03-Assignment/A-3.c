/*
    A-3 ->  Write a C program to find inorder successor or predecessor of a given node in bst
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

int size = 0,i = 0;

BST* create(BST *root);
void prev_next_node(BST*,int[]);
void print(BST*);
void freeTree(BST*);

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    print(root);
    printf("\n");

    printf("\n\t ----- Finding inorder Successor or Predecessor ----- \n");
    int val,i = 0;
    int *arr = (int*)malloc(sizeof(int)*size);
    if (!arr) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    prev_next_node(root,arr);
    printf("\n\t Enter the value : ");
    scanf("%d",&val);
    for (int i = 0 ; i < size ; i++) {
        if (arr[i] == val) {
            if (i-1 != -1) printf("\n\t The inorder Predecessor of %d : %d \n",val,arr[i-1]);
            else    printf("\n\t THe inorder Predecessor of %d does not exist \n",val);
            
            if (i+1 != size)   printf("\n\t The inorder Successor of %d : %d \n\n",val,arr[i+1]);
            else    printf("\n\t The inorder Successor of %d does not exist \n\n",val);
        }
    }

    freeTree(root);
    free(arr);
    arr = NULL;

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
        size++;
    } while (ch != 0);

    return root;
}

void prev_next_node(BST* root,int arr[]) {
    if (root == NULL)   return;

    prev_next_node(root->left,arr);
    arr[i++] = root->data;
    prev_next_node(root->right,arr);
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

