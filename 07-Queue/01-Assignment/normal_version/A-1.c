/*
    A-1 ->  write a c program to Create a queue and perform enqueue and dequeue operations(using array)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 4

typedef struct queue
{
    int no;
    char name[20];
} que;

int enqueue(int, que*);
int dequeue(int);
int isEmpty(int, int);
int isFull(int, int);
void display(int, int, que*);

void main() {
    int front = 0,rear = -1;
    que arr[MAX];

    while (1) {
        int ch;
        printf("\n\t *****************");
        printf("\n\t Queue using array");
        printf("\n\t *****************");
        printf("\n\t 1. Enqueue");
        printf("\n\t 2. Dequeue");
        printf("\n\t 3. Exit");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);

        switch (ch) {
            case 1:
                if (!isFull(front, rear)) {
                    break;
                }
                rear = enqueue(rear, arr);
                display(front, rear, arr);
                break;
        
            case 2:
                if (front > rear && rear <= (MAX-1)) {
                    printf("\n\t These operation not allowed!");
                    break;
                }
                if (!isEmpty(front, rear)) { 
                    break;
                }
                front = dequeue(front);
                display(front, rear, arr);      
                break;

            case 3:
                exit(0);
            
            default:
                printf("\n\t Invalid Choice Entered!");
                break;
        }
    }
}

int enqueue(int rear, que arr[]) {
    rear++;
    printf("Enter the number and name to be enqueued : ");
    scanf("%d", &(arr[rear].no));
    getchar();//Clear the buffer using fgets 
    fgets(arr[rear].name, sizeof(arr[rear].name), stdin);
    arr[rear].name[strcspn(arr[rear].name, "\n")] = '\0';//Remove newline character
    return rear;    
}

int dequeue(int front) {

    front++;

    return front;
}

int isEmpty(int front, int rear) {
    if ((front == 0) && (rear == -1)) {
        printf("\n\t Queue is Empty!\n");
        return 0;
    } else if (front > rear  && front <= (MAX-1)) {
        printf("\n\t Queue is Empty technically!\n");
        return 0;
    }
    return 1;
}

int isFull(int front, int rear) {
    if ((front == 0) && (rear == (MAX - 1))) {
        printf("\n\t Queue is Full!\n");
        return 0;
    } else if (rear == (MAX - 1))  {
        printf("\n\t Queue is Full technically!\n");
        return 0;
    }   
    return 1;
} 

void display(int front, int rear, que arr[]) {
    if (!isEmpty(front, rear)) { 
        return;
    }
    if (front == rear) {
                printf("\n\t |_%d_|_%s_| <- Front <- Rear", arr[front].no, arr[front].name);
    } else {
        for (int i = front ; i != rear + 1 ; i++) {
            if (front == i) {
                printf("\n\t |_%d_|_%s_| -> Front", arr[front].no, arr[front].name);
            } else if (rear == i) {
                printf("\n\t |_%d_|_%s_| -> Rear", arr[rear].no, arr[rear].name);
            } else {
                printf("\n\t |_%d_|_%s_|", arr[i].no, arr[i].name);
            }
        }
    }
    printf("\n");
}