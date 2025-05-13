/*
    A-12 -> write a c program to sort the doubly linked list. 
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_5_|_EE_|_00CD0D40_| <--> |_00CD2F98_|_3_|_CC_|_00CD0D68_| <--> |_00CD0D40_|_1_|_AA_|_00CD0D90_| <--> |_00CD0D68_|_4_|_DD_|_00CD0DB8_| <--> |_00CD0D90_|_2_|_BB_|_00000000_|                  
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
DLLNode* sort(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\tLinked List : ");
    displayDLL(head);

    head = sort(head);

    printf("\n\tSorted Linked List : ");
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

DLLNode* sort(DLLNode *head) {

    DLLNode *p1 = NULL, *p2 = NULL,temp;

    for (p1 = head; p1 != NULL ; p1 = p1 -> next) {
        for (p2 = p1 -> next ; p2 != NULL ; p2 = p2 -> next) {
            if (p1 -> number > p2 -> number) {
                temp.number = p1 -> number;
                p1 -> number = p2 -> number;
                p2 -> number = temp.number;

                strcpy(temp.name, p1 -> name);
                strcpy(p1 -> name, p2 -> name);
                strcpy(p2 -> name, temp.name);
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
    DLLNode *t = NULL;

    while (f != NULL) {
        t = f;
        f = f -> next;
        free(t);
    }
}

/*
    Output ->
                    Enter Number and Name : 5 EE
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 4 DD
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List :

            |_Head_| <--> |_00000000_|_5_|_EE_|_00CD0D40_| <--> |_00CD2F98_|_3_|_CC_|_00CD0D68_| <--> |_00CD0D40_|_1_|_AA_|_00CD0D90_| <--> |_00CD0D68_|_4_|_DD_|_00CD0DB8_| <--> |_00CD0D90_|_2_|_BB_|_00000000_|   


                    Sorted Linked List :

            |_Head_| <--> |_00000000_|_1_|_AA_|_00CD0D40_| <--> |_00CD2F98_|_2_|_BB_|_00CD0D68_| <--> |_00CD0D40_|_3_|_DD_|_00CD0D90_| <--> |_00CD0D68_|_4_|_DD_|_00CD0DB8_| <--> |_00CD0D90_|_5_|_EE_|_00000000_| 
*/