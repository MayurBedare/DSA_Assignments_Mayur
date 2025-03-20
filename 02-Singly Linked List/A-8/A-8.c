/*
    A-8 ->  write a c program to Create a Singly linked list and Insert a node in the given position.
*/

/* 
    Input -> |_Head_| --> |_1_|_AA_|_00D40D40_| --> |_2_|_BB_|_00000000_| 
    position = 3             
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SLLNode
{
    int number;
    char name[20];
    struct SLLNode *next;
} SLLNode;

SLLNode* createSLL();
void displaySLL(SLLNode*);
void freeSLL(SLLNode*);
void positionNodeInsertion(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    positionNodeInsertion(head);

    freeSLL(head);

    return 0;
    
}

SLLNode* createSLL() {

    SLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = malloc(sizeof(SLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = NULL;

        if (head == NULL)
            head = nw;
        else 
            last -> next = nw;
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

void positionNodeInsertion(SLLNode *head) {

    SLLNode *nw = NULL,*p = NULL;
    p = head;

    int pos;
    printf("\n\tEnter the position of node to insert : ");
    scanf("%d", &pos);

    nw = malloc(sizeof(SLLNode));
    if (nw == NULL)
    {
        printf("\n\tMemory Allocation Failed!");
    }
    
    printf("\n\tEnter the number and name of new inserted node at Given position : ");
    scanf("%d %s", &(nw -> number), nw -> name);

    if (pos == 1) {
        nw -> next = head;
        head = nw;
        displaySLL(head);
    } else {
        for (int i = 1 ; i < pos-1 && p != NULL ; p = p -> next, i++);

        if (p != NULL) {
            nw -> next = p -> next;
            p -> next = nw;
        } else {
            printf("\n\tInvalid Position Entered!");
            free(p);
        }
        
        printf("\n\tLinked list after Insertion of node at given position : ");
        displaySLL(head);
    }

}

void displaySLL(SLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSLL(SLLNode *f) {

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

            |_Head_| --> |_1_|_AA_|_00D40D40_| --> |_2_|_BB_|_00000000_|


                    Enter the position of node to insert : 3

                    Enter the number and name of new inserted node at Given position : 5 MM

                    Linked list after Insertion of node at given position :

            |_Head_| --> |_1_|_AA_|_00D40D40_| --> |_2_|_BB_|_00D40D68_| --> |_5_|_MM_|_00000000_|
*/

/*
    Position = 1 (Head Position) :

        Linked List : 

    |_Head_| --> |_5_|_MM_|_00B22F98_| --> |_1_|_AA_|_00B20D40_| --> |_2_|_BB_|_00000000_| 
*/

/*
    Position = 2 (Middle Position) :

        Linked List : 

    |_Head_| --> |_1_|_AA_|_00B90D68_| --> |_5_|_MM_|_00B90D40_| --> |_2_|_BB_|_00000000_|
*/

/*
    Position = 3 (End Position) :

        Linked List : 

    |_Head_| --> |_1_|_AA_|_00D40D40_| --> |_2_|_BB_|_00D40D68_| --> |_5_|_MM_|_00000000_|
*/