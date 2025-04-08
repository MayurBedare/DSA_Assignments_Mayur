/*
    A-13 -> write a c program to Create a doubly linked list and Sort the doubly linked list while creation.
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_4_|_d_|_00871388_| <--> |_00872FC0_|_3_|_c_|_008713B0_| <--> |_00871388_|_2_|_b_|_008713D8_| <--> |_008713B0_|_1_|_a_|_00000000_|                            
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
DLLNode* sortDLL(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\t Doubly Linked List : ");
    displayDLL(head);
    
    head = sortDLL(head);
    printf("\n\t Doubly Linked List after sorting : ");
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

DLLNode* sortDLL(DLLNode *head) {

    DLLNode *p1 = NULL, *p2 = NULL;
    DLLNode t;
    for (p1 = head ; p1 != NULL ; p1 = p1 -> next) {
        for (p2 = p1 -> next ; p2 != NULL ; p2 = p2 -> next) {
            if (p1 -> number > p2 -> number) {
                t.number = p1 -> number;
                p1 -> number = p2 -> number;
                p2 -> number = t.number;

                strcpy(t.name,p1 -> name);
                strcpy(p1 -> name,p2 -> name);
                strcpy(p2 -> name,p1 -> name);
            }
        }
    }

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
                Enter Number and Name : 4 d
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 c
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 b
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 1 a
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Doubly Linked List :

            |_Head_| <--> |_00000000_|_4_|_d_|_00871388_| <--> |_00872FC0_|_3_|_c_|_008713B0_| <--> |_00871388_|_2_|_b_|_008713D8_| <--> |_008713B0_|_1_|_a_|_00000000_|       


                    Doubly Linked List after sorting :

            |_Head_| <--> |_00000000_|_1_|_a_|_00871388_| <--> |_00872FC0_|_2_|_a_|_008713B0_| <--> |_00871388_|_3_|_a_|_008713D8_| <--> |_008713B0_|_4_|_a_|_00000000_|       
*/