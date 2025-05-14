/*
    A-13 -> write a c program to Create a Singly linked list and Delete the node depending on user input key/value
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
SLLNode* keyNodeDeletion(SLLNode*);

int main() { 
    SLLNode *head = NULL;

    printf("\n\t ***** Delete a node at the given key/value : Singly Linked List ***** \n");

    printf("\n\t --------------------------------------------------------------");
    printf("\n\t Create a linked list to delete a node at the given key/value : \n");
    printf("\t -------------------------------------------------------------- \n");

    head = createSLL();

    printf("\n\t -------------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displaySLL(head);
    
    while (1) {
        int ch; 
        printf("\n\t --------------------------------------- ");
        printf("\n\t 1. Delete a node at the given key/value ");
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
                head = keyNodeDeletion(head);

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

SLLNode* keyNodeDeletion(SLLNode *head) {

    SLLNode *del = NULL, *prev = NULL;
    int temp;

    int pos,flag = 0;
    printf("\n\t Enter key/value ie Node's number Eg. 1 AA -> key/value is 1 : ");
    scanf("%d", &temp);
    
    if (head -> next == NULL && temp == head -> number) {
        flag = 1;
        free(head);
        head = NULL;
    } else {
        for (del = head,prev = del ; temp != del -> number && del -> next != NULL ; prev = del, del = del -> next);

        if (temp == del -> number) {
            flag = 1;
            if (del -> next !=  NULL) {
                if (del == head)    head = head -> next;
                else    prev -> next = del -> next;
                free(del);
                del = NULL;
            } else {
                prev -> next = NULL;
                free(del);
                del = NULL;
            }
        } else {
            printf("\n\t Invalid key/value Entered! \n");
        }
    }

    if ( flag == 1) {
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
