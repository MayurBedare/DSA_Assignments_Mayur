/*
    A-13 -> write a c program to Create a Singly linked list and Delete the node depending on user input key/value
*/

/* 
    Input -> |_Head_| --> |_1_|_AA_|_00B31388_| --> |_2_|_BB_|_00B313B0_| --> |_3_|_CC_|_00000000_| 
    key/value = 2 BB              
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
SLLNode* keyNodeDeletion(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    head = keyNodeDeletion(head);

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

SLLNode* keyNodeDeletion(SLLNode * head) {

    SLLNode *del = NULL,*temp = NULL, *prev;
    temp = malloc(sizeof(SLLNode));
    del = head;

    int pos;
    printf("\n\tEnter key/value ie Node's name and number Eg. 1 AA : ");
    scanf("%d %s", &(temp -> number), temp -> name);
    
    if (temp -> number == del -> number && (!strcmp(temp -> name, del -> name))) {
        head = del -> next;
        free(del);
        free(temp);
        del = NULL, temp = NULL;
    } else {
        for ( ; temp -> number != del -> number && strcmp(temp -> name, del -> name) && del -> next != NULL ; prev = del, del = del -> next);

        if (prev -> next -> next != NULL ) {
            temp = prev -> next;
            prev -> next = prev -> next -> next;
            free(temp);
            free(del);
            del = NULL,temp = NULL;
        } else {
            prev -> next = NULL;
            free(temp);
            free(del);
            del = NULL, temp = NULL;
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

            |_Head_| --> |_1_|_AA_|_00B31388_| --> |_2_|_BB_|_00B313B0_| --> |_3_|_CC_|_00000000_| 


                    Enter key/value ie Node's name and number Eg. 1 AA : 2 BB

                    Linked List after Deletion of node at Given position : 

            |_Head_| --> |_1_|_AA_|_00B313B0_| --> |_3_|_CC_|_00000000_|
*/

/*
    Key/value = 1 AA (Head Position) :

        Linked List : 

    |_Head_| --> |_2_|_BB_|_00B313B0_| --> |_3_|_CC_|_00000000_|  
*/

/*
    Key/value = 2 BB (Middle Position) :

        Linked List : 

    |_Head_| --> |_1_|_AA_|_00B313B0_| --> |_3_|_CC_|_00000000_| 
*/

/*
    Key/value = 3 CC (End Position) :

        Linked List : 

    |_Head_| --> |_1_|_AA_|_00B31388_| --> |_2_|_BB_|_00000000_|  
*/