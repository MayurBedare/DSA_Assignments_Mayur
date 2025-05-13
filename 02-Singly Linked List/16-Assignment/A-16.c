/*
    A-16 -> write a c program to Create a Singly linked list and Display it in reverse order (Use Normal Function)
            I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
            O/P :
            ------  
             4 DD
             3 CC
             2 BB
             1 AA
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SLLNode
{
    int number;
    char name[20];
    struct SLLNode *next;
} SLLNode;

SLLNode* createSLL();
void reverse(SLLNode*);
void displaySLL(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    reverse(head);
    
    free(head);
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
            printf("\n\t Memory Allocation Failed! \n\n");
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

void reverse(SLLNode *head) {

    SLLNode *p1 = NULL, *p2 = NULL, *temp = NULL;
    p1 = head;
    
    printf("\n\t Display of linked list elements in reverse order : ");
    printf("\n\t ------");
    while (p1 != NULL) {
        if (p1 -> next == NULL) {
            printf("\n\t %d %s\n\n", p1 -> number, p1 -> name);
            return;
        }

        for (p2 = head ; p2 -> next -> next != NULL ; p2 = p2 -> next);

        printf("\n\t %d %s", p2 -> next -> number, p2 -> next -> name);
        temp = p2 -> next;
        p2 -> next = NULL;
        free(temp);
        temp = NULL;
    }

}

void displaySLL(SLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("\n\n");

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

            |_Head_| --> |_1_|_AA_|_00D11388_| --> |_2_|_BB_|_00D113B0_| --> |_3_|_CC_|_00D113D8_| --> |_4_|_DD_|_00000000_| 


                    Display of linked list elements in reverse order : 
                    ------
                    4 DD
                    3 CC
                    2 BB
                    1 AA                              
*/