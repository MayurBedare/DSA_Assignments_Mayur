/*
    A-5 ->  write a c program to Create a circular singly linked list and delete the first node.
*/

/*
    Input -> |_Head_| --> |_1_|_AA_|_00C81388_| --> |_2_|_BB_|_00C813B0_| --> |_3_|_CC_|_00C82FC0_| <-- |_last_|
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SCLLNode
{
    int number;
    char name[20];
    struct SCLLNode *next;
} SCLLNode;

SCLLNode* createSCLL();
SCLLNode* deleteFirst(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    last = createSCLL();

    printf("\n\t Singly Circular Linked List : ");
    displaySCLL(last);
    
    last = deleteFirst(last);

    if (last == NULL) {
        printf("\n\t Singly Circular Linked List is empty!\n\n");
        exit(0);
    }

    printf("\n\t Singly Circular Linked List after deletion of node at the start : ");
    displaySCLL(last);

    freeSCLL(last);
    last = NULL;

    return 0;
    
}

SCLLNode* createSCLL() {

    SCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = (SCLLNode*)malloc(sizeof(SCLLNode));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\tEnter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';
        
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

SCLLNode* deleteFirst(SCLLNode *last) {

    SCLLNode *d = NULL;
    d = last -> next;
    
    if (d == last) {
        free(d);
        d = NULL;
        return d;
    }

    last -> next = d -> next;
    free(d);
    d = NULL;

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

            |_Head_| --> |_1_|_AA_|_00C81388_| --> |_2_|_BB_|_00C813B0_| --> |_3_|_CC_|_00C82FC0_| <-- |_last_|


                    Singly Circular Linked List after deletion of node at the start : 

            |_Head_| --> |_2_|_BB_|_00C813B0_| --> |_3_|_CC_|_00C81388_| <-- |_last_|
*/