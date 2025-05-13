/*
    A-3 ->  write a c program to Create a doubly linked list and Insert the Node at Head .
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_1_|_AA_|_00C80D40_| <--> |_00C82F98_|_2_|_BB_|_00000000_|                        
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
DLLNode* insertHead(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\tLinked List : ");
    displayDLL(head);

    head = insertHead(head);

    printf("\n\tLinked List after Head node insertion : ");
    displayDLL(head);
    
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

DLLNode* insertHead(DLLNode *head) {

    DLLNode *nw = NULL;

    nw = (DLLNode*)malloc(sizeof(DLLNode));
    if (nw == NULL)
    {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    printf("\n\tEnter the number and name of new inserted node at Head position : ");
    scanf("%d %s", &(nw -> number), nw -> name);

    nw -> prev = NULL;
    nw -> next = head;
    head -> prev = nw;
    head = nw;

    return head;

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
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List : 

            |_Head_| <--> |_00000000_|_1_|_AA_|_00C80D40_| <--> |_00C82F98_|_2_|_BB_|_00000000_| 


                    Enter the number and name of new inserted node at Head position : 5 MM

                    Linked List after Head node insertion : 

            |_Head_| <--> |_00000000_|_5_|_MM_|_00C82F98_| <--> |_00C80D68_|_1_|_AA_|_00C80D40_| <--> |_00C82F98_|_2_|_BB_|_00000000_| 
*/