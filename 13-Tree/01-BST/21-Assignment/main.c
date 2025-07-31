/*
    A-21 -> Write a C program to print Lowest common annestor of 2 nodes in a BST  
*/

#include<stdio.h>
#include "A-21.h"

int main() {
    printf("\n\t ***** Creating BST ***** \n");

    BST *root = NULL;
    int n1,n2,la1,la2,lca;

    root = create(root);

    printf(" \n\t Enter value 1 and 2 : ");
    scanf("%d %d",&n1,&n2);

    if (n1 == root->data || n2 == root->data) {
        lca = root->data;
    } else {
        la1 = lowestCommonAncestor(root,n1);
        la2 = lowestCommonAncestor(root,n2);
        if (la1 == n1 || la2 == n1) {
            lca = n1;
        } else if (la1 == n2 || la2 == n2) {
            lca = n2;
        } else {
            while (la1 != la2) {
                la1 = lowestCommonAncestor(root,la1);
                la2 = lowestCommonAncestor(root,la2);
            }
            lca = la1;
        }
    }
    
    printf("\n\t The Lowest Common Ancestor of the given two nodes : %d \n\n",lca);

    freeTree(root);

    return 0;   
}