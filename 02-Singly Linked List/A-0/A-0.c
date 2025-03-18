/*
    A- -> 
*/

/* 
    Input ->                        
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
void displaySLL(SLLNode*);
//function declaration

int main() {
    
    SLLNode *head = NULL;

    head = createSLL();

    //function calling

    displaySLL(head);

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

//function definition

void displaySLL(SLLNode *p) {

    printf("\n\t|_head_| ");
    for ( ; p != NULL ; p = p -> next )
        printf("--> |_%d_|_%s_|_%p_| ", p -> number, p -> name, p -> next);

    printf("\n\n");

}

/*
    Output ->                                
*/