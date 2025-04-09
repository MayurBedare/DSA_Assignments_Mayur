/*
    A-7 ->  write a c program to Create a circular doubly linked list and delete the last node .
*/

/*
    Input -> |_Head_| <--> |_00D80D40_|_1_|_AA_|_00D82F68_| <--> |_00D82FB8_|_2_|_BB_|_00D80D40_| <--> |_00D82F68_|_3_|_CC_|_00D82FB8_|  <--> |_last_|
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
DCLLNode* deleteLast(DCLLNode*);
void displayDCLL(DCLLNode*);
void freeDCLL(DCLLNode*);

int main() {
   
    DCLLNode *last = NULL;

    last = createDCLL();

    printf("\n\t Doubly Circular Linked List : ");
    displayDCLL(last);

    last = deleteLast(last);

    if (last == NULL) {
        printf("\n\t Doubly Circular Linked List is empty!\n\n");
        exit(0);
    }

    printf("\n\t Doubly Circular Linked List after deletion of node at the end : ");
    displayDCLL(last);
    
    freeDCLL(last);

    return 0;
    
}

DCLLNode* createDCLL() {

    DCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = (DCLLNode*)malloc(sizeof(DCLLNode));

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

DCLLNode* deleteLast(DCLLNode *last) {

    DCLLNode *d = NULL;
    d = last -> next;
    
    if (d == last) {
        free(d);
        d = NULL;
        return d;
    }

    for ( ; d != last ; d = d -> next);

    d -> prev -> next = last -> next;
    d -> prev -> next -> prev = d -> prev;
    last = d -> prev;
    free(d);
    d = NULL;

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

                    Doubly Circular Linked List : 

            |_Head_| <--> |_00D80D40_|_1_|_AA_|_00D82F68_| <--> |_00D82FB8_|_2_|_BB_|_00D80D40_| <--> |_00D82F68_|_3_|_CC_|_00D82FB8_|  <--> |_last_|


                    Doubly Circular Linked List after deletion of node at the end : 

            |_Head_| <--> |_00D82F68_|_1_|_AA_|_00D82F68_| <--> |_00D82FB8_|_2_|_BB_|_00D82FB8_|  <--> |_last_|
*/