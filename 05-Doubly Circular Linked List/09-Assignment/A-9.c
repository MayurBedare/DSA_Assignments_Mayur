/*
    A-9 ->  write a c program to Create a circular doubly  linked list and Reverse it.  
*/

/*
    Input -> |_Head_| <--> |_00DE13E8_|_1_|_AA_|_00DE13C0_| <--> |_00DE1398_|_2_|_BB_|_00DE13E8_| <--> |_00DE13C0_|_3_|_CC_|_00DE1398_|  <--> |_last_|
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
DCLLNode* reverse(DCLLNode*);
void displayDCLL(DCLLNode*);
void freeDCLL(DCLLNode*);

int main() {
   
    DCLLNode *last = NULL;

    last = createDCLL();

    printf("\n\t Doubly Circular Linked List : ");
    displayDCLL(last);

    last = reverse(last);

    printf("\n\t Doubly Circular Linked List after reversing : ");
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

DCLLNode* reverse(DCLLNode *last) {

    DCLLNode *p = NULL,*t = NULL;

    for (p = last -> next ; p != last ; p = t) {
        t = p -> next;
        p -> next = p -> prev;
        p -> prev = t;
    }

    t = p -> next;
    p -> next = p -> prev;
    p -> prev = t;
    printf("%d",p -> number);
    printf("%d",t -> number);

    return t;

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

            |_Head_| <--> |_00DE13E8_|_1_|_AA_|_00DE13C0_| <--> |_00DE1398_|_2_|_BB_|_00DE13E8_| <--> |_00DE13C0_|_3_|_CC_|_00DE1398_|  <--> |_last_|

            31
                    Doubly Circular Linked List after reversing : 

            |_Head_| <--> |_00DE1398_|_3_|_CC_|_00DE13C0_| <--> |_00DE13E8_|_2_|_BB_|_00DE1398_| <--> |_00DE13C0_|_1_|_AA_|_00DE13E8_|  <--> |_last_|
*/