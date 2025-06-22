#include <stdio.h>
#include "bst.h"

int main(){
     BST* root = NULL;
     int choice,val, count = 0, even = 0, odd = 0;
     
     do{
       printf("\n----- BST Operations-----\n");
       printf("0.Create BST \n");
       printf("1.Insert \n 2.Inorder \n 3.Preorder \n 4.Postorder \n");
       printf("5.Search (Recursive) \n 6.Search (Iterative) \n");
       printf("7.Count Nodes \n 8.Count Even/Odd \n");
       printf("9.Find Max Element \n 10.Find Height\n");
       printf("11.Count Leaf/Non-Leaf Nodes\n 12.Print Leaf Nodes \n");
       printf("13.Exit \n");

       printf("Enter your choice:");
       scanf("%d", & choice);

       switch(choice) {
       case 0:
             root = create(root);
             break;
       case 1:
             printf("Enter value:");
             scanf("%d", & val);
             root = insert(root,val);
             break;
       case 2:
             printf("Inorder:");
             inorder(root);
             printf("\n");
             break;
        case 3:
             printf("Preorder:");
             preorder(root);
             printf("\n");
             break;
        case 4:
             printf("Postorder:");
             postorder(root);
             printf("\n");
             break;
        case 5:
             printf("Enter key to Search:");
             scanf("%d", & val);
             if(searchRecursive (root,val))
                printf("Found \n");
             else
                printf("Not found \n");
             break;
        case 6:
             printf("Enter key to Search:");
             scanf("%d", & val);
             if(searchIterative (root,val))
                printf("Found \n");
             else
                printf("Not found \n");
             break;
        case 7:
             count = 0;
             countNodes (root, & count);
             printf("Total nodes: %d \n", count);
             break;
        case 8:
             even = odd = 0;
             countEvenOdd (root, & even, & odd);
             printf("Even: %d, Odd: %d \n", even,odd);
             break;
        case 9:
             printf("Maximum element: %d \n", findMax (root));
             break;
        case 10:
             printf("Height of BST: %d \n", findHeight (root));
             break;
        case 11:{
             int leaf = 0, nonleaf = 0;
             countLeafNonLeaf (root, &leaf, &nonleaf);
             printf("Leaf Nodes: %d, Non-leaf nodes: %d \n", leaf,nonleaf);
             break;
        }
        case 12:
             printf("Leaf Nodes:");
             printLeafNodes (root);
             printf("\n");
             break;
        case 13:
             freeTree (root);
             printf("Existing...\n");
             break;
        default:
             printf("Invalid choice:\n");      
        }
     }  while(choice != 13);
    return 0;
}