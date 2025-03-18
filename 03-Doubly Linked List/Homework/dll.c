#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DNode {
    
    int no;
    char name[20];
    struct DNode *next;
    struct DNode *prev;
}DNode;
//Function Declaration
DNode* create();
void printList(DNode*);
void printReverse(DNode*);
void freeList(DNode*);

int main() {

    int choice;
    DNode *start = NULL;

    while (!choice)
    {
        printf("\n\t*****Menu Driven Program = Doubly Linked List");
        printf("\n\t1.Create List");
        printf("\n\t2.Print List");
        printf("\n\t3.Print Reverse List");
        printf("\n\t4.Exit");
        printf("\n\tEnter you choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create();
            break;

        case 2:
            printList(start);
            break;

        case 3:
            printReverse(start);
            break;

        case 4:
            freeList(start);
            exit(0);
        
        default:
            printf("\n\t Invalid choice! Please try again.");
        }
    }
    
    return 0;
}

DNode* create() {

    DNode *head = NULL, *tail = NULL, *newNode;
    int ans;

    do {
        newNode = (DNode*)malloc(sizeof(DNode));
        if(!newNode) {
           printf("\n\tMemory Allocation Failed!");
           exit(1);
        }
        printf("\n\tEnter the number and name :");
        scanf("%d %s", &(newNode -> no), newNode -> name);
        newNode -> next = NULL;
        newNode -> prev = tail;

        if (head == NULL)
            head = newNode;
        else    
            tail -> next = newNode;
        
        tail = newNode;

        printf("\n\tDo you want to enter more records?(1(yes)/0(no)):");
        scanf("%d", &ans);
    } while (ans == 1);
      
    return head;
}

void printList(DNode *head) {

    if(!head) {

        printf("\n\tList is empty");
        return;
    }

    printf("\n\tDoubly Linked List:");
    for (;head != NULL; head = head -> next)
        printf("\n\tNo : %d, Name : %s",head -> no, head -> name);
}

void printReverse(DNode *head) {

    if(!head) {

        printf("\n\tList is Empty!");
        return;
    }

    DNode *tail = head;
    
    while (tail -> next != NULL)
        tail = tail -> next;

    printf("\n\tDoubly Linked List in Reverse Order :");
    for(; tail != NULL; tail = tail -> prev)
        printf("\n\tNo : %d, Name : %s",tail -> no, tail -> name);
}

void freeList(DNode *head) {
    
    DNode *temp;

    while (head) {
        temp = head;
        head = head  -> next;
        free(temp);
    }
    
}

