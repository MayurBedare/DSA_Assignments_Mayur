/*
    A-6 ->  write a c program to Create a circular doubly linked list and delete the node which key matches the user's key
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DCLLNode
{
    int number;
    char name[20];
    struct DCLLNode *next;
    struct DCLLNode *prev;
} DCLLNode;

DCLLNode* createDCLL();
DCLLNode* deleteKey(DCLLNode*);
void displayDCLL(DCLLNode*);
void freeDCLL(DCLLNode*);

int main() {
   
    DCLLNode *last = NULL;

    printf("\n\t ***** Delete a node at the given key : Doubly Circular Linked List ***** \n");

    printf("\n\t --------------------------------------------------------");
    printf("\n\t Create a linked list to delete a node at the given key : \n");
    printf("\t -------------------------------------------------------- \n");

    last = createDCLL();

    printf("\n\t -------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displayDCLL(last);
    
    while (1) {
        int ch; 
        printf("\n\t ---------------------------------");
        printf("\n\t 1. Delete a node at the given key ");
        printf("\n\t 2. Exit ");
        printf("\n\t ---------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t --------------------------------- \n");
        
        switch (ch) {
            case 1:
                if (last == NULL) {
                    printf("\n\t Linked List is Empty! \n");
                    break;
                }
                last = deleteKey(last);
                break;
            
            case 2:
                freeDCLL(last);
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

DCLLNode* createDCLL() {

    DCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = (DCLLNode*)malloc(sizeof(DCLLNode));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\t Enter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = nw;
        nw -> prev = nw;

        if (head == NULL) {
            head = nw;
        }
        else {
            last -> next = nw;
            nw -> prev = last;
            nw -> next = head;
            head -> prev = nw;
        }
        
        last = nw;

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

DCLLNode* deleteKey(DCLLNode *last) {

    int t,flag = 0;
    DCLLNode *p = NULL;
    p = last -> next;

    printf("\n\t Enter the kay/value of the node to be deleted eg.1 AA : ");
    scanf("%d", &t);

    if (p -> number == t) {
        flag = 1;
        if (p == last) {
            free(p);
            p = NULL;
            return p;
        }
        last -> next = p -> next;
        p -> next -> prev = last;
        free(p);
        p = NULL;
    } else {
        for (p = p -> next ; p -> number != t && p != last ; p = p -> next);

        if (p -> number == t) {
            flag = 1;
            p -> prev -> next = p -> next;
            p -> next -> prev = p -> prev;
            if (p == last) {
                last -> next -> prev = p -> prev;
                last = p -> prev;
            }
            free(p);
            p = NULL;
        } else {
            printf("\n\t Key not found! \n");
        }
    }

    if (flag == 1) {
        printf("\n\t Linked List after deletion of the key : ");
        displayDCLL(last);
    }

    return last;

}

void displayDCLL(DCLLNode *last) {

    DCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n\t |_Head_| ");
    printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);


    for (d = d -> next ; d != last -> next ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf(" <--> |_last_|");

    printf("\n");

}

void freeDCLL(DCLLNode *last) {

    if (last == NULL)
        return;

    DCLLNode *f = NULL;
    f = last -> next;

    while (f != last) {   
        f = f -> next;
        free(f -> prev);
        f -> prev = NULL;
    }

    free(f);
    f = NULL;

}
