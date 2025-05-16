/*
    A-2 ->  write a c program to Create a circular doubly  linked list and insert a new node at the beginning. 
*/

/*
    Input ->|_Head_| <--> |_00DA13B0_|_1_|_AA_|_00DA1388_| <--> |_00DA2FC0_|_2_|_BB_|_00DA13B0_| <--> |_00DA1388_|_3_|_CC_|_00DA2FC0_|  <--> |_last_|
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
DCLLNode* insertBeg(DCLLNode*);
void displayDCLL(DCLLNode*);
void freeDCLL(DCLLNode*);

int main() {
   
    DCLLNode *last = NULL;

    last = createDCLL();

    printf("\n\t Circular Doubly Linked List : ");
    displayDCLL(last);

    last = insertBeg(last);

    printf("\n\t Dingly Circular Linked List after insertion of node at the beginning : ");
    displayDCLL(last);
    
    freeDCLL(last);
    last = NULL;

    return 0;
    
}

DCLLNode* createDCLL() {

    DCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = (DCLLNode*)malloc(sizeof(DCLLNode));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

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

DCLLNode* insertBeg(DCLLNode *last) {
    
    DCLLNode *nw = NULL;
    nw = (DCLLNode*)malloc(sizeof(DCLLNode));
    if (nw == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter number and name of the node to be inserted at the beginning :");
    scanf("%d %s", &(nw -> number),nw -> name);
    
    nw -> next = last -> next;
    nw -> prev = last;
    last -> next = nw;
    nw -> next -> prev = nw;

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

            |_Head_| <--> |_00DA13B0_|_1_|_AA_|_00DA1388_| <--> |_00DA2FC0_|_2_|_BB_|_00DA13B0_| <--> |_00DA1388_|_3_|_CC_|_00DA2FC0_|  <--> |_last_|


                    Enter number and name of the node to be inserted at the beginning :5 MM

                    Dingly Circular Linked List after insertion of node at the beginning :

            |_Head_| <--> |_00DA13B0_|_5_|_MM_|_00DA2FC0_| <--> |_00DA13D8_|_1_|_AA_|_00DA1388_| <--> |_00DA2FC0_|_2_|_BB_|_00DA13B0_| <--> |_00DA1388_|_3_|_CC_|_00DA13D8_|  <--> |_last_|
*/