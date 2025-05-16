/*
    A-5 ->  write a c program to Create a doubly linked list and Insert the Node at the end.
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_1_|_AA_|_00DD0D40_| <--> |_00DD2F98_|_2_|_BB_|_00000000_|              
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
DLLNode* insertLast(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\tLinked List : ");
    displayDLL(head);

    head = insertLast(head);

    printf("\n\tLinked List after Last node insertion : ");
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
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

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

DLLNode* insertLast(DLLNode *head) {


    DLLNode *nw = NULL,*p = NULL;

    nw = (DLLNode*)malloc(sizeof(DLLNode));
    if (nw == NULL)
    {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    printf("\n\tEnter the number and name of new inserted node at Last position : ");
    scanf("%d", &(nw -> number));
    getchar();
    fgets(nw -> name,20,stdin);
    nw -> name[strcspn(nw -> name,"\n")] = '\0';

    for (p = head ; p -> next != NULL ; p = p -> next);
    
    nw -> next = p -> next;
    p -> next = nw;
    nw -> prev = p;

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

            |_Head_| <--> |_00000000_|_1_|_AA_|_00DD0D40_| <--> |_00DD2F98_|_2_|_BB_|_00000000_| 


                    Enter the number and name of new inserted node at Last position : 5 MM

                    Linked List after Last node insertion : 

        |_Head_| <--> |_00000000_|_1_|_AA_|_00DD0D40_| <--> |_00DD2F98_|_2_|_BB_|_00DD0D68_| <--> |_00DD0D40_|_5_|_MM_|_00000000_| 
*/