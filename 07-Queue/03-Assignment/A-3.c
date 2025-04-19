/*
    A-3 ->  write a c program to create a circular queue and perform enqueue and dequeue operations (with array) 
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
int dequeue(int, que*);
int isEmpty(int, int, que*);
int isFull(int, int, que*);
void display(int, int, que*);

void main() {
    int front = 0,rear = -1;
    que arr[MAX];

    while (1) {
        int ch;
        printf("\n\t **************************");
        printf("\n\t Circular Queue using array");
        printf("\n\t **************************");
        printf("\n\t 1.Enqueue");
        printf("\n\t 2.Dequeue");
        printf("\n\t 3.Exit");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);

        switch (ch) {
            case 1:
                if (!isFull(front, rear, arr)) {
                    break;
                }
                rear = enqueue(rear, arr);
                display(front, rear, arr);
                break;
        
            case 2:
                if (!isEmpty(front, rear, arr)) { 
                    break;
                }
                front = dequeue(front, arr);
                if ((front == 0) && (rear == (MAX - 1))) {
                    rear = -1; 
                }
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
    if (rear == (MAX - 1))
        rear = -1;

    rear++;
    printf("Enter the number and name to be enqueued : ");
    scanf("%d", &(arr[rear].no));
    getchar();//Clear the buffer using fgets 
    fgets(arr[rear].name, sizeof(arr[rear].name), stdin);
    arr[rear].name[strcspn(arr[rear].name, "\n")] = '\0';//Remove newline character
    return rear;    
}

int dequeue(int front, que arr[]) {

    arr[front].no = 0;
    strcpy(arr[front].name,"--");
    front++;

    if (front == MAX)
        front = 0;

    return front;
}

int isEmpty(int front, int rear, que arr[]) {
    if ((front == 0) && (rear == -1)) {
        printf("\n\t Queue is Empty!");
        return 0;
    } else if (((front - 1) == rear) && (front != 0) && arr[rear].no == 0) {
        printf("\n\t Queue is Empty!");
        return 0;
    } else {
        return 1;
    }
}

int isFull(int front, int rear, que arr[]) {
    if ((front == 0) && (rear == (MAX - 1))) {
        printf("\n\t Queue is Full!");
        return 0;
    } else if (((front - 1) == rear) && (rear != -1) && arr[rear].no != 0) {
        printf("\n\t Queue is Full!");
        return 0;
    } else {
        return 1;
    }
} 

void display(int front, int rear, que arr[]) {
    int i = 0;
    if (front == rear) {
        for ( ; i != MAX ; i++) {
            if (front == i) 
                printf("\n\t |_%d_|_%s_| <- Front <- Rear", arr[i].no, arr[i].name);
            else 
                printf("\n\t |_%d_|_%s_|", arr[i].no = 0, strcpy(arr[i].name,"--"));
        }
    } else {
        for ( ; i != MAX ; i++) {
            if (front == i) {
                printf("\n\t |_%d_|_%s_| -> Front", arr[i].no, arr[i].name);
            } else if (rear == i) {
                printf("\n\t |_%d_|_%s_| -> Rear", arr[i].no, arr[i].name);
            } else {
                printf("\n\t |_%d_|_%s_|", arr[i].no, arr[i].name);
            }
        }
    }
    printf("\n");
}