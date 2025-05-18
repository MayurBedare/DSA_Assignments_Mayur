/*
    A-1 ->  write a c program to Create a queue and perform enqueue and dequeue operations(using array)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct Queue {
    int no;
    char name[10];
} queue;

int enqueue(int ,queue*);
int dequeue(int,int,queue*);
void display(int,int,queue*);

int main() {
    queue a[MAX];
    int front = 0,rear = -1;
    int ch;

    while (1) {
        printf("\n\n\t Queue with array ");
        printf("\n\t 1. Enqeue");
        printf("\n\t 2. Dequeue");
        printf("\n\t 3. Display");
        printf("\n\t 4. Exit");
        printf("\n\t Enter your choice :");
        scanf("%d",&ch);
        switch(ch) {
            case 1: rear = enqueue(rear,a);break;
            case 2: front = dequeue(front,rear,a);
                    if(front == 0)  rear = -1;
                    break;
            case 3: display(front,rear,a);break;
            case 4: exit(0);

            default: printf("Invalid choice");
        }
    }
    return 0;
}

int enqueue(int rear,queue *a) {
    if (rear == MAX-1)  printf("\n\t Queue is Full!");
    else {
        rear++;
        printf("Eneter no. & name: ");
        scanf("%d %s",&a[rear].no,&a[rear].name);
    }
    return rear;
}

int dequeue(int front,int rear, queue *a) {
    if (rear == -1) printf("Queue is Empty!");
    else if (front == rear) front = 0;
    else {
        printf("%d is deleted.",a[front].no);
        front++;
    }
    return front;
}

void display(int front,int rear,queue *a) {
    if (rear == -1) {
        printf("\n\t Queue is empty");
        return;
    }
    for (int i = front ; i <= rear ; i++) {
        printf("\n\t %d %s",a[i].no,a[i].name);
    }
}
