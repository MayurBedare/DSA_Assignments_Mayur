/*
    A-9 ->  write a c program to create a circular singly linked list and delete the node by position
*/

/*
    Input -> |_Head_| --> |_1_|_AA_|_00771388_| --> |_2_|_BB_|_007713B0_| --> |_3_|_CC_|_00772FC0_| <-- |_last_| 
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
SCLLNode* deletePos(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    last = createSCLL();

    printf("\n\t Singly Circular Linked List : ");
    displaySCLL(last);

    last = deletePos(last);

    if (last == NULL) {
        printf("\n\t Singly Circular Linked List is empty!\n\n");
        exit(0);
    }

    printf("\n\t Singly Circular Linked List after deletion of node at given position : ");
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

SCLLNode* deletePos(SCLLNode *last) {

    int pos;
    SCLLNode *d = NULL,*prev = NULL;
    d = last -> next;

    printf("\n\t Enter the position of the node to be deleted from the given linked list : ");
    scanf("%d",&pos);

    if (pos == 1) {
        if (d == last) {
            free(d);
            d = NULL;
            return d;
        }
        last -> next = d -> next;
        free(d);
        d = NULL;
    } else {
        int i;
        for (prev = d,d = d -> next,i = 1 ; i < (pos - 1) && d != last ; prev = prev -> next,d = d -> next,i++);

        if (d != last) {
            prev -> next = d -> next;
            free(d);
            d = NULL;
        } else {
            if (i == (pos - 1)) {
            prev -> next = d -> next;
            last = prev;
            free(d);
            d = NULL;
            } else {
                printf("\n\t Invalid Position entered!\n\n");
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

            |_Head_| --> |_1_|_AA_|_00771388_| --> |_2_|_BB_|_007713B0_| --> |_3_|_CC_|_00772FC0_| <-- |_last_|


                    Enter the position of the node to be deleted from the given linked list : 2

                    Singly Circular Linked List after deletion of node at given position :

            |_Head_| --> |_1_|_AA_|_007713B0_| --> |_3_|_CC_|_00772FC0_| <-- |_last_|
*/

/*
    Position = 1 (Head Position) :

        Singly Circular Linked List : 

    |_Head_| --> |_2_|_BB_|_007713B0_| --> |_3_|_CC_|_007713B0_| <-- |_last_|
*/

/*
    Position = 2 (Middle Position) :

        Singly Circular Linked List : 

    |_Head_| --> |_1_|_AA_|_007713B0_| --> |_3_|_CC_|_00772FC0_| <-- |_last_|
*/

/*
    Position = 3 (End Position) :

        Singly Circular Linked List : 

    |_Head_| --> |_1_|_AA_|_00771388_| --> |_2_|_BB_|_00772FC0_| <-- |_last_|
*/