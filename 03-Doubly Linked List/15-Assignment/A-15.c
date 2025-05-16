/*
    A-15 -> write a c program to Find middle node in doubly linked list.
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_1_|_AA_|_00C40D40_| <--> |_00C42F98_|_2_|_BB_|_00C40D68_| <--> |_00C40D40_|_3_|_CC_|_00C40D90_| <--> |_00C40D68_|_4_|_DD_|_00C40DB8_| <--> |_00C40D90_|_5_|_EE_|_00000000_|                         
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
void middleNode(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\tLinked List : ");
    displayDLL(head);

    middleNode(head);
    
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

void middleNode(DLLNode *head) {

    DLLNode *p1 = NULL, *p2 = NULL;
    p1 = head , p2 = head;

    while (p1 != NULL && p1 -> next != NULL) {

        p1 = p1 -> next -> next;
        p2 = p2 -> next;

    }

    printf("\n\t The Middle Element in the given Doubly Linked List : \n");
    printf("\n\t |_%p_|_%d_|_%s_|_%p_| \n\n", p2 -> prev, p2 -> number, p2 -> name, p2 -> next);

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
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 5 EE
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List :

            |_Head_| <--> |_00000000_|_1_|_AA_|_00C40D40_| <--> |_00C42F98_|_2_|_BB_|_00C40D68_| <--> |_00C40D40_|_3_|_CC_|_00C40D90_| <--> |_00C40D68_|_4_|_DD_|_00C40DB8_| <--> |_00C40D90_|_5_|_EE_|_00000000_|   


                    The Middle Element in the given Doubly Linked List :

                    |_00C40D40_|_3_|_CC_|_00C40D90_|
*/