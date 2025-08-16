/*
    A-8 ->  Write a C program to serilize a BST into a file & deserilize it  
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST* create(BST *root);
BST* insert(BST *root,int value);
void serialize(BST*,FILE*);
BST* deserialize(FILE*);
void print(BST*);
void freeTree(BST*);

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    FILE *fp = NULL;

    root = create(root);
    
    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    print(root);
    printf("\n");

    printf("\n\t ------ Serialization of BST ------ \n");
    char fName[20];
    printf("\n\t Enter the file name : ");
    scanf("%s",fName);
    fp = fopen(fName,"w");

    serialize(root,fp);
    fclose(fp);

    char ch;
    fp = fopen(fName, "r");
    if (fp == NULL) {
        printf("\n\t Error opening file!\n");
        return 1;
    }

    printf("\n\t Contents of file (serialized BST): ");

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    printf("\n\n\t ------ Deserialization of BST ------ \n");
    fp = fopen(fName,"r");   
    BST* newRoot = deserialize(fp);
    fclose(fp);

    printf("\n\t Printing Deserialized BST in Inorder Traversal : \n\n\t");
    print(newRoot);
    printf("\n\n");

    freeTree(root);
    freeTree(newRoot);

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

BST* insert (BST* root, int data) {
    if(root == NULL) {
        BST* newNode = (BST*) malloc (sizeof(BST));
        newNode -> data = data;
        newNode -> left = newNode -> right = NULL;
        return newNode;
    }
    if (data < root -> data)
        root -> left = insert(root -> left, data);
    else if (data > root -> data)   // FIXED
        root -> right = insert (root -> right, data);
    else    
        printf("\n\t Duplicate Values \n\n");

    return root;
}

void serialize(BST* root,FILE *fp) {
    if (root == NULL)   return;

    fprintf(fp,"%d ",root->data);   // add space
    serialize(root->left,fp);
    serialize(root->right,fp);
}

BST* deserialize(FILE* fp) {
    int value;
    BST* root = NULL;
    while (fscanf(fp,"%d",&value) != EOF) {
        root = insert(root,value);
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
