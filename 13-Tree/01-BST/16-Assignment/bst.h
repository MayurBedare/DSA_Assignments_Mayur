#ifndef BST_H //if  not defined yet
#define BST_H //define if now(first time use)

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
} BST;

//BST Operations
BST* create(BST *root);
BST* insert (BST* root,int data);
void inorder(const BST* root);
void preorder(const BST* root);
void postorder(const BST* root);
int searchRecursive (const BST* root,int key);
int searchIterative (const BST* root,int key);
void countNodes (const BST* root,int* Count);
void countEvenOdd (const BST* root,int* even,int* odd);
void freeTree (BST* root);
int findMax(const BST* root);
int findHeight(const BST* root);
void countLeafNonLeaf (const BST* root, int* leaf, int* nonleaf);
void printLeafNodes (const BST* root);

#endif