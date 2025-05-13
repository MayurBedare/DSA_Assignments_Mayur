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

    printf("\n\t ***** Doubly Linked List Sortring : While creation ***** \n");

    head = createDLL();

    printf("\n\t Doubly Linked List after sorting while creation : ");
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

        printf("\n\t Enter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = NULL;
        nw -> prev = NULL;

        if (head == NULL) {
            head = nw;
            last = nw;
        }
        else {
            int flag = 0;
            for (DLLNode *p = head ; p != NULL ; p = p -> next) {
                if (p -> number > nw -> number) {
                    flag = 1;
                    if (p == head) {
                        p -> prev = nw;
                        nw -> next = p;
                        last = p;
                        head = nw;
                    } else {
                        p -> prev -> next = nw;
                        nw -> prev = p -> prev;
                        nw -> next = p;
                        p -> prev = nw;
                    }
                    break;
                }
            }
            
            if (flag == 0) {
                last -> next = nw;
                nw -> prev = last;
                last = nw;
            }
        }

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

void displayDLL(DLLNode *d) {

    printf("\n\n\t |_Head_| ");
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