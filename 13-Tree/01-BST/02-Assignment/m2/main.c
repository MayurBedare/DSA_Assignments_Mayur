/*
    A-2 ->  Wrtie a C program to create BST and insert an element in the BST
*/

/*
    Tree created : 

                    10
                   /   \
                  8      15
                 / \       \
                5   9       30
*/ 

#include "A-2_BST_insertion.h"
#include "../01-Assignment/A-1_BST_Create.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    bst *root,*p = NULL;

    root = create(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    print(root);
    printf("\n\n");

    insert(root);

    printf("\n\t Printing of the given Tree in Inorder Traversal : \n\n\t");
    print(root);
    printf("\n\n");

    return 0;   
}

/*
    Tree after insertion of 7 : 

                    10
                   /   \
                  8      15
                 / \    /  \
                5   9  7    30
*/