/*
    A-2 ->  write a c program to Create Doubly linked list and display it in reverse order.
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_1_|_AA_|_00710D40_| <--> |_00712F98_|_2_|_BB_|_00710D68_| <--> |_00710D40_|_3_|_CC_|_00710D90_| <--> |_00710D68_|_4_|_DD_|_00000000_| 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct DLLNode
{
    int number;
    char name[20];
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

DLLNode* createDLL();
void displayDLL(DLLNode*);
void freeDLL(DLLNode*);
void reverseDLL(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\tLinked List : ");
    displayDLL(head);

    reverseDLL(head);
    
    freeDLL(head);
    head = NULL;

    return 0;
    
}

DLLNode* createDLL() {

    DLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = (DLLNode*)malloc(sizeof(DLLNode));
        if (nw == NULL)
        {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = NULL;

        if (head == NULL) {
            head = nw;
            nw -> prev = NULL;
        }
        else {
            last -> next = nw;
            nw -> prev = last;
        }
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

void reverseDLL(DLLNode *head) {

    DLLNode *p = NULL;
    
    printf("\n\tDisplay of linked list elements in reverse order : ");
    printf("\n\t------");
    
    for (p = head ; p -> next != NULL ; p = p -> next);

    for ( ; p != NULL ; p = p -> prev) {
        printf("\n\t %d  %s", p -> number, p -> name);
    }
    printf("\n\n");

}

void displayDLL(DLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeDLL(DLLNode *f) {
    DLLNode *t = NULL;

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
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 4 DD
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List : 

            |_Head_| <--> |_00000000_|_1_|_AA_|_00710D40_| <--> |_00712F98_|_2_|_BB_|_00710D68_| <--> |_00710D40_|_3_|_CC_|_00710D90_| <--> |_00710D68_|_4_|_DD_|_00000000_| 


                    Display of linked list elements in reverse order : 
                    ------
                    4  DD
                    3  CC
                    2  BB
                    1  AA
*/