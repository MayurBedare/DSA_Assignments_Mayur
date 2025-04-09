/*
    A-5 ->  write a c program to Create a circular singly linked list and delete the last node.
*/

/*
    Input -> |_Head_| --> |_1_|_AA_|_008B2F68_| --> |_2_|_BB_|_008B0D40_| --> |_3_|_CC_|_008B2FB8_| <-- |_last_|
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SCLLNode
{
    int number;
    char name[20];
    struct SCLLNode *next;
} SCLLNode;

SCLLNode* createSCLL();
SCLLNode* deleteLast(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    last = createSCLL();

    printf("\n\t Singly Circular Linked List : ");
    displaySCLL(last);
    
    last = deleteLast(last);

    if (last == NULL) {
        printf("\n\t Singly Circular Linked List is empty!\n\n");
        exit(0);
    }

    printf("\n\t Singly Circular Linked List after deletion of node at the last : ");
    displaySCLL(last);

    freeSCLL(last);

    return 0;
    
}

SCLLNode* createSCLL() {

    SCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = (SCLLNode*)malloc(sizeof(SCLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = nw;

        if (head == NULL) {
            head = nw;
        }
        else {
            last -> next = nw;
            nw -> next = head;
        }
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

SCLLNode* deleteLast(SCLLNode *last) {

    SCLLNode *d = NULL,*t = NULL;
    d = last -> next;
    
    if (d == last) {
        free(d);
        d = NULL;
        return d;
    }

    for ( ; d -> next != last ; d = d -> next);

    t = d -> next;
    d -> next = last -> next;
    last = d;
    free(t);
    t = NULL;

    return last;

}

void displaySCLL(SCLLNode *last) {

    SCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n|_Head_| ");

    for ( ; d != last ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("--> |_%d_|_%s_|_%p_| <-- |_last_|", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSCLL(SCLLNode *last) {

    if (last == NULL)
        return;

    SCLLNode *f = NULL,*t = NULL;
    f = last -> next;

    while (f != last) {
        t = f;   
        f = f -> next;
        free(t);
        t = NULL;
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

                    Singly Circular Linked List : 

            |_Head_| --> |_1_|_AA_|_008B2F68_| --> |_2_|_BB_|_008B0D40_| --> |_3_|_CC_|_008B2FB8_| <-- |_last_|


                    Singly Circular Linked List after deletion of node at the last : 

            |_Head_| --> |_1_|_AA_|_008B2F68_| --> |_2_|_BB_|_008B2FB8_| <-- |_last_|
*/