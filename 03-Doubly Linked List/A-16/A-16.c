/*
    A-16 -> write a c program to Re-Arrange doubly linked list in pair format.
            input -> 6 <-> 1 <-> 9 <-> 4 <-> 3 <-> 8 <-> 2
            output -> 1 <-> 6 <-> 4 <-> 9 <-> 3 <-> 8 <-> 2

            If first value is greater than second then swap  , if 3rd value is less than 4th then swap same for remaining pair
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_6_|_AA_|_00DD0D40_| <--> |_00DD2F98_|_1_|_BB_|_00DD0D68_| <--> |_00DD0D40_|_9_|_CC_|_00DD0D90_| <--> |_00DD0D68_|_4_|_DD_|_00DD0DB8_| <--> |_00DD0D90_|_3_|_EE_|_00DD0DE0_| <--> |_00DD0DB8_|_8_|_FF_|_00DD0E08_| <--> |_00DD0DE0_|_2_|_GG_|_00000000_|                          
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
void swapDLL(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\t Doubly Linked List : ");
    displayDLL(head);

    swapDLL(head);
    
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

void swapDLL(DLLNode *head) {

    DLLNode *swap1 = NULL, *swap2 = NULL, temp;
    swap1 = head, swap2 = swap1 -> next;

    if ( swap2 == NULL) {
        printf("\n\tDisplaying Swaping of Two Consecutive Nodes is not possible!\n\n");
    }
    else {
        for ( ; swap1 != NULL && swap2 != NULL ; swap1 = swap2 -> next, swap2 = swap1 -> next ) {
            
            if (swap1 -> number > swap2 -> number) {
                temp.number = swap1->number;
                swap1 -> number = swap2 -> number;
                swap2 -> number = temp.number;

                strcpy(temp.name, swap1 -> name);
                strcpy(swap1 -> name, swap2 -> name);
                strcpy(swap2 -> name, temp.name);
            }            

            if ( swap2 -> next == NULL )
                break;  

        }
        printf("\n\tLinked List with Swapping of two consecutive nodes having first node number greater than second : ");
        displayDLL(head);
    }

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
                 Enter Number and Name : 6 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 1 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 9 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 4 DD
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 EE
            Do you want to enter more records ( yes(1) / no(0) ) : 1


                    Enter Number and Name : 2 GG
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Doubly Linked List :

            |_Head_| <--> |_00000000_|_6_|_AA_|_00DD0D40_| <--> |_00DD2F98_|_1_|_BB_|_00DD0D68_| <--> |_00DD0D40_|_9_|_CC_|_00DD0D90_| <--> |_00DD0D68_|_4_|_DD_|_00DD0DB8_| <--> |_00DD0D90_|_3_|_EE_|_00DD0DE0_| <--> |_00DD0DB8_|_8_|_FF_|_00DD0E08_| <--> |_00DD0DE0_|_2_|_GG_|_00000000_|   


                    Linked List with Swapping of two consecutive nodes having first node number greater than second :

            |_Head_| <--> |_00000000_|_1_|_BB_|_00DD0D40_| <--> |_00DD2F98_|_6_|_AA_|_00DD0D68_| <--> |_00DD0D40_|_4_|_DD_|_00DD0D90_| <--> |_00DD0D68_|_9_|_CC_|_00DD0DB8_| <--> |_00DD0D90_|_3_|_EE_|_00DD0DE0_| <--> |_00DD0DB8_|_8_|_FF_|_00DD0E08_| <--> |_00DD0DE0_|_2_|_GG_|_00000000_|   
*/