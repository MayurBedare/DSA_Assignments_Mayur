/*
    A-9 ->  write a c program to create a circular singly linked list and delete the node by position
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SCLLNode
{
    int number;
    char name[20];
    struct SCLLNode *next;
} SCLLNode;

SCLLNode* createSCLL();
SCLLNode* deletePos(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    printf("\n\t ***** Delete a node at the given position : Singly Circular Linked List ***** \n");

    printf("\n\t -------------------------------------------------------------");
    printf("\n\t Create a linked list to insert a node at the given position : \n");
    printf("\t ------------------------------------------------------------- \n");

    last = createSCLL();

    printf("\n\t -------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displaySCLL(last);
    
    while (1) {
        int ch; 
        printf("\n\t --------------------------------------");
        printf("\n\t 1. Delete a node at the given position ");
        printf("\n\t 2. Exit ");
        printf("\n\t --------------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t ---------------------------------------- \n");
        
        switch (ch) {
            case 1:
                if (last == NULL) {
                    printf("\n\t Linked List is Empty! \n\n");
                    exit(0);
                }
                last = deletePos(last);
                break;
            
            case 2:
                freeSCLL(last);
                last = NULL;
                printf("\n\t Program Exited Successfully. \n\n");
                exit(0);

            default: 
                printf("\n\t Invalid Choice Entered! \n");
                break;
        }
    }

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

        printf("\n\t Enter Number and Name : ");
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

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

SCLLNode* deletePos(SCLLNode *last) {

    int pos,flag = 0;
    SCLLNode *d = NULL,*prev = NULL;
    d = last -> next;

    printf("\n\t Enter the position of the node to be deleted from the given linked list : ");
    scanf("%d",&pos);

    if (pos == 1) {
        flag = 1;
        if (d == last) {
            free(d);
            d = NULL;
            return d;
        }
        last -> next = d -> next;
        free(d);
        d = NULL;
    } else {
        int i;
        for (prev = d,d = d -> next,i = 1 ; i < (pos - 1) && d != last ; prev = prev -> next,d = d -> next,i++);

        if (d != last) {
            flag = 1;
            prev -> next = d -> next;
            free(d);
            d = NULL;
        } else {
            if (i == (pos - 1)) {
            flag = 1;
            prev -> next = d -> next;
            last = prev;
            free(d);
            d = NULL;
            } else {
                printf("\n\t Invalid Position entered! \n");
            }
        }
    }

    if (flag == 1) {
        printf("\n\t Linked List after deletion of node at the given position : ");
        displaySCLL(last);
    }

    return last;

}

void displaySCLL(SCLLNode *last) {
    
    SCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n\t |_Head_| ");

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

