#ifndef BST_H //if  not defined yet
#define BST_H //define if now(first time use)

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

int flag;

BST* create(BST *root);
BST* createBinaryTree(BST *root);
void print(BST *root);
int validateTree(BST*,int);
void freeTree(BST*);

#endif