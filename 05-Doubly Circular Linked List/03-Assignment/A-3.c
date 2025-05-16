/*
    A-3 ->  write a c program to Create a circular doubly  linked list and insert a new node  at given position.  
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DCLLNode
{
    int number;
    char name[20];
    struct DCLLNode *next;
    struct DCLLNode *prev;
} DCLLNode;

DCLLNode* createDCLL();
DCLLNode* insertPos(DCLLNode*);
void displayDCLL(DCLLNode*);
void freeDCLL(DCLLNode*);

int main() {
   
    DCLLNode *last = NULL;

    printf("\n\t ***** Insert a node at the given position : Doubly Circular Linked List ***** \n");

    printf("\n\t -------------------------------------------------------------");
    printf("\n\t Create a linked list to insert a node at the given position : \n");
    printf("\t ------------------------------------------------------------- \n");

    last = createDCLL();

    printf("\n\t ------------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displayDCLL(last);
    
    while (1) {
        int ch; 
        printf("\n\t --------------------------------------");
        printf("\n\t 1. Insert a node at the given position ");
        printf("\n\t 2. Exit ");
        printf("\n\t --------------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t -------------------------------------- \n");
        
        switch (ch) {
            case 1:
                last = insertPos(last);
                break;
            
            case 2:
                freeDCLL(last);
                last = NULL;
                printf("\n\t Program Exited Successfully. \n\n");
                exit(0);

            default: 
                printf("\n\t Invalid Choice Entered! \n");
                break;
        }
    }

    return 0;
    
}

DCLLNode* createDCLL() {

    DCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = (DCLLNode*)malloc(sizeof(DCLLNode));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\t Enter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

        nw -> next = nw;
        nw -> prev = nw;

        if (head == NULL) {
            head = nw;
        }
        else {
            last -> next = nw;
            nw -> prev = last;
            nw -> next = head;
            head -> prev = nw;
        }
        
        last = nw;

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

DCLLNode* insertPos(DCLLNode *last) {

    DCLLNode *p = NULL;
    p = last -> next;

    DCLLNode *nw = NULL;
    nw = (DCLLNode*)malloc(sizeof(DCLLNode));
    if (nw == NULL) {
    printf("\n\t Memory Allocation Failed! \n\n");
    exit(1);
    }

    printf("\n\t Enter number and name of the node to be inserted at the given position : ");
    scanf("%d", &(nw -> number));
    getchar();
    fgets(nw -> name,20,stdin);
    nw -> name[strcspn(nw -> name,"\n")] = '\0';

    nw -> prev = nw;
    nw -> next = nw;

    int pos,flag = 0;
    printf("\n\t Enter the position where new node to be insereted : ");
    scanf("%d",&pos);

    if (pos == 1) {
        flag = 1;
        nw -> next = last -> next;
        nw -> next -> prev = nw;
        nw -> prev = last;
        last -> next = nw;

    } else {
        int i;
        for(i = 1 ; i < (pos - 1) && p != last ; i++, p = p -> next);

        if (p != last) {
            flag = 1;
            nw -> next = p -> next;
            nw -> next -> prev = nw;
            nw -> prev = p;
            p -> next = nw;
        } else {
            if (i == (pos - 1)) {
                flag = 1;
            nw -> next = p -> next;
            nw -> prev = p;
            p -> next = nw;
            last = nw;
            } else {
                printf("\n\t Invalid position entered! \n");
                free(nw);
                nw = NULL;
            }
        }
    }

    if (flag == 1) {
        printf("\n\t Linked List after insertion of node at the given position : ");
        displayDCLL(last);
    }

    return last;

}

void displayDCLL(DCLLNode *last) {

    DCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n\t |_Head_| ");
    printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);


    for (d = d -> next ; d != last -> next ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf(" <--> |_last_|");

    printf("\n");

}

void freeDCLL(DCLLNode *last) {

    if (last == NULL)
        return;

    DCLLNode *f = NULL;
    f = last -> next;

    while (f != last) {   
        f = f -> next;
        free(f -> prev);
        f -> prev = NULL;
    }

    free(f);
    f = NULL;

}
