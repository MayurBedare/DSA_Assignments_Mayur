/*
    A-5 ->  write a c program to Create a singly linked list and search a particular node. 
          
            I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  
            Enter : Key = 5
            O/P ---->  
            |_5_|_EE_|_500_|
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
void search(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List :");
    displaySLL(head);

    search(head);

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
            printf("Memory Allocation Failed!");
            exit(1);
        }

        printf("\n\tEnter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

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

void search(SLLNode *head) {

    SLLNode *s = NULL;

    int key;
    printf("\n\tEnter : Key = ");
    scanf("%d", &key);

    for (s = head ; s != NULL ; s = s -> next) {

        if (key == s -> number) 
            printf("\n|_Head_| --> |_%d_|_%s_|_%p_| \n\n", s -> number, s -> name, s -> next);
        
        if (key == s -> number && s -> next == NULL)
            exit(0);
        
    }

    if (s == NULL)
        printf("\n\tInvalid Key Entered!\n\n");

    free(s);
    s = NULL;

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

            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 4 DD
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 5 EE
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 6 FF
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List :

            |_Head_| --> |_1_|_AA_|_00C10D40_| --> |_2_|_BB_|_00C10D68_| --> |_3_|_CC_|_00C10D90_| --> |_4_|_DD_|_00C10DB8_| --> |_5_|_EE_|_00C10DE0_| --> |_6_|_FF_|_00000000_|


                    Enter : Key = 5

            |_Head_| --> |_5_|_EE_|_00C10DE0_|                              
*/