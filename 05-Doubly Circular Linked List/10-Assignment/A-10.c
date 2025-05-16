/*
    A-10 -> write a c program to create a circular doubly linked list and delete the node by position 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct DCLLNode
{
    int number;
    char name[20];
    struct DCLLNode *next;
    struct DCLLNode *prev;
} DCLLNode;

DCLLNode* createDCLL(DCLLNode*);
DCLLNode* deletePos(DCLLNode*);
void displayDCLL(DCLLNode*);
void freeDCLL(DCLLNode*);


int main() {
   
    DCLLNode *last = NULL;

    printf("\n\t ***** Deletion by position - Doubly Circular Linked List *****\n");
    while (1) {
        int ch;
        printf("\n\t ------------------------------------------------------");
        printf("\n\t 1. Create Doubly Circular Linked List ");
        printf("\n\t 2. Delete Doubly Cicular Linked List Node by Position ");
        printf("\n\t 3. Exit ");
        printf("\n\t ------------------------------------------------------");
        printf("\n\t Enter you choice : ");
        scanf("%d",&ch);
        printf("\t ------------------------------------------------------\n");

        switch (ch) {
            case 1:
                last = createDCLL(last);
                printf("\n\n\t Doubly Circular Linked List : ");
                displayDCLL(last);
                break;
            
            case 2:
                if (!last) {
                    printf("\n\t Doubly Circular Linked List is empty!\n");
                    break;
                }
                last = deletePos(last);
                break;

            case 3:
                freeDCLL(last);
                printf("\n\t Exiting by freeing the allocated memory for Doubly Circular Linked List\n\n");
                exit(0);
            
            default:
                printf("\n\t Invalid choice Entered! \n");
                break;
        }
    }

    return 0;
    
}

DCLLNode* createDCLL(DCLLNode *last) {
    int cnt;
    do
    {
        DCLLNode *nw = NULL;
        nw = (DCLLNode*)malloc(sizeof(DCLLNode));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\t Enter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);
        nw -> next = nw;
        nw -> prev = nw;

        if (last) {
            nw -> next = last -> next;
            nw -> prev = last;
            last -> next = nw;
        }
        last = nw;

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

DCLLNode* deletePos(DCLLNode *last) {
    int pos,i,flag = 0;
    DCLLNode *d = NULL,*prev = NULL;
    d = last -> next;

    printf("\n\t Enter the position of the node to be deleted from the given linked list : ");
    scanf("%d",&pos);

    for (i = 1 ; i < pos && d != last ; d = d -> next,i++);

    if (d != last) { // d is not last node 
        flag = 1;
        if (d != last -> next) { // d is not first node
            d -> prev -> next = d -> next;
            d -> next -> prev = d -> prev;
        } else { // d is first node
            last -> next = d -> next;
            d -> prev = last;
        }
        free(d);
        d = NULL;
    } else { // d is last node
        if (i == pos) { // indicates last node where last and d points
            flag = 1; 
            if (pos != 1) { // single doubly linked list node present 
                last = last -> prev;
                last -> next = d -> next;
                last -> next -> prev = last;
            }
            free(d);
            d = NULL;
        } else {
            printf("\n\t Invalid Position entered!\n");
        }
    }

    if (flag == 1) {
        printf("\n\t Linked List after deletion of node at the given position : ");
        displayDCLL(last);
    }

    return last;
}

void displayDCLL(DCLLNode *last) {
    DCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n\t |_Head_| ");

    for ( ; d != last ; d = d -> next )
        printf("<--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("<--> |_%d_|_%s_|_%p_| <--> |_last_|", d -> number, d -> name, d -> next);

    printf("\n");
}

void freeDCLL(DCLLNode *last) {
    if (!last)
        return;

    DCLLNode *f = NULL;
    f = last -> next;

    while (f != last -> next) {   
        f = f -> next;
        free(f -> prev);
        f -> prev = NULL;
    }
    
    free(f);
    f = NULL;
}