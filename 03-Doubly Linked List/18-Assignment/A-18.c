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
void createCycle(DLLNode*,DLLNode**,DLLNode**);
void detectCycle(DLLNode*,DLLNode*);
void displayDLL(DLLNode*,DLLNode*,DLLNode*,DLLNode*);
void freeDLL(DLLNode*,DLLNode*,DLLNode*);

int main() {

    printf("\n\t ***** Cycle Detection in Doubly Linked List ***** \n");

    while(1) {
        DLLNode *head = NULL,*p = NULL,*temp = NULL;
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
                head = createDLL();
                createCycle(head,&p,&temp);
                freeDLL(head,p,temp);
                break;

            case 2:
                freeDLL(head,p,temp);
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

DLLNode* createDLL() {

    DLLNode *head,*last = NULL, *nw;
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
            last -> next = nw;
            nw -> prev = last;
        }
        
        last = nw;

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

void createCycle(DLLNode *head,DLLNode **p,DLLNode **temp) {
    DLLNode *q = NULL;
    (*p) = q = head;
    int m,n;

    printf("\n\t ----------------------------------------------------------");
    printf("\n\t Note : Enter -1 for no cycle \n"); 
    printf("\n\t      : Enter 0 to n-1/m-1 where n/m is total no. of nodes in linked list \n");
    printf("\n\t Enter the position of nth node where m's next points, to make cycle : ");
    printf("\n\t Enter m and n : ");
    scanf("%d %d",&m,&n);
    
    if (m != -1 && n != -1 && m >= n) {   
        for (int i = 0 ; i < m && (*p) != NULL ; i++,(*p) = (*p) -> next);  
        for (int i = 0 ; i < n && q != NULL ; i++,q = q -> next);
        (*temp) = (*p) -> next;
        (*p) -> next = q;
    }

    displayDLL(head,*p,q,*temp);
    if ((*p) -> next == q) {
        printf("\n\n\t Nodes having cycle in it : \n");
        printf("\n\t |_%p_|_%d_|_%s_|_%p_| --> |_%p_|_%d_|_%s_|_%p_| \n", (*p) -> prev, (*p) -> number, (*p) -> name, (*p) -> next, q -> prev, q -> number, q -> name, q -> next);
    }
    detectCycle(*p,q);
}

void detectCycle(DLLNode *p,DLLNode *q) {
    int flag = 0;
     
    if (p -> next == q)   flag = 1;

    if (flag == 1) 
        printf("\n\t Cycle is detected in the given linked list.\n");
    else
        printf("\n\t No cycle detected in the given linked list.\n");
}

void displayDLL(DLLNode *d,DLLNode *p,DLLNode *q,DLLNode *temp) {

    if (p -> next != q) {
        printf("\n\t Doubly Linked List without cycle : \n");
        printf("\n\t |_Head_| ");
        for ( ; d != NULL ; d = d -> next )
            printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next); 
    } else {
        printf("\n\t Doubly Linked List with cycle : \n");
        printf("\n\t |_Head_| ");
        for ( ; d != p ; d = d -> next ) {
            printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);
        }
        if (temp == NULL) {
            printf("<--> |_%p_|_%d_|_%s_|_%p_| ", p -> prev, p -> number, p -> name, p -> next);
            return;
        } else {
            printf("<--> |_%p_|_%d_|_%s_|_%p_| <-- |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next, temp -> prev, temp -> number, temp -> name, temp -> next);
        }
        for (temp = temp -> next ; temp != NULL ; temp = temp -> next) {
            printf("<--> |_%p_|_%d_|_%s_|_%p_| ", temp -> prev, temp -> number, temp -> name, temp -> next);
        }
    }

    printf("\n");

}

void freeDLL(DLLNode *f,DLLNode *p,DLLNode *temp) {
    while (f != p) {
        f = f -> next;
        free(f -> prev);
    }
    free(f);
    f = NULL;
    if (temp != NULL) {
        while (temp -> next != NULL) {
            temp = temp -> next;
            free(temp -> prev);
        }
        free(temp);
    }
}
