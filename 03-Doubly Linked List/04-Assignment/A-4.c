/*
    A-4 ->  write a c program to Create a doubly linked list and Insert the Node at given position.
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_1_|_AA_|_00C60D40_| <--> |_00C62F98_|_2_|_BB_|_00000000_|
    position = 2                   
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
void displayDLL(DLLNode*);
void freeDLL(DLLNode*);
DLLNode* insertPosition(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    printf("\n\t ***** Insert a node at the given position : Doubly Linked List ***** \n");

    printf("\n\t -------------------------------------------------------------");
    printf("\n\t Create a linked list to insert a node at the given position : \n");
    printf("\t ------------------------------------------------------------- \n");

    head = createDLL();

    printf("\n\t ------------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displayDLL(head);
    
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
                head = insertPosition(head);
                break;
            
            case 2:
                freeDLL(head);
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

DLLNode* createDLL() {

    DLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = (DLLNode*)malloc(sizeof(DLLNode));
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

DLLNode* insertPosition(DLLNode *head) {

    DLLNode *nw = NULL,*p = NULL;
    p = head;

    int pos;
    printf("\n\t Enter the position of node to insert : ");
    scanf("%d", &pos);

    nw = (DLLNode*)malloc(sizeof(DLLNode));
    if (nw == NULL)
    {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    printf("\n\t Enter the number and name of new inserted node at Given position : ");
    scanf("%d", &(nw -> number));
    getchar();
    fgets(nw -> name,20,stdin);
    nw -> name[strcspn(nw -> name,"\n")] = '\0';
    
    nw -> next = NULL;
    nw -> prev = NULL;

    if (pos == 1) {
        nw -> next = head;
        head -> prev = nw;
        head = nw;
    } else {
        for (int i = 1 ; i < pos-1 && p != NULL ; p = p -> next, i++);

        if (p != NULL) {
            nw -> next = p -> next;

            if (p -> next != NULL)
                p -> next -> prev = nw;

            p -> next = nw;
            nw -> prev = p;
        } else {
            printf("\n\t Invalid Position Entered! \n");
            free(nw);
            nw = NULL;
        }
    }

    if ( p != NULL) {
        printf("\n\t Linked list after Insertion of node at given position : ");
        displayDLL(head);
    }

    return head;

}

void displayDLL(DLLNode *d) {

    printf("\n\n\t |_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf("\n");

}

void freeDLL(DLLNode *f) {
    DLLNode *t = NULL;

    while (f != NULL) {
        t = f;
        f = f -> next;
        free(t);
    }
}

/*
    Output ->
                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List : 

            |_Head_| <--> |_00000000_|_1_|_AA_|_00C60D40_| <--> |_00C62F98_|_2_|_BB_|_00000000_| 


                    Enter the position of node to insert : 2

                    Enter the number and name of new inserted node at Given position : 5 MM

                    Linked list after Insertion of node at given position :

            |_Head_| <--> |_00000000_|_1_|_AA_|_00C60D68_| <--> |_00C62F98_|_5_|_MM_|_00C60D40_| <--> |_00C60D68_|_2_|_BB_|_00000000_|
*/

/*
    Position = 1 (Head Position) :

        Linked List : 

    |_Head_| <--> |_2E342D41_|_5_|_MM_|_00DB2F98_| <--> |_00DB0D68_|_1_|_AA_|_00DB0D40_| <--> |_00DB2F98_|_2_|_BB_|_00000000_| 
*/

/*
    Position = 2 (Middle Position) :

        Linked List : 

    |_Head_| <--> |_00000000_|_1_|_AA_|_00B00D68_| <--> |_00B02F98_|_5_|_MM_|_00B00D40_| <--> |_00B00D68_|_2_|_B_|_00000000_| 
*/

/*
    Position = 3 (End Position) :

        Linked List : 

    |_Head_| <--> |_00000000_|_1_|_AA_|_00CB0D40_| <--> |_00CB2F98_|_2_|_BB_|_00CB0D68_| <--> |_00CB0D40_|_5_|_MM_|_00000000_|
*/