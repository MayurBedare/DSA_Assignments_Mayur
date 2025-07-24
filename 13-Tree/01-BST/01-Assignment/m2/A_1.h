#ifndef BST_H //if  not defined yet
#define BST_H //define if now(first time use)

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
void freeTree(bst*);

#endif
