/*
    A-17 -> write a c program to Swap doubly linked list without using swapping. 
            hint -> Adust the pointer instead of swapping the data
            I/P  ---->   |_1_|_AA_| --> |_2_|_BB_| --> |_3_|_CC_| --> |_4_|_DD_| --> |_5_|_EE|_NULL_|  

            O/P  ---->   |_3_|_CC_| --> |_4_|_DD_| --> |_1_|_AA_| --> |_2_|_BB_| --> |_5_|_EE_|_NULL_|
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_1_|_AA_|_00CB1378_| <--> |_00CB2FB8_|_2_|_BB_|_00CB13A0_| <--> |_00CB1378_|_3_|_CC_|_00CB13C8_| <--> |_00CB13A0_|_4_|_DD_|_00CB13F0_| 
                      <--> |_00CB13C8_|_5_|_EE_|_00CB1418_| <--> |_00CB13F0_|_6_|_FF_|_00CB1440_| <--> |_00CB1418_|_7_|_GG_|_00CB1468_| <--> |_00CB1440_|_8_|_HH_|_00000000_|                      
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
DLLNode* swapDLL(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\t Doubly Linked List : ");
    displayDLL(head);

    head = swapDLL(head);

    printf("\n\t Doubly Linked List with Swapping of nodes : ");
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

DLLNode* swapDLL(DLLNode *head) {

    DLLNode *swap1 = NULL, *swap2 = NULL;
    swap1 = head,swap2 = swap1 -> next -> next;
    
    if (swap1 == NULL || swap1 -> next == NULL || swap2 == NULL || swap2 -> next == NULL) {
        printf("\n\tDisplaying Swaping of Two Consecutive Nodes is not possible!\n\n");
    }
    else {
        while (swap1 -> next -> next == swap2) {
            
            swap2 -> prev = swap1 -> prev;
            swap1 -> prev = swap2 -> next; 
            swap1 -> next -> next = swap2 -> next -> next; 
            if (swap2 -> next -> next == NULL) { 
            swap2 -> next -> next = swap1;
            } else {
                swap2 -> next -> next -> prev = swap1 -> next;
                swap2 -> next -> next = swap1;
            }

            if(swap2 -> prev == NULL)
                head = swap2;
            else 
                swap2 -> prev -> next = swap2;
            
            swap1 = swap1 -> next -> next;
            if(swap1 == NULL || swap1 -> next == NULL)
                break;

            swap2 = swap1 -> next -> next;
            if(swap2 == NULL || swap2 -> next == NULL)
                break;
            
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
                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 4 DD
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 5 EE
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 6 FF
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 7 GG
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 8 HH
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Doubly Linked List :

            |_Head_| <--> |_00000000_|_1_|_AA_|_00CB1378_| <--> |_00CB2FB8_|_2_|_BB_|_00CB13A0_| <--> |_00CB1378_|_3_|_CC_|_00CB13C8_| <--> |_00CB13A0_|_4_|_DD_|_00CB13F0_| 
                     <--> |_00CB13C8_|_5_|_EE_|_00CB1418_| <--> |_00CB13F0_|_6_|_FF_|_00CB1440_| <--> |_00CB1418_|_7_|_GG_|_00CB1468_| <--> |_00CB1440_|_8_|_HH_|_00000000_|


                    Doubly Linked List with Swapping of nodes :

            |_Head_| <--> |_00000000_|_3_|_CC_|_00CB13C8_| <--> |_00CB13A0_|_4_|_DD_|_00CB2FB8_| <--> |_00CB13C8_|_1_|_AA_|_00CB1378_| <--> |_00CB2FB8_|_2_|_BB_|_00CB1440_| 
                     <--> |_00CB1378_|_7_|_GG_|_00CB1468_| <--> |_00CB1440_|_8_|_HH_|_00CB13F0_| <--> |_00CB1468_|_5_|_EE_|_00CB1418_| <--> |_00CB13F0_|_6_|_FF_|_00000000_|          
*/