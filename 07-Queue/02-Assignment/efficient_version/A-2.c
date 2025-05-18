/*
    A-2 ->  write a c program to Create a queue and perform enqueue and dequeue operations(using Linked List) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    int no;
    char name[10];
    struct Queue *next;
} node;

int isEmpty(node*);
node* enqueue(node*,int,char*);
node* dequeue(node**,node*);
void display(node*);

int main() {
    node *front = NULL,*rear = NULL;
    int choice,num;
    char name[10];

    while (1) {
        printf("\n Queue using linked list \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if empty\n");
        printf("5. Exit");
        printf("\n Enter your choice : ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("\n Enter no & name : ");
                scanf("%d %s",&num,name);
                rear = enqueue(rear,num,name);
                if  (front == NULL) front = rear;
                break;
            case 2: rear= dequeue(&front,rear);break;
            case 3: display(front); break;
            case 4: 
                if  (isEmpty(front)) printf("Queue is empty!");
                else    printf("Exiting"); exit(0);
            default: 
                printf("Invalid choice!");
        }
    }
    return 0;
}

int isEmpty(node *front) {
    return front == NULL;
}

node* enqueue(node* rear,int num, char *name) {
    node *newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory Allcoation Failed!");
        return rear;
    }
    newNode->no = num;
    strcpy(newNode->name,name);
    newNode->next = NULL;
    if (rear == NULL) {
        return newNode;
        rear->next = newNode;
        return newNode;
    }
}

node *dequeue(node **front,node *rear) {
    if (isEmpty(*front)) {
        printf("Queue is empty!");
        return rear;
    }

    node *temp = *front;
    printf("\n Dequeued : %d %s ",temp->no,temp->name);
    *front = (*front)->next;
    if (*front == NULL) rear = NULL;
    free(temp);
    return rear;
}

void display(node *front) {
    if (isEmpty(front)) {
        printf("\n Queue is Empty!");
        return;
    }
    node *temp = front;
    printf("\n Queue elements: \n");

    while (temp != NULL) {
        printf("%d %s \t",temp -> no, temp -> name);
        temp = temp -> next;
    }
}