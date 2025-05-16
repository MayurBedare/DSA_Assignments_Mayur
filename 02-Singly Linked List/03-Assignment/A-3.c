/*
    A-3 ->  write a c program to Create a Singly linked list and Display the alternate nodes 

            I/P  ---->  |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_NULL_|. 

            O/P  ---->  |_1_|_AA_|_100_| --> |_3_|_CC_|_300_| --> |_5_|_EE_|_NULL_| 
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
void alternateSLL(SLLNode*);
void freeSLL(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    alternateSLL(head);

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

void alternateSLL(SLLNode *head) {

    SLLNode *alt_p = NULL;

    if ( head -> next == NULL || head -> next -> next == NULL ) { 
        printf("\n\tDisplaying Alternate Nodes not possible!\n\n");
    }
    else {
        printf("\n\tLinked List with Alternate nodes : ");
        printf("\n\n|_head_| ");

        for (alt_p = head ; alt_p -> next != NULL && alt_p -> next -> next != NULL ; alt_p = alt_p -> next -> next) {
        
            printf("--> |_%d_|_%s_|_%p_| ", alt_p -> number,  alt_p -> name, alt_p -> next);
        
        }
        
        printf("--> |_%d_|_%s_|_%p_| \n\n", alt_p -> number,  alt_p -> name, alt_p -> next);
    }

    free(alt_p);
    alt_p = NULL;

}

void displaySLL(SLLNode *d) {

    printf("\n\n|_head_| ");
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
