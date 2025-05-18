/*
    A-3 ->  Write a C program to implement a Priority Queue using a Normal Array.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 5 

typedef struct {
    int queue[MAX];
    int front, rear;
} PriorityQueue;

void insert(PriorityQueue* pq, int value);
int delete_min(PriorityQueue* pq);
void peek(PriorityQueue* pq);
void display(PriorityQueue* pq);

int main() {
    int choice, value;
    PriorityQueue pq;
    pq.front = pq.rear = -1;

    while(1) {
        printf("\n*** Min-Priority Queue (Array with Front & Rear) ***");
        printf("\n1. Insert");
        printf("\n2. Delete Min");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                insert(&pq,value);
                break;
            case 2: 
                value = delete_min(&pq);
                if (value != -1) {
                    printf("Deleted minimum value: %d\n",value);
                }
                break;
            case 3:
                peek(&pq);
                break;
            case 4:
                display(&pq);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.");
        }
    }

    return 0;   
}

void insert(PriorityQueue* pq,int value) {
    if (pq->rear >= MAX-1) {
        printf("Queue is full. Cannot insert more elements.\n");
        return;
    }

    if (pq->front == -1 && pq->rear == -1) {
        pq->front = pq->rear = 0;
        pq->queue[pq->rear] = value;
        return;
    }

    int i = pq->rear;
    while (i >= pq->front && pq->queue[i] > value) {
        pq->queue[i + 1] = pq->queue[i];
        i--;
    }
    pq->queue[i + 1] = value;
    pq->rear++;
}

int delete_min(PriorityQueue* pq) {
    if (pq->front == -1) {
        printf("Queue is empty. Nothing to delete.\n");
        return -1;
    }

    int min_value = pq->queue[pq->front];

    for (int i = pq->front ; i < pq->rear ; i++) {
            pq->queue[i] = pq->queue[i + 1];
    }

    pq->rear--;
    if (pq->rear == -1) {
        pq->front = -1;
    }

    return min_value;
}

void peek(PriorityQueue* pq) {
    if (pq->front == -1) {
        printf("Queue is Empty.\n");
    } else {
           printf("Minimum value: %d\n",pq->queue[pq->front]);
    }
}

void display(PriorityQueue* pq) {
    if (pq->front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue Elements: %d");
        for (int i = pq->front ; i <= pq->rear ; i++) {
            printf("%d ",pq->queue[i]);
        }
            printf("\n");
    }
}

