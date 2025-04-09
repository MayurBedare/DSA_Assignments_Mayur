/*
    A-6 ->  write a c program to Create a circular singly linked list and delete the node which key matches the user's key
*/

/*
    Input -> |_Head_| --> |_1_|_AA_|_00DB1388_| --> |_2_|_BB_|_00DB13B0_| --> |_3_|_CC_|_00DB2FC0_| <-- |_last_| 
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
SCLLNode* deleteKey(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    last = createSCLL();

    printf("\n\t Singly Circular Linked List : ");
    displaySCLL(last);

    last = deleteKey(last);

    if (last == NULL) {
        printf("\n\t Singly Circular Linked List is empty!\n\n");
        exit(0);
    }

    printf("\n\t Singly Circular Linked List after deletion of the key/value : ");
    displaySCLL(last);
    
    freeSCLL(last);

    return 0;
    
}

SCLLNode* createSCLL() {

    SCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = malloc(sizeof(SCLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

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

SCLLNode* deleteKey(SCLLNode *last) {

    SCLLNode *p = NULL,*prev = NULL,t;
    p = last -> next;

    printf("\n\t Enter the kay/value of the node to be deleted eg.1 AA : ");
    scanf("%d %s", &(t.number), t.name);

    if (p -> number == t.number && !(strcmp(p -> name, t.name))) {
        if (p == last) {
            free(p);
            p = NULL;
            return p;
        }
        last -> next = p -> next;
        free(p);
        p = NULL;
    } else {
        for (prev = p,p = p -> next ; p -> number != t.number && (strcmp(p -> name, t.name)) && p != last ; p = p -> next,prev = prev -> next);

        if (p -> number == t.number && !(strcmp(p -> name, t.name))) {
            if (p != last) {
                prev -> next = p -> next;
                free(p);
                p = NULL;
            } else {
                prev -> next = p -> next;
                free(p);
                p = NULL;
                last = prev;
            }
        } else {
            printf("\n\t Key/Value not found!\n\n");
            exit(0);
        }
    }

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

            |_Head_| --> |_1_|_AA_|_00DB1388_| --> |_2_|_BB_|_00DB13B0_| --> |_3_|_CC_|_00DB2FC0_| <-- |_last_|


                    Enter the kay/value of the node to be deleted eg.1 AA : 2 BB 

                    Singly Circular Linked List after deletion of the key/value : 

            |_Head_| --> |_1_|_AA_|_00DB13B0_| --> |_3_|_CC_|_00DB2FC0_| <-- |_last_|
*/