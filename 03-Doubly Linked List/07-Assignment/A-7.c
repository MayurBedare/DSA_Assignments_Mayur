/*
    A-7 ->  write a c program to Create a doubly linked list and Delete a node at given position.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DLLNode
{
    int number;
    char name[20];
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

DLLNode* createDLL();
void displayDLL(DLLNode*);
void freeDLL(DLLNode*);
DLLNode* deletePosition(DLLNode*);

int main() {
    DLLNode *head = NULL;

    printf("\n\t ***** Delete a node at the given position : Doubly Linked List ***** \n");

    printf("\n\t -------------------------------------------------------------");
    printf("\n\t Create a linked list to delete a node at the given position : \n");
    printf("\t ------------------------------------------------------------- \n");

    head = createDLL();

    printf("\n\t ------------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displayDLL(head);
    
    while (1) {
        int ch; 
        printf("\n\t --------------------------------------");
        printf("\n\t 1. Delete a node at the given position ");
        printf("\n\t 2. Exit ");
        printf("\n\t --------------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t -------------------------------------- \n");
        
        switch (ch) {
            case 1:
                if (head == NULL) {
                    printf("\n\t Linked list is empty! \n\n");
                    exit(1);
                }
                head = deletePosition(head);
                break;
            
            case 2:
                freeDLL(head);
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

DLLNode* createDLL() {

    DLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = (DLLNode*)malloc(sizeof(DLLNode));
        if (nw == NULL)
        {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\t Enter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

        nw -> next = NULL;

        if (head == NULL) {
            head = nw;
            nw -> prev = NULL;
        }
        else {
            last -> next = nw;
            nw -> prev = last;
        }
        
        last = nw;

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

DLLNode* deletePosition(DLLNode *head) {

    DLLNode *del = NULL,*temp = NULL;
    del = head;

    int pos,flag = 0;
    printf("\n\t Enter the position of the node to be deleted : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        flag = 1;
        head = del -> next;
        if (head != NULL)   head -> prev = NULL;
        free(del);
        del = NULL;
    } else {
        for (int i = 1 ; i < pos-1 && del -> next != NULL ; del = del -> next,i++);
    
        if (del -> next != NULL) {
            flag = 1; 
            del -> next = del -> next -> next;
            free(del -> next -> prev );
            del -> next -> prev = NULL;
        } else {
            printf("\n\t Invalid Position Entered! \n");
        }
    }

    if (flag == 1) {
        printf("\n\t Linked list after Deletion of node at the given position : ");
        displayDLL(head);
    }

   return head;

}

void displayDLL(DLLNode *d) {

    printf("\n\n\t |_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf("\n");

}

void freeDLL(DLLNode *f) {
    DLLNode *t = NULL;

    while (f != NULL) {
        t = f;
        f = f -> next;
        free(t);
    }
}
