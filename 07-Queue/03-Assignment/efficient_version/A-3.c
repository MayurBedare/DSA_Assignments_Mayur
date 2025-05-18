/*
    A-1 ->  write a c program to Create a queue and perform enqueue and dequeue operations(using array)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct {
    int no;
    char name[20];
} Data;

typedef struct {
    Data arr[MAX];
    int front, rear;
} CircularQue;

void initQueue(CircularQue *q);
int isFull(CircularQue *q);
int isEmpty(CircularQue *q);
void insert(CircularQue *q);
void delete(CircularQue *q);
void display(CircularQue *q);

int main() {
    CircularQue q;
    int ch;

    initQueue(&q);

    while (1) {
        printf("\n========== Circular Queue Menu ==========\n");
        printf("1. Insert\n2. Delete\n3. Dispaly\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch (ch) {
            case 1:
                insert(&q);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void initQueue(CircularQue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQue *q) {
    return (q ->front == (q->rear + 1) % MAX);
}

int isEmpty(CircularQue *q) {
    return (q->front == -1);
}

void insert(CircularQue *q) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert.\n");
        return;
    }

    Data a;
    printf("Enter number and name: ");
    scanf("%d %s",&a.no,a.name);

    if (isEmpty(q)) {
        q ->front = q ->rear = 0;
    } else {
        q->rear = (q->rear+1) % MAX;
    }

    q->arr[q->rear] = a;
    printf("Inserted successfully!\n");
}

void delete(CircularQue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot delete.\n");
        return;
    }

    printf("Deleted element: %d, %s\n", q->arr[q->front].no,q->arr[q->front].name);

    if (q->front == q->rear) {
        initQueue(q);
    } else {
        q->front = (q->front + 1) & MAX;
    }
}

void display(CircularQue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue Elements:\n");
    int i = q->front;
    while (1) {
        printf(" %d %s\n",q->arr[i].no,q->arr[i].name);
        if (i == q->rear)   break;
        i = (i + 1) % MAX;
    }
}
