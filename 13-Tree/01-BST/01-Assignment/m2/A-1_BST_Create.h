#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
    int data;
    struct BST* left;
    struct BST* right;
} bst;

bst* create(bst*);
void print(bst*);
