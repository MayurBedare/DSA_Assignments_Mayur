/*
    A-14 -> write a c program to Create a Singly linked list and Find and print the middle element
*/

/* 
    Input -> |_Head_| --> |_1_|_AA_|_00BD1388_| --> |_2_|_BB_|_00BD13B0_| --> |_3_|_CC_|_00BD13D8_| --> |_4_|_DD_|_00BD1400_| --> |_5_|_EE_|_00000000_|                    
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
void middleElement(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    middleElement(head);
    
    freeSLL(head);
    head = NULL;

    return 0;
    
}

SLLNode* createSLL() {

    SLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = (SLLNode*)malloc(sizeof(SLLNode));
        if (nw == NULL)
        {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

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

void middleElement(SLLNode *head) {

    SLLNode *p1 = NULL, *p2 = NULL;
    p1 = head, p2 = head;

    while (p2 != NULL && p2 -> next != NULL)
    {
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
    }

    printf("\n\t The Middle Element in the given Linked List : \n");
    printf("\n\t|_%d_|_%s_|_%p_|\n\n", p1 -> number, p1 -> name, p1 -> next);
    
}

void displaySLL(SLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSLL(SLLNode *f) {
    SLLNode *t = NULL;

    while (f != NULL) {
        t = f;
        f = f -> next;
        free(t);
    }
}

/*
    Output ->   
                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 4 DD
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 5 EE
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List :

            |_Head_| --> |_1_|_AA_|_00BD1388_| --> |_2_|_BB_|_00BD13B0_| --> |_3_|_CC_|_00BD13D8_| --> |_4_|_DD_|_00BD1400_| --> |_5_|_EE_|_00000000_|


                    The Middle Element in the given Linked List :

                    |_3_|_CC_|_00BD13D8_|                             
*/