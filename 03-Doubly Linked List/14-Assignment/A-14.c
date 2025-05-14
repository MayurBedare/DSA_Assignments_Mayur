/*
    A-14 -> write a c program to create two doubly linked lists, sort them individually and then merge the two sorted lists
*/

/* 
    Input ->
                    Doubly Linked List 1 : 

            |_Head_| <--> |_00000000_|_3_|_CC_|_00BF0D40_| <--> |_00BF2F98_|_1_|_AA_|_00BF0D68_| <--> |_00BF0D40_|_2_|_BB_|_00000000_| 

                    Doubly Linked List 2 : 

            |_Head_| <--> |_00000000_|_6_|_FF_|_00BF0DB8_| <--> |_00BF0D90_|_4_|_DD_|_00BF0DE0_| <--> |_00BF0DB8_|_5_|_EE_|_00000000_| 
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
DLLNode* merge(DLLNode*,DLLNode*);

int main() {
    
    DLLNode *head1 = NULL, *head2 = NULL;

    printf("\n\t ***** Creation of Doubly Linked List 1  ******\n");
    head1 = createDLL();
    printf("\n\t Doubly Linked List 1 : ");
    displayDLL(head1);

    head1 = sort(head1);
    printf("\n\t Sorted Doubly Linked List 1 : ");
    displayDLL(head1);

    printf("\n\t ***** Creation of Doubly Linked List 2  ******\n");
    head2 = createDLL();
    printf("\n\t Doubly Linked List 2 : ");
    displayDLL(head2);

    head2 = sort(head2);
    printf("\n\t Sorted Doubly Linked List 2 : ");
    displayDLL(head2);

    head1 = merge(head1,head2);

    printf("\n\t Merged Doubly Linked List : ");
    displayDLL(head1);
    
    freeDLL(head1);
    head1 = NULL;
    head2 = NULL;

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

DLLNode* merge(DLLNode *head1, DLLNode *head2) {

    DLLNode *P = NULL;
    
    for (P = head1; P -> next != NULL ; P = P -> next);

    P -> next = head2;
    head2 -> prev = P;

    return head1;

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
                ***** Creation of Doubly Linked List 1  ******

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Doubly Linked List 1 : 

            |_Head_| <--> |_00000000_|_3_|_CC_|_00BF0D40_| <--> |_00BF2F98_|_1_|_AA_|_00BF0D68_| <--> |_00BF0D40_|_2_|_BB_|_00000000_| 


                    Sorted Doubly Linked List 1 : 

            |_Head_| <--> |_00000000_|_1_|_AA_|_00BF0D40_| <--> |_00BF2F98_|_2_|_BB_|_00BF0D68_| <--> |_00BF0D40_|_3_|_CC_|_00000000_| 


                    ***** Creation of Doubly Linked List 2  ******

                    Enter Number and Name : 6 FF
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 4 DD
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 5 EE
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Doubly Linked List 2 : 

            |_Head_| <--> |_00000000_|_6_|_FF_|_00BF0DB8_| <--> |_00BF0D90_|_4_|_DD_|_00BF0DE0_| <--> |_00BF0DB8_|_5_|_EE_|_00000000_| 


                    Sorted Doubly Linked List 2 : 

            |_Head_| <--> |_00000000_|_4_|_DD_|_00BF0DB8_| <--> |_00BF0D90_|_5_|_EE_|_00BF0DE0_| <--> |_00BF0DB8_|_6_|_FF_|_00000000_| 


                    Merged Doubly Linked List : 

            |_Head_| <--> |_00000000_|_1_|_AA_|_00BF0D40_| <--> |_00BF2F98_|_2_|_BB_|_00BF0D68_| <--> |_00BF0D40_|_3_|_CC_|_00BF0D90_| <--> |_00BF0D68_|_4_|_DD_|_00BF0DB8_| <--> |_00BF0D90_|_5_|_EE_|_00BF0DE0_| <--> |_00BF0DB8_|_6_|_FF_|_00000000_|     
*/