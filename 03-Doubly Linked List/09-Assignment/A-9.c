/*
    A-9 ->  write a c program to Create a doubly linked list, accept a key, and delete the node which contains the key element. 
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
DLLNode* deleteKey(DLLNode*);

int main() { 
    DLLNode *head = NULL;

    printf("\n\t ***** Delete a node at the given key : Doubly Linked List ***** \n");

    printf("\n\t --------------------------------------------------------");
    printf("\n\t Create a linked list to delete a node at the given key : \n");
    printf("\t -------------------------------------------------------- \n");

    head = createDLL();

    printf("\n\t -------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displayDLL(head);
    
    while (1) {
        int ch; 
        printf("\n\t ---------------------------------");
        printf("\n\t 1. Delete a node at the given key ");
        printf("\n\t 2. Exit ");
        printf("\n\t ---------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t ----------------------------------- \n");
        
        switch (ch) {
            case 1:
                if (head == NULL) {
                    printf("\n\t Linked List is Empty! \n\n");
                    exit(0);
                }
                head = deleteKey(head);
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

DLLNode* deleteKey(DLLNode *head) {

    DLLNode *del = NULL;
    int temp;

    int flag = 0; 

    printf("\n\t Enter key ie Node's key(number) Eg. 1 AA -> key is 1 : ");
    scanf("%d", &temp);
    
    if (head -> next == NULL && temp == head -> number) {
        flag = 1;
        free(head);
        head = NULL;
    } else {
        for (del = head ; temp != del -> number && del -> next != NULL ; del = del -> next);
        
        if (temp == del -> number) {
            flag = 1;
            if (del -> next != NULL) {
                if (del == head) {
                    head = del -> next;
                    head -> prev = NULL;
                } else {
                    del -> prev -> next = del -> next;
                    del -> next -> prev = del -> prev;
                }  
            } else {
                del -> prev -> next = NULL;
            }
            free(del);
            del = NULL;
        } else {
            printf("\n\t Invalid Key/Value Entered! \n");
        }
    }

    if (flag == 1) {
        printf("\n\t Linked List after Deletion of node at Given key/value : ");
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

