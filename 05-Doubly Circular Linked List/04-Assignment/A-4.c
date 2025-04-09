/*
    A-4 ->  write a c program to Create a circular doubly  linked list and insert a new node  at last. 
*/

/*
    Input -> |_Head_| <--> |_00BE13B0_|_1_|_AA_|_00BE1388_| <--> |_00BE2FC0_|_2_|_BB_|_00BE13B0_| <--> |_00BE1388_|_3_|_CC_|_00BE2FC0_|  <--> |_last_|
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
DCLLNode* insertEnd(DCLLNode*);
void displayDCLL(DCLLNode*);
void freeDCLL(DCLLNode*);

int main() {
   
    DCLLNode *last = NULL;

    last = createDCLL();

    printf("\n\t Circular Doubly Linked List : ");
    displayDCLL(last);

    last = insertEnd(last);

    printf("\n\t Dingly Circular Linked List after insertion of node at the end : ");
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

DCLLNode* insertEnd(DCLLNode *last) {
    
    DCLLNode *nw = NULL;
    nw = malloc(sizeof(DCLLNode));
    printf("\n\t Enter number and name of the node to be inserted at the end : ");
    scanf("%d %s", &(nw -> number),nw -> name);
    
    nw -> next = last -> next;
    nw -> next -> prev = nw;
    last -> next = nw;
    nw -> prev = last;
    last = nw;

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

            |_Head_| <--> |_00BE13B0_|_1_|_AA_|_00BE1388_| <--> |_00BE2FC0_|_2_|_BB_|_00BE13B0_| <--> |_00BE1388_|_3_|_CC_|_00BE2FC0_|  <--> |_last_|


                    Enter number and name of the node to be inserted at the end : 5 MM

                    Dingly Circular Linked List after insertion of node at the end :

            |_Head_| <--> |_00BE13D8_|_1_|_AA_|_00BE1388_| <--> |_00BE2FC0_|_2_|_BB_|_00BE13B0_| <--> |_00BE1388_|_3_|_CC_|_00BE13D8_| <--> |_00BE13B0_|_5_|_MM_|_00BE2FC0_|  <--> |_last_|
*/