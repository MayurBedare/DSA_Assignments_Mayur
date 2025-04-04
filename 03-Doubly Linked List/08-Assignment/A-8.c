/*
    A-7 ->  write a c program to Create a doubly linked list and Delete a node at the end.
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_1_|_AA_|_00820D40_| <--> |_00822F98_|_2_|_BB_|_00820D68_| <--> |_00820D40_|_3_|_CC_|_00000000_|
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
DLLNode* deleteLast(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\tLinked List : ");
    displayDLL(head);

    head = deleteLast(head);

    printf("\n\tLinked List after Deletion of node at Last position : ");
    displayDLL(head);
    
    freeDLL(head);

    return 0;
    
}

DLLNode* createDLL() {

    DLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = malloc(sizeof(DLLNode));

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

DLLNode* deleteLast(DLLNode *head) {

    DLLNode *del = NULL;
    del = head;

    for ( ; del -> next -> next != NULL ; del = del -> next);

    del -> next = NULL;
    free(del -> next);

   return head;

}

void displayDLL(DLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeDLL(DLLNode *f) {

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

            |_Head_| <--> |_00000000_|_1_|_AA_|_00820D40_| <--> |_00822F98_|_2_|_BB_|_00820D68_| <--> |_00820D40_|_3_|_CC_|_00000000_|


                    Linked List after Deletion of node at Last position :

            |_Head_| <--> |_00000000_|_1_|_AA_|_00820D40_| <--> |_00822F98_|_2_|_BB_|_00000000_|
*/