/*
    A-15 -> write a c program to Create a Singly linked list and sort the linked list
*/

/* 
    Input ->                        
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
void sort(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    printf("\n\tLinked List : ");
    displaySLL(head);

    sort(head);
    
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

void sort(SLLNode *head) {

    SLLNode *p1 = NULL, *p2 = NULL,temp;

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

    printf("\n\tSorted Linked List : ");
    displaySLL(head);

}

void displaySLL(SLLNode *d) {

    printf("\n\n|_Head_| ");
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
*/