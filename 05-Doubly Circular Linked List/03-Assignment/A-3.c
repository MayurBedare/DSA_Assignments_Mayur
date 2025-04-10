/*
    A-3 ->  write a c program to Create a circular doubly  linked list and insert a new node  at given position.  
*/

/*
    Input -> |_Head_| <--> |_007213B0_|_1_|_AA_|_00721388_| <--> |_00722FC0_|_2_|_BB_|_007213B0_| <--> |_00721388_|_3_|_CC_|_00722FC0_|  <--> |_last_|
*/

#include<stdio.h>
#include<stdlib.h>

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

    last = createDCLL();

    printf("\n\t Circular Doubly Linked List : ");
    displayDCLL(last);

    last = insertPos(last);

    printf("\n\t Singly Circular Linked List after insertion of node at the given position : ");
    displayDCLL(last);
    
    freeDCLL(last);

    return 0;
    
}

DCLLNode* createDCLL() {

    DCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = malloc(sizeof(DCLLNode));

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

DCLLNode* insertPos(DCLLNode *last) {

    DCLLNode *p = NULL;
    p = last -> next;

    DCLLNode *nw = NULL;
    nw = malloc(sizeof(DCLLNode));
    printf("\n\t Enter number and name of the node to be inserted at the given position : ");
    scanf("%d %s", &(nw -> number),nw -> name);

    int pos;
    printf("\n\t Enter the position where new node to be insereted : ");
    scanf("%d",&pos);

    if (pos == 1) {
        nw -> next = last -> next;
        nw -> next -> prev = nw;
        nw -> prev = last;
        last -> next = nw;

    } else {
        int i;
        for(i = 1 ; i < (pos - 1) && p != last ; i++, p = p -> next);

        if (p != last) {
            nw -> next = p -> next;
            nw -> next -> prev = nw;
            nw -> prev = p;
            p -> next = nw;
        } else {
            if (i == (pos - 1)) {
            nw -> next = p -> next;
            nw -> prev = p;
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

void displayDCLL(DCLLNode *last) {

    DCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n|_Head_| ");
    printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);


    for (d = d -> next ; d != last -> next ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf(" <--> |_last_|");

    printf("\n\n");

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

/*
    Output ->
                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Circular Doubly Linked List :

            |_Head_| <--> |_007213B0_|_1_|_AA_|_00721388_| <--> |_00722FC0_|_2_|_BB_|_007213B0_| <--> |_00721388_|_3_|_CC_|_00722FC0_|  <--> |_last_|


                    Enter number and name of the node to be inserted at the given position : 5 MM

                    Enter the position where new node to be insereted : 2

                    Singly Circular Linked List after insertion of node at the given position :

            |_Head_| <--> |_007213B0_|_1_|_AA_|_007213D8_| <--> |_00722FC0_|_5_|_MM_|_00721388_| <--> |_007213D8_|_2_|_BB_|_007213B0_| <--> |_00721388_|_3_|_CC_|_00722FC0_|  <--> |_last_|
*/

/*
    Position = 1 (Head Position) :

        Singly Circular Linked List : 

    |_Head_| <--> |_prev_|_5_|_MM_|_next_| <--> |_prev_|_1_|_AA_|_next_| <--> |_prev_|_2_|_BB_|_next_| <--> |_prev_|_3_|_CC_|_next_|  <--> |_last_|
*/

/*
    Position = 2 (Middle Position) :

        Singly Circular Linked List : 

    |_Head_| <--> |_prev_|_1_|_AA_|_next_| <--> |_prev_|_5_|_MM_|_next_| <--> |_prev_|_2_|_BB_|_next_| <--> |_prev_|_3_|_CC_|_next_|  <--> |_last_|
*/

/*
    Position = 3 (End Position) :

        Singly Circular Linked List : 

    |_Head_| <--> |_prev_|_1_|_AA_|_next_| <--> |_prev_|_2_|_BB_|_next_| <--> |_prev_|_3_|_CC_|_next_| <--> |_prev_|_5_|_MM_|_next_| <--> |_last_|
*/