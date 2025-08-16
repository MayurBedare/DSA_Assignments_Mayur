/*
    A-1 ->  Write a C program to convert BST to sorted doubly Linked list  
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
    int visited;
} BST;

BST **arr = NULL;
int size = 0,top = -1;
BST* head = NULL;

BST* create(BST *root);
void convert2DLL(BST* root);
void displayDLL(BST*);
void print(BST*);
void freeDLL(BST*);

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;

    root = create(root);
    
    printf("\n\t Printing of the given Tree in Inorder Traversal : ");
    print(root);
    printf("\n");

    printf("\n\t ----- Converting to Doubly Linked List -----\n");
    convert2DLL(root);

    printf("\n\t Printing of the given Tree by converting it to Doubly linked list : \n");
    displayDLL(head);

    freeDLL(root);

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
        nw -> visited = 0;

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

void convert2DLL(BST* root) {
    BST* temp = NULL;
    BST* prev = NULL;   
   
    arr = (BST**)malloc(sizeof(BST*)*size);
    if (!arr) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    arr[++top] = root;

    while (top != -1) {
        temp = arr[top];
        if (temp->visited == 0) {
            temp->visited = 1;
            if (temp->left == NULL && temp->right == NULL) {
                if (head == NULL) {
                    head = temp;
                } else {
                    prev->right = temp;
                    temp->left = prev;
                }
                prev = temp;
                --top;
            } else if (temp->right == NULL) {
                arr[++top] = temp->left;
            } else if (temp->left == NULL) {
                int t = top;
                arr[++top] = temp;
                arr[t] = temp->right;
            } else {
                int t = top;
                arr[++top] = temp;
                arr[++top] = temp->left;
                arr[t] = temp->right;
            }
        } else {
            if (head == NULL) {
                head = temp;
            } else {
                prev->right = temp;
                temp->left = prev;
            }
            prev = temp;
            --top;
        }
    }

    free(arr);
    arr = NULL;
}


void print(BST *root) {
    if (root) {
        print(root->left);
        printf(" %d ",root->data);
        print(root->right);
    } 
}

void displayDLL(BST *d) {
    printf("\n\t |_Head_| ");
    for ( ; d != NULL ; d = d -> right )
        printf("<--> |_%p_|_%d_|_%p_| ", d -> left, d -> data, d -> right);

    printf("\n\n");

}

void freeDLL(BST *f) {
    BST *t = NULL;

    while (f != NULL) {
        t = f;
        f = f -> right;
        free(t);
    }
}

