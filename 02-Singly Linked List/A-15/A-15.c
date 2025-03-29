/*
    A-15 -> write a c program to Create a Singly linked list and sort the linked list
*/

/* 
    Input -> |_Head_| --> |_5_|_EE_|_00901388_| --> |_3_|_CC_|_009013B0_| --> |_1_|_AA_|_009013D8_| --> |_4_|_DD_|_00901400_| --> |_2_|_BB_|_00000000_|                      
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SLLNode
{
    int number;
    char name[20];
    struct SLLNode *next;
} SLLNode;

SLLNode* createSLL();
void displaySLL(SLLNode*);
void freeSLL(SLLNode*);
void sort(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    sort(head);
    
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

void sort(SLLNode *head) {

    SLLNode *p1 = NULL, *p2 = NULL,temp;

    for (p1 = head; p1 -> next != NULL ; p1 = p1 -> next) {
        for (p2 = p1 -> next ; p2 -> next != NULL ; p2 = p2 -> next) {
            if (p1 -> number > p2 -> number) {
                temp.number = p1 -> number;
                p1 -> number = p2 -> number;
                p2 -> number = temp.number;

                strcpy(temp.name, p1 -> name);
                strcpy(p1 -> name, p2 -> name);
                strcpy(p2 -> name, temp.name);
            }
        }
    }

    printf("\n\tSorted Linked List : ");
    displaySLL(head);

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
                    Enter Number and Name : 5 EE
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 4 DD
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List : 

            |_Head_| --> |_5_|_EE_|_00901388_| --> |_3_|_CC_|_009013B0_| --> |_1_|_AA_|_009013D8_| --> |_4_|_DD_|_00901400_| --> |_2_|_BB_|_00000000_| 


                    Sorted Linked List : 

            |_Head_| --> |_1_|_AA_|_00901388_| --> |_2_|_BB_|_009013B0_| --> |_3_|_CC_|_009013D8_| --> |_4_|_DD_|_00901400_| --> |_5_|_EE_|_00000000_|                                
*/