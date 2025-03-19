/*
    A-3 ->  write a c program to Create a Singly linked list and Display the alternate nodes 

            I/P  ---->  |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_NULL_|. 

            O/P  ---->  |_1_|_AA_|_100_| --> |_3_|_CC_|_300_| --> |_5_|_EE_|_NULL_| 
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
void alternateSLL(SLLNode*);
void freeSLL(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    alternateSLL(head);

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
        if (nw == NULL)
        {
        printf("Memory Allocation Failed!");
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

void alternateSLL(SLLNode *head) {

    SLLNode *alt_p = NULL;
    alt_p = head;

    if ( alt_p -> next == NULL || alt_p -> next -> next == NULL ) { 
        printf("\n\tDisplaying Alternate Nodes not possible!\n\n");
    }
    else {
        for ( ; alt_p -> next != NULL && alt_p -> next -> next != NULL ; alt_p = alt_p -> next) {

            alt_p -> next = alt_p -> next -> next;
        
            }

        alt_p -> next = NULL;

        printf("\n\tLinked List with Alternate nodes : ");
        displaySLL(head);
    }

}

void displaySLL(SLLNode *d) {

    printf("\n\n|_head_| ");
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
                Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 5 EE
                Do you want to enter more records ( yes(1) / no(0) ) : 0

                    |_head_| --> |_1_|_AA_|_00B913B0_| --> |_3_|_CC_|_00B91400_| --> |_5_|_EE_|_00000000_|                           
*/