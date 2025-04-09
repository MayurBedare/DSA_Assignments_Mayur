/*
    A-3 ->  write a c program to Create a circular singly  linked list and insert a new node  at given position  
*/

/*
    Input -> |_Head_| --> |_1_|_AA_|_00E91388_| --> |_2_|_BB_|_00E913B0_| --> |_3_|_CC_|_00E92FC0_| <-- |_last_|
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SCLLNode
{
    int number;
    char name[20];
    struct SCLLNode *next;
} SCLLNode;

SCLLNode* createSCLL();
SCLLNode* insertPos(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    last = createSCLL();

    printf("\n\t Singly Circular Linked List : ");
    displaySCLL(last);
    
    last = insertPos(last);

    printf("\n\t Singly Circular Linked List after insertion of node at the given position : ");
    displaySCLL(last);

    freeSCLL(last);

    return 0;
    
}

SCLLNode* createSCLL() {

    SCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = malloc(sizeof(SCLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = nw;

        if (head == NULL) {
            head = nw;
        }
        else {
            last -> next = nw;
            nw -> next = head;
        }
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

SCLLNode* insertPos(SCLLNode *last) {

    SCLLNode *p = NULL;
    p = last -> next;

    SCLLNode *nw = NULL;
    nw = malloc(sizeof(SCLLNode));
    printf("\n\t Enter number and name of the node to be inserted at the given position : ");
    scanf("%d %s", &(nw -> number),nw -> name);

    int pos;
    printf("\n\t Enter the position where new node to be insereted : ");
    scanf("%d",&pos);

    if (pos == 1) {
        nw -> next = last -> next;
        last -> next = nw;
    } else {
        int i;
        for(i = 1 ; i < (pos - 1) && p != last ; i++, p = p -> next);

        if (p != last) {
            nw -> next = p -> next;
            p -> next = nw;
        } else {
            if (i == (pos - 1)) {
            nw -> next = p -> next;
            p -> next = nw;
            last = nw;
            } else {
                printf("\n\t Invalid position entered!\n\n");
                exit(0);
            }
        }
    }

    return last;

}

void displaySCLL(SCLLNode *last) {
    
    SCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n|_Head_| ");

    for ( ; d != last ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("--> |_%d_|_%s_|_%p_| <-- |_last_|", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSCLL(SCLLNode *last) {

    if (last == NULL)
        return;

    SCLLNode *f = NULL,*t = NULL;
    f = last -> next;

    while (f != last) {
        t = f;   
        f = f -> next;
        free(t);
        t = NULL;
    }
    
    free(f);
    f = NULL;
}

/*
    Output ->   
                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Singly Circular Linked List :

            |_Head_| --> |_1_|_AA_|_00E91388_| --> |_2_|_BB_|_00E913B0_| --> |_3_|_CC_|_00E92FC0_| <-- |_last_|


                    Enter number and name of the node to be inserted at the given position : 5 MM

                    Enter the position where new node to be insereted : 2

                    Singly Circular Linked List after insertion of node at the given position :

            |_Head_| --> |_1_|_AA_|_00E913D8_| --> |_5_|_MM_|_00E91388_| --> |_2_|_BB_|_00E913B0_| --> |_3_|_CC_|_00E92FC0_| <-- |_last_|
*/

/*
    Position = 1 (Head Position) :

        Singly Circular Linked List : 

    |_Head_| --> |_5_|_MM_|_next_| --> |_1_|_AA_|_next_| --> |_2_|_BB_|_next_| --> |_3_|_CC_|_next_| <-- |_last_| 
*/

/*
    Position = 2 (Middle Position) :

        Singly Circular Linked List : 

    |_Head_| --> |_1_|_AA_|_next_| --> |_5_|_MM_|_next_| --> |_2_|_BB_|_next_| --> |_3_|_CC_|_next_| <-- |_last_| 
*/

/*
    Position = 3 (End Position) :

        Singly Circular Linked List : 

    |_Head_| --> |_1_|_AA_|_next_| --> |_2_|_BB_|_next_| --> |_3_|_CC_|_next_| --> |_5_|_MM_|_next_| <-- |_last_| 
*/