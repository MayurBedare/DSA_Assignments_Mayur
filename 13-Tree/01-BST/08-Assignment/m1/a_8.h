#ifndef BST_H //if  not defined yet
#define BST_H //define if now(first time use)

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

BST* create(BST *root);
void countNodes (const BST* root,int* Count);
void inorder (BST *root);

#endif