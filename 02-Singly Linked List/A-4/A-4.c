/*
    A-4 ->  write a c program to Create a Singly linked list and swap the two consecutive nodes 
          
            I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  


            O/P  ---->   |_2_|_BB_|_100_| --> |_1_|_AA_|_200_| --> |_4_|_DD_|_300_| --> |_3_|_CC_|_400_| --> |_6_|_FF_|_500_| --> |_5_|_EE_|_NULL_|
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SLLNode
{
    int number;
    char name[20];
    struct SLLNode *next;
} SLLNode;

SLLNode* createSLL();
void displaySLL(SLLNode*);
void freeSLL(SLLNode*);
void swapSLL(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    swapSLL(head);

    freeSLL(head);

    return 0;
    
}

SLLNode* createSLL() {

    SLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = malloc(sizeof(SLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = NULL;

        if (head == NULL)
            head = nw;
        else 
            last -> next = nw;
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

void swapSLL(SLLNode *head) {

    SLLNode *swap1 = NULL, *swap2 = NULL, temp;
    swap1 = head, swap2 = swap1 -> next;

    if ( swap2 == NULL) {
        printf("\n\tDisplaying Swaping of Two Consecutive Nodes is not possible!\n\n");
    }
    else {
        for ( ; swap1 != NULL && swap2 != NULL ; swap1 = swap2 -> next, swap2 = swap1 -> next ) {

            temp.number = swap1->number;
            swap1 -> number = swap2 -> number;
            swap2 -> number = temp.number;

            strcpy(temp.name, swap1 -> name);
            strcpy(swap1 -> name, swap2 -> name);
            strcpy(swap2 -> name, temp.name);

            if ( swap2 -> next == NULL )
                break;  

        }
        displaySLL(head);
    }

}

void displaySLL(SLLNode *d) {

    printf("\n\t|_head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSLL(SLLNode *f) {

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
                Do you want to enter more records ( yes(1) / no(0) ) : 1

                        Enter Number and Name : 4 DD
                Do you want to enter more records ( yes(1) / no(0) ) : 1

                        Enter Number and Name : 5 EE
                Do you want to enter more records ( yes(1) / no(0) ) : 1

                        Enter Number and Name : 6 FF
                Do you want to enter more records ( yes(1) / no(0) ) : 0

                        |_head_| --> |_2_|_BB_|_00751388_| --> |_1_|_AA_|_007513B0_| --> |_4_|_DD_|_007513D8_| --> |_3_|_CC_|_00751400_| --> |_6_|_FF_|_00751428_| --> |_5_|_EE_|_00000000_|           
*/