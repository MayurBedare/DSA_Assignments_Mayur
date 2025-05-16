/*
    A-4 ->  write a c program to Create a circular singly  linked list and insert a new node  at last.
*/

/*
    Input -> |_Head_| --> |_1_|_AA_|_00C61388_| --> |_2_|_BB_|_00C613B0_| --> |_3_|_CC_|_00C62FC0_| <-- |_last_|
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SCLLNode
{
    int number;
    char name[20];
    struct SCLLNode *next;
} SCLLNode;

SCLLNode* createSCLL();
SCLLNode* insertEnd(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    last = createSCLL();

    printf("\n\t Singly Circular Linked List : ");
    displaySCLL(last);

    last = insertEnd(last);

    printf("\n\t Singly Circular Linked List after insertion of node at the end : ");
    displaySCLL(last);
    
    freeSCLL(last);
    last = NULL;

    return 0;
    
}

SCLLNode* createSCLL() {

    SCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = (SCLLNode*)malloc(sizeof(SCLLNode));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\tEnter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

        nw -> next = nw;

        if (head == NULL) {
            head = nw;
        }
        else {
            last -> next = nw;
            nw -> next = head;
        }
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

SCLLNode* insertEnd(SCLLNode *last) {
    
    SCLLNode *nw = NULL;
    nw = (SCLLNode*)malloc(sizeof(SCLLNode));
    if (nw == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter number and name of the node to be inserted at the end : ");
    scanf("%d", &(nw -> number));
    getchar();
    fgets(nw -> name,20,stdin);
    nw -> name[strcspn(nw -> name,"\n")] = '\0';
    
    nw -> next = last -> next;
    last -> next = nw;
    last = nw;

    return last;

}

void displaySCLL(SCLLNode *last) {
    
    SCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n|_Head_| ");

    for ( ; d != last ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("--> |_%d_|_%s_|_%p_| <-- |_last_|", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSCLL(SCLLNode *last) {

    if (last == NULL)
        return;

    SCLLNode *f = NULL,*t = NULL;
    f = last -> next;

    while (f != last) {
        t = f;   
        f = f -> next;
        free(t);
        t = NULL;
    }
    
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
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Singly Circular Linked List :

            |_Head_| --> |_1_|_AA_|_00C61388_| --> |_2_|_BB_|_00C613B0_| --> |_3_|_CC_|_00C62FC0_| <-- |_last_|


                    Enter number and name of the node to be inserted at the end : 5 MM

                    Singly Circular Linked List after insertion of node at the end :

            |_Head_| --> |_1_|_AA_|_00C61388_| --> |_2_|_BB_|_00C613B0_| --> |_3_|_CC_|_00C613D8_| --> |_5_|_MM_|_00C62FC0_| <-- |_last_|
*/