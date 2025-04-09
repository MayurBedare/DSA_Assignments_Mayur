/*
    A-18 -> write a c program to Detect cycle in doubly linked list.
*/

/* 
    Input ->                        
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct DLLNode
{
    int number;
    char name[20];
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

DLLNode* createDLLWOC();
DLLNode* createDLLWC();
void displayDLLWOC(DLLNode*);
void displayDLLWC(DLLNode*);
void detectCycle(DLLNode*,DLLNode*);
void freeDLLWOC(DLLNode*);
void freeDLLWC(DLLNode*);


int main() {
    
    int x = 1;
    DLLNode *head = NULL;
    DLLNode *last = NULL;

    while(x) {
        int ch;
        printf("\n\t Creation of Doubly Linked List (with/without cycle):");
        printf("\n\t 1. Without cycle.");
        printf("\n\t 2. With cycle.");
        printf("\n\n\t Enter your choice :");
        scanf("%d",&ch);

        switch (ch) {
        case 1:
            head = createDLLWOC();
            printf("\n\t Doubly Linked List without cycle : ");
            displayDLLWOC(head);
            detectCycle(head,last);
            freeDLLWOC(head);
            x = 0;
            break;

        case 2:
            last = createDLLWC(); 
            x = 0;
            break;
        
        default:
            printf("\n\t Invalid choice entered!\n");
            x = 1;
            break;
        }
        
    }

    if (head != NULL) {
        printf("\n\t Doubly Linked List without cycle : ");
        displayDLLWOC(head);
        detectCycle(head,last);
        freeDLLWOC(head);
    }

    if (last != NULL) {
        printf("\n\t Doubly Linked List with cycle : ");
        displayDLLWC(last);
        detectCycle(head,last);
        freeDLLWC(last);
    }

    return 0;
    
}

DLLNode* createDLLWOC() {

    DLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = malloc(sizeof(DLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = NULL;

        if (head == NULL) {
            head = nw;
            nw -> prev = NULL;
        }
        else {
            last -> next = nw;
            nw -> prev = last;
        }
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

DLLNode* createDLLWC() {

    DLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = malloc(sizeof(DLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

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

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

void detectCycle(DLLNode *head, DLLNode *last) {
    
    int flag = 0;
    if (head != NULL) {
        flag = 0;
    }
    if (last != NULL) {

        DLLNode *p = NULL;
        p = last -> next;

        for ( ; p != last ; p = p -> next);

        if (p -> next == last -> next)
            flag = 1;
 
    }

    if (flag == 1) 
      printf("\n\t Cycle is detected in the given linked list.\n\n");
    else
        printf("\n\t No cycle detected in the given linked list.\n\n");
    

}

void displayDLLWOC(DLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf("\n\n");

}

void displayDLLWC(DLLNode *last) {

    DLLNode *d = NULL;
    d = last -> next;
    printf("\n\n|_Head_| ");

    for ( ; d != last ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf("<--> |_%p_|_%d_|_%s_|_%p_| <--> |_last_|", d -> prev, d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeDLLWOC(DLLNode *f) {

    if (f == NULL)
        return;

    while (f != NULL) {
        f = f -> next;
        free(f -> prev);
        f -> prev = NULL;
    }

    free(f);
    f = NULL;
    
}

void freeDLLWC(DLLNode *last) {

    if (last == NULL)
        return;

    DLLNode *f = NULL;
    f = last -> next;

    while (f != last) {   
        f = f -> next;
        free(f -> prev);
        f -> prev = NULL;
    }

    free(f);
    f = NULL;

}

/*
    Output ->
*/