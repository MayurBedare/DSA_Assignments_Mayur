/*
    A-7 ->  write a c program to Create a Singly linked list and Insert a node at Head
*/

/* 
    Input -> |_Head_| --> |_1_|_AA_|_00BC0D40_| --> |_2_|_BB_|_00BC0D68_| --> |_3_|_CC_|_00000000_|                     
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
SLLNode* headNodeInsertion(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    head = headNodeInsertion(head);

    printf("\n\tLinked List after Head node insertion : ");
    displaySLL(head);

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
            printf("Memory Allocation Failed!");
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

SLLNode* headNodeInsertion(SLLNode *head) {

    SLLNode *nw = NULL;

    nw = (SLLNode*)malloc(sizeof(SLLNode));
    if (nw == NULL)
    {
        printf("\n\tMemory Allocation Failed!");
    }
    
    printf("\n\tEnter the number and name of new inserted node at Head position : ");
    scanf("%d %s", &(nw -> number), nw -> name);

    nw -> next = head;
    head = nw;

    return head;

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
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List :

            |_Head_| --> |_1_|_AA_|_00BC0D40_| --> |_2_|_BB_|_00BC0D68_| --> |_3_|_CC_|_00000000_|


                    Enter the number and name of new inserted node at Head position : 1 ZZ

                    Linked List after Head node insertion : 

            |_Head_| --> |_1_|_ZZ_|_00BE2F98_| --> |_1_|_AA_|_00BE0D40_| --> |_2_|_BB_|_00BE0D68_| --> |_3_|_CC_|_00000000_|           
*/