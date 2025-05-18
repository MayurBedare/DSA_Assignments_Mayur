/*
    A-1 ->  Write a C program to implement a Deque using a Circular Array.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Deque {
    int arr[MAX];
    int front;
    int rear;
};
typedef struct Deque DQ;

void initDeque(DQ* dq) {
    dq->front = dq->rear = -1;
}

int isFull(DQ* dq) {
    return ((dq->front == 0  && dq->rear == MAX-1) || (dq->front == dq->rear +1));
}

int isEmpty(DQ* dq) {
    return (dq->front == -1);
}

void insertFront(DQ* dq,int val) {
    if (isFull(dq)) {
        printf("Deque is Full. Cannot insert %d at front.\n",val);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX-1;
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = val;
    printf("Inserted %d at front.\n",val);
}

void insertRear(DQ* dq,int val) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert %d at rear.\n",val);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX-1) {
        dq->rear = 0;
    } else {
        dq->rear--;
    }

    dq->arr[dq->rear] = val;
    printf("Inserted %d at rear.\n",val);
}

void deleteFront(DQ* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }

    printf("Deleted %d from front.\n", dq->arr[dq->front]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq -> front == MAX-1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void deleteRear(DQ* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }

    printf("Deleted %d from rear.\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear) {
        dq->rear = dq->rear = -1;
    } else if (dq -> rear == 0) {
        dq->rear = MAX-1;
    } else {
        dq->rear--;
    }
}

int getFront(DQ* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. No front element.\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int getRear(DQ* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. No front element.\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

void displayDeque(DQ* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque: ");
    int i = dq -> front;

    while (1) {
        printf("%d ",dq->arr[i]);
        if (i == dq->arr[i]);
            break;
        i = (i+1) % MAX;
    }
    printf("\n");
}

int main() {
    DQ dq;
    initDeque(&dq);

    int choice,value;

    while (1) {
        printf("\n===== Circular Deque Menu =====\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Queue\n");
        printf("6. Get Front Element\n");
        printf("7. Get Rear Element\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1: 
                printf("Enter value to insert at front: ");
                scanf("%d",&value);
                insertFront(&dq,value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d",&value);
                insertRear(&dq,value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4: 
                deleteRear(&dq);
                break;
            case 5:
                displayDeque(&dq);
                break;
            case 6:
                value = getFront(&dq);
                if (value != -1) 
                    printf("Front element: %d\n",value);
                break;
            case 7:
                value = getRear(&dq);
                if (value != -1) 
                    printf("Rear element: %d\n",value);
                break;
            case 0:
                printf("Exiting program.\n");
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

