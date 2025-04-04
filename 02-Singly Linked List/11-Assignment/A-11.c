/*
    A-11 -> write a c program to Create a Singly linked list and Delete the node in the given position
*/

/* 
    Input -> |_Head_| --> |_1_|_AA_|_00B71388_| --> |_2_|_BB_|_00B713B0_| --> |_3_|_CC_|_00000000_|  
    position = 2                 
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
SLLNode* positionNodeDeletion(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    head = positionNodeDeletion(head);

    if( head != NULL) {
    printf("\n\tLinked List after Deletion of node at Given position : ");
    displaySLL(head);
    }

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

SLLNode* positionNodeDeletion(SLLNode * head) {

    SLLNode *del = NULL,*temp = NULL;
    del = head;

    int pos;
    printf("\n\tEnter the position of the node to be deleted : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        head = del -> next;
    } else {
        for (int i = 1 ; i < pos-1 && del -> next != NULL ; del = del -> next,i++);

        if (del -> next != NULL) {
            if (del -> next -> next == NULL) {
                del -> next = NULL;
            } else {
            temp = del -> next;
            del -> next = del -> next -> next;
            free(temp);
            temp = NULL;
            }
        } else {
            printf("\n\tInvalid Position Entered!\n\n");
            exit(0);
        }
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

            |_Head_| --> |_1_|_AA_|_00B71388_| --> |_2_|_BB_|_00B713B0_| --> |_3_|_CC_|_00000000_|


                    Enter the position of the node to be deleted : 2

                    Linked List after Deletion of node at Given position :

            |_Head_| --> |_1_|_AA_|_00B713B0_| --> |_3_|_CC_|_00000000_|    
*/

/*
    Position = 1 (Head Position) :

        Linked List : 

    |_Head_| --> |_2_|_BB_|_00B713B0_| --> |_3_|_CC_|_00000000_|  
*/

/*
    Position = 2 (Middle Position) :

        Linked List : 

    |_Head_| --> |_1_|_AA_|_00B71388_| --> |_3_|_CC_|_00000000_| 
*/

/*
    Position = 3 (End Position) :

        Linked List : 

    |_Head_| --> |_1_|_AA_|_00B71388_| --> |_2_|_BB_|_00000000_|  
*/