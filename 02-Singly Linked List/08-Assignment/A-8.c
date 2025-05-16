/*
    A-8 ->  write a c program to Create a Singly linked list and Insert a node in the given position.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SLLNode
{
    int number;
    char name[20];
    struct SLLNode *next;
} SLLNode;

SLLNode* createSLL();
void displaySLL(SLLNode*);
void freeSLL(SLLNode*);
SLLNode* positionNodeInsertion(SLLNode*);

int main() {
    SLLNode *head = NULL;

    printf("\n\t ***** Insert a node at the given position : Singly Linked List ***** \n");

    printf("\n\t -------------------------------------------------------------");
    printf("\n\t Create a linked list to insert a node at the given position : \n");
    printf("\t ------------------------------------------------------------- \n");

    head = createSLL();

    printf("\n\t ------------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displaySLL(head);
    
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
                head = positionNodeInsertion(head);
                break;
            
            case 2:
                freeSLL(head);
                head = NULL;
                printf("\n\t Program Exited Successfully. \n\n");
                exit(0);

            default: 
                printf("\n\t Invalid Choice Entered! \n");
                break;
        }
    }
    return 0;
}

SLLNode* createSLL() {

    SLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = (SLLNode*)malloc(sizeof(SLLNode));
        if (nw == NULL)
        {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\t Enter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

        nw -> next = NULL;

        if (head == NULL)
            head = nw;
        else 
            last -> next = nw;
        
        last = nw;

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

SLLNode* positionNodeInsertion(SLLNode *head) {

    SLLNode *nw = NULL,*p = NULL;
    p = head;

    int pos;
    printf("\n\t Enter the position of node to insert : ");
    scanf("%d", &pos);

    nw = (SLLNode*)malloc(sizeof(SLLNode));
    if (nw == NULL)
    {
        printf("\n\t Memory Allocation Failed!");
    }
    
    printf("\n\t Enter the number and name of new inserted node at Given position : ");
    scanf("%d", &(nw -> number));
    getchar();
    fgets(nw -> name,20,stdin);
    nw -> name[strcspn(nw -> name,"\n")] = '\0';

    nw -> next = NULL;

    if (pos == 1) {
        nw -> next = head;
        head = nw;
    } else {
        for (int i = 1 ; i < pos-1 && p != NULL ; p = p -> next, i++);

        if (p != NULL) {
            nw -> next = p -> next;
            p -> next = nw;
        } else {
            printf("\n\t Invalid Position Entered! \n");
            free(nw);
            nw = NULL;
        }
    }

    if (p != NULL) {
        printf("\n\t Linked list after Insertion of node at given position : ");
        displaySLL(head);
    }

    return head;

}

void displaySLL(SLLNode *d) {

    printf("\n\n\t |_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("\n");

}

void freeSLL(SLLNode *f) {
    SLLNode *t = NULL;

    while (f != NULL) {
        t = f;
        f = f -> next;
        free(t);
    }
}
