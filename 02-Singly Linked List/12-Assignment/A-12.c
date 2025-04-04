/*
    A-10 -> write a c program to Create a Singly linked list and Delete the node at the last position
*/

/* 
    Input -> |_Head_| --> |_1_|_AA_|_00C91388_| --> |_2_|_BB_|_00C913B0_| --> |_3_|_CC_|_00000000_|                  
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
SLLNode* lastNodeDeletion(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    head = lastNodeDeletion(head);

    printf("\n\tLinked List after Deletion of node at Last position : ");
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

SLLNode* lastNodeDeletion(SLLNode *head) {

    SLLNode *del = NULL;

    if (head -> next == NULL) {
        head = NULL;
    } else {
        for (del = head ; del -> next -> next != NULL ; del = del -> next);
        free(del -> next);
        del -> next = NULL;
    }
    
    return head;
     
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

                    Linked List : 

            |_Head_| --> |_1_|_AA_|_00C91388_| --> |_2_|_BB_|_00C913B0_| --> |_3_|_CC_|_00000000_| 


                    Linked List after Deletion of node at Last position : 

            |_Head_| --> |_1_|_AA_|_00C91388_| --> |_2_|_BB_|_00000000_|                      
*/