/*
    A-18 -> write a c program to Detect cycle in doubly linked list.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DLLNode
{
    int number;
    char name[20];
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

DLLNode* createDLL();
void createCycle(DLLNode*,DLLNode*);
void detectCycle(DLLNode*,DLLNode*);
void displayDLL(DLLNode*,DLLNode*);
void freeDLL(DLLNode*,DLLNode*);

int main() {
    
    DLLNode *head = NULL;
    DLLNode *last = NULL;

    printf("\n\t ***** Cycle Detection in Doubly Linked List ***** \n");

    head = createDLL(&last);

    while(1) {
        int ch;
        printf("\n\t ----------------------------------------------------------");
        printf("\n\t 1. Creation & Detection of cycle in the Doubly Linked List ");
        printf("\n\t 2. Exit ");
        printf("\n\t ----------------------------------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t ---------------------------------------------------------- \n");

        switch (ch) {
            case 1:
                createCycle(head,last);
                break;

            case 2:
                freeDLL(head,last);
                head = NULL;
                printf("\n\t Program Exited Successfully! \n\n");
                exit(0);
            
            default:
                printf("\n\t Invalid choice entered!\n");
                break;
        }
        
    }

    return 0;
}

DLLNode* createDLL(DLLNode **last) {

    DLLNode *head, *nw;
    head = NULL, nw = NULL;

    int cnt;

    do
    {
        nw = (DLLNode*)malloc(sizeof(DLLNode));
        if (nw == NULL) {
            printf("\n\t Memory Allocatin Failed! \n\n");
            exit(1);
        }

        printf("\n\t Enter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

        nw -> next = NULL;

        if (head == NULL) {
            head = nw;
            nw -> prev = NULL;
        }
        else {
            (*last) -> next = nw;
            nw -> prev = *last;
        }
        
        *last = nw;

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

void createCycle(DLLNode *head, DLLNode *last) {
    DLLNode *p = NULL;
    p = head;
    int pos;

    printf("\n\t Note : Enter -1 for no cycle \n"); 
    printf("\n\t      : Enter 0 to n-1 where n is total no. of nodes in linked list \n");
    printf("\n\t Enter the position of nth node where tail's next points, to make cycle : ");
    scanf("%d",&pos);
    
    if (pos != -1) {     
        for (int i = 0 ; i < pos && p != NULL ; i++,p = p -> next);
        last -> next = p;
    }

    displayDLL(head,last);
    detectCycle(head,last);
}

void detectCycle(DLLNode *head,DLLNode *last) {
    int flag = 0;
    
    for ( ; head != last -> next ; head = head -> next);
    
    if (head == last -> next && head != NULL)   flag = 1;

    if (flag == 1) 
        printf("\n\t Cycle is detected in the given linked list.\n");
        if (last -> next != NULL)   last -> next = NULL;
    else
        printf("\n\t No cycle detected in the given linked list.\n");
}

void displayDLL(DLLNode *d,DLLNode *last) {

    if (last -> next == NULL) {
        printf("\n\t Doubly Linked List without cycle : \n");
        printf("\n\t |_Head_| ");
        for ( ; d != NULL ; d = d -> next )
            printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next); 
    } else {
        printf("\n\t Doubly Linked List with cycle : \n");
        printf("\n\t |_Head_| ");
        for ( ; d != last ; d = d -> next ) {
                printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);
        }
        printf("<--> |_%p_|_%d_|_%s_|_%p_| -> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next, last -> next -> prev, last -> next -> number, last -> next -> name, last -> next -> next);
    }

    printf("\n");

}

void freeDLL(DLLNode *f,DLLNode *last) {
    while (f != last) {
        f = f -> next;
        free(f -> prev);
    }
    free(f);
}
