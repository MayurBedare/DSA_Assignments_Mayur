/*
    A-3 ->  write a c program to Create a circular singly  linked list and insert a new node  at given position  
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
SCLLNode* insertPos(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    printf("\n\t ***** Insert a node at the given position : Singly Circular Linked List ***** \n");

    printf("\n\t -------------------------------------------------------------");
    printf("\n\t Create a linked list to insert a node at the given position : \n");
    printf("\t ------------------------------------------------------------- \n");

    last = createSCLL();

    printf("\n\t ------------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displaySCLL(last);
    
    while (1) {
        int ch; 
        printf("\n\t --------------------------------------");
        printf("\n\t 1. Insert a node at the given position ");
        printf("\n\t 2. Exit ");
        printf("\n\t --------------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t -------------------------------------- \n");
        
        switch (ch) {
            case 1:
                last = insertPos(last);
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

SCLLNode* insertPos(SCLLNode *last) {

    SCLLNode *p = NULL;
    p = last -> next;

    SCLLNode *nw = NULL;
    nw = (SCLLNode*)malloc(sizeof(SCLLNode));
    if (nw == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter number and name of the node to be inserted at the given position : ");
    scanf("%d %s", &(nw -> number),nw -> name);
    nw -> next = NULL;

    int pos,flag = 0;
    printf("\n\t Enter the position where new node to be insereted : ");
    scanf("%d",&pos);

    if (pos == 1) {
        flag = 1;
        nw -> next = last -> next;
        last -> next = nw;
    } else {
        int i;
        for(i = 1 ; i < (pos - 1) && p != last ; i++, p = p -> next);

        if (p != last) {
            flag = 1;
            nw -> next = p -> next;
            p -> next = nw;
        } else {
            if (i == (pos - 1)) {
            flag = 1;
            nw -> next = p -> next;
            p -> next = nw;
            last = nw;
            } else {
                printf("\n\t Invalid position entered! \n");
                free(nw);
                nw = NULL;
            }
        }
    }

    if (flag == 1) {
        printf("\n\t Linked list after Insertion of node at given position : ");
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

    printf("\n");

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

