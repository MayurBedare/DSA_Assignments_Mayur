/*
    A-1 ->  Write a C program to create BST (Binary Search Tree) 
*/

#include "A-1[BST_Create].c"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    bst *root,*p = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    print(root);
    printf("\n\n");

    return 0;   
}