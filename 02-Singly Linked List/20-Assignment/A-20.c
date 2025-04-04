/*
    A-20 ->  write a c program to Create Linked List using Recursion.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SLLNode
{
    int number;
    char name[20];
    struct SLLNode *next;
} SLLNode;

void displaySLL(SLLNode*);
void freeSLL(SLLNode*);
SLLNode* recursiveCreateSLL(SLLNode*,SLLNode*,int*);

int main() {
    
    SLLNode *head = NULL;
    SLLNode *last = NULL;

    int cnt = 1;

    head = recursiveCreateSLL(head,last,&cnt);

    printf("\n\tLinked List using recursion : ");
    displaySLL(head);
    
    freeSLL(head);

    return 0;
    
}

SLLNode* recursiveCreateSLL(SLLNode *head, SLLNode *last, int *cnt) {

    if(*cnt == 0)
        return head;

    SLLNode *nw = NULL;
    
    nw = malloc(sizeof(SLLNode));
    
    printf("\n\tEnter Number and Name : ");
    scanf("%d %s", &(nw -> number), nw -> name);

    nw -> next = NULL;

    if (head == NULL) 
        head = nw;
    else 
        last -> next = nw;

    printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", cnt);
    
    recursiveCreateSLL(head,nw,cnt);

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
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List using recursion : 

            |_Head_| --> |_1_|_AA_|_00CE1388_| --> |_2_|_BB_|_00CE13B0_| --> |_3_|_CC_|_00000000_|                              
*/