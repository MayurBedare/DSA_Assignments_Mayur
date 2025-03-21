/*
    A-4 ->  write a c program to Create a doubly linked list and Insert the Node at given position.
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_1_|_AA_|_00C60D40_| <--> |_00C62F98_|_2_|_BB_|_00000000_|
    position = 2                   
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

DLLNode* createDLL();
void displayDLL(DLLNode*);
void freeDLL(DLLNode*);
DLLNode* insertPosition(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\tLinked List : ");
    displayDLL(head);

    head = insertPosition(head);

    printf("\n\tLinked list after Insertion of node at given position : ");
    displayDLL(head);
    
    freeDLL(head);

    return 0;
    
}

DLLNode* createDLL() {

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

DLLNode* insertPosition(DLLNode *head) {

    DLLNode *nw = NULL,*p = NULL;
    p = head;

    int pos;
    printf("\n\tEnter the position of node to insert : ");
    scanf("%d", &pos);

    nw = malloc(sizeof(DLLNode));
    if (nw == NULL)
    {
        printf("\n\tMemory Allocation Failed!");
    }
    
    printf("\n\tEnter the number and name of new inserted node at Given position : ");
    scanf("%d %s", &(nw -> number), nw -> name);

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
            printf("\n\tInvalid Position Entered!");
            free(p);
        }
    }

    return head;

}

void displayDLL(DLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeDLL(DLLNode *f) {

    for( ; f != NULL ; f = f -> next)
        free(f);

    f = NULL;
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