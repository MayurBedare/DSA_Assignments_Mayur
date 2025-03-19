/*
    A-18 -> write a c program to Create a Singly linked list and revert it 
            I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
            O/P ---->    |_4_|_DD_|_100_| --> |_3_|_CC_|_200_| --> |_2_|_BB_|_300_| --> |_1_|_AA_|_NULL_| 
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
SLLNode* revert(SLLNode*);


int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    head = revert(head);

    printf("\n\tLinked List after revert : ");
    displaySLL(head);
    
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

SLLNode* revert(SLLNode* t)
{
    SLLNode *x,*y,*z;
    x = t; 
    y = x -> next;
    z = y -> next;
    
    while (x -> next != NULL)
    {
        if (z -> next != NULL)
        {
            t = y -> next;
            y -> next = z -> next;
            z -> next = z -> next -> next;
            y -> next -> next = t; 
        }
        else
        {
            t = y -> next;
            z -> next = y;
            y -> next = x;
            x -> next = NULL;
            
        }
    }    
    return t;
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
                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1  

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 4 DD
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List : 

            |_Head_| --> |_1_|_AA_|_00BD1388_| --> |_2_|_BB_|_00BD13B0_| --> |_3_|_CC_|_00BD13D8_| --> |_4_|_DD_|_00000000_| 


                    Linked List after revert : 

            |_Head_| --> |_4_|_DD_|_00BD13B0_| --> |_3_|_CC_|_00BD1388_| --> |_2_|_BB_|_00BD2FC0_| --> |_1_|_AA_|_00000000_| 
*/