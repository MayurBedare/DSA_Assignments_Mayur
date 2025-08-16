#ifndef BST_H //if  not defined yet
#define BST_H //define if now(first time use)

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
    int visited;
} BST;

BST **arr;
int size;
int top;

BST* create(BST *root);
void inorderStack(BST *root);
void print (BST *root);
void freeTree(BST*);

#endif