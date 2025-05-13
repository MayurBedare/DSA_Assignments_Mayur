/*
    A-11 -> write a c program to Create a Singly linked list and Delete the node in the given position
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
void freeSLL(SLLNode*);
SLLNode* positionNodeDeletion(SLLNode*);

int main() { 
    SLLNode *head = NULL;

    printf("\n\t ***** Delete a node at the given position : Singly Linked List ***** \n");

    printf("\n\t -------------------------------------------------------------");
    printf("\n\t Create a linked list to delete a node at the given position : \n");
    printf("\t ------------------------------------------------------------- \n");

    head = createSLL();

    printf("\n\t ------------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displaySLL(head);
    
    while (1) {
        int ch; 
        printf("\n\t --------------------------------------- ");
        printf("\n\t 1. Delete a node at the given position ");
        printf("\n\t 2. Exit ");
        printf("\n\t --------------------------------------- ");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t --------------------------------------- \n");
        
        switch (ch) {
            case 1:
                if (head == NULL) {
                    printf("\n\t Linked list is empty! \n\n");
                    exit(1);
                }
                head = positionNodeDeletion(head);
                break;
            
            case 2:
                freeSLL(head);
                head = NULL;
                printf("\n\t Program Exited Successfully. \n\n");
                exit(0);

            default: 
                printf("\n\t Invalid Choice Entered! \n");
                break;
        }
    }
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

        printf("\n\t Enter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = NULL;

        if (head == NULL)
            head = nw;
        else 
            last -> next = nw;
        
        last = nw;

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

SLLNode* positionNodeDeletion(SLLNode * head) {

    SLLNode *del = NULL,*temp = NULL;
    del = head;

    int pos,flag = 0;
    printf("\n\t Enter the position of the node to be deleted : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        flag = 1;
        head = del -> next;
        free(del);
        del = NULL;
    } else {
        for (int i = 1 ; i < pos-1 && del -> next != NULL ; del = del -> next,i++);

        if (del -> next != NULL) {
            flag = 1;
            temp = del -> next;
            del -> next = del -> next -> next;
            free(temp);
            temp = NULL;
        } else {
            printf("\n\t Invalid Position Entered! \n");
        }
    }

    if (flag == 1) {
        printf("\n\t Linked list after Deletion of node at the given position : ");
        displaySLL(head);
    }

    return head;

}

void displaySLL(SLLNode *d) {

    printf("\n\n\t |_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("\n");

}

void freeSLL(SLLNode *f) {
    SLLNode *t = NULL;

    while (f != NULL) {
        t = f;
        f = f -> next;
        free(t);
    }
}

