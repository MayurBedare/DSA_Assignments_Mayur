/*
    A-6 ->  write a c program to Create a Singly Linked list and  Display the addition of two consecutive nodes to the next node 
          
            I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 

            O/P ---->    |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_AABB_|_700_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_800_| --> |_7_|_CCDD_|_NULL_|
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
void add2CN(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    add2CN(head);

    freeSLL(head);
    head = NULL;

    return 0;
    
}

SLLNode* createSLL() {

    SLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = (SLLNode*)malloc(sizeof(SLLNode));
        if (nw == NULL)
        {
            printf("\n\t Memory Allocation Failed!");
            exit(1);
        }

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

void add2CN(SLLNode *head) {

    SLLNode *nw = NULL, *a1 = NULL, *a2 = NULL;
    a1 = head, a2 = a1 -> next;
    char string[20];

    if (a1 == NULL || a2 == NULL) {
        printf("\n\tDisplaying Addition of two consecutive nodes is not possible!\n\n");
    } else {
        for ( ; a1 != NULL && a2 != NULL ; a2 = a1 -> next) {
            nw = malloc(sizeof(SLLNode));
            
            nw -> next = a2 -> next;
            a2 -> next = nw;

            nw -> number = a1 -> number + a2 -> number;
            strcpy(string, a1 -> name);
            strcat(string, a2 -> name);
            strcpy(nw -> name, string);
            
            a1 = nw -> next;

            if (a1 == NULL)
                break;
        }
        printf("\n\tLinked List with Addition of two consecutive nodes to 3rd node and so on : ");
        displaySLL(head);
    }   
}

void displaySLL(SLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSLL(SLLNode *f) {
    SLLNode *t = NULL;

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
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List :

            |_Head_| --> |_1_|_AA_|_00B00D40_| --> |_2_|_BB_|_00B00D68_| --> |_3_|_CC_|_00B00D90_| --> |_4_|_DD_|_00000000_|


                    Linked List with Addition of two consecutive nodes to 3rd node and so on :

            |_Head_| --> |_1_|_AA_|_00C70D40_| --> |_2_|_BB_|_00C70DB8_| --> |_3_|_AABB_|_00C70D68_| --> |_3_|_CC_|_00C70D90_| --> |_4_|_DD_|_00C70DE0_| --> |_7_|_CCDD_|_00000000_|            
*/