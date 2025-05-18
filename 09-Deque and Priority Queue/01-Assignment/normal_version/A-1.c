/*
    A-1 ->  Write a C program to implement a Deque using a Circular Array.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5

typedef struct deque {
   int arr[MAX];
   int front;
   int rear; 
} dq;


void insertFront(dq*);
void insertRear(dq*);
void deleteFront(dq*);
void deleteRear(dq*);
int isEmpty(dq*);
int isFull(dq*);
void display(dq*);

int main() {
    dq base = {{0},-1,-1};

    printf("\n\t ***** Deque - Using Circular Array ***** \n");
    while (1) {
        int ch;
        printf("\n\t -------------------");
        printf("\n\t 1. Insert Front ");
        printf("\n\t 2. Insert Rear ");
        printf("\n\t 3. Delete Front ");
        printf("\n\t 4. Delete Rear ");
        printf("\n\t 5. Display Deque ");
        printf("\n\t 6. Exit ");
        printf("\n\t -------------------");
        printf("\n\t Enter you choice : ");
        scanf("%d",&ch);
        printf("\n\t -------------------\n");

        switch (ch) {
            case 1:
                if (!isFull(&base)) {
                    break;
                }
                insertFront(&base);
                break;
            
            case 2:
                if (!isFull(&base)) {
                    break;
                }
                insertRear(&base);
                break;

            case 3:
                if (!isEmpty(&base)) {
                    break;
                }
                deleteFront(&base);
                break;
            
            case 4:
                if (!isEmpty(&base)) {
                    break;
                }
                deleteRear(&base);
                break;
            
            case 5:
                if (!isEmpty(&base)) {
                    break;
                }
                display(&base);
                break;

            case 6:
                printf("\n\t Exiting the program successfully. \n\n");
                exit(0);

            default:
                printf("\n\t Invalid choice Entered! \n");
        }
    }

    return 0;   
}

void insertFront(dq *base) {
    if (base -> front == (MAX-1)) {
        base -> front = 0;
    }

    if (base -> front + 1 == base -> rear) {
        if (base -> front == 0) {
            base -> front = (MAX-1);
        } else {
            base -> front--;
        }
    } else {
        base -> front++;
    }

    printf("\n\t Enter the number to be inserted : ");
    scanf("%d",&(base -> arr[base -> front]));
}

void insertRear(dq *base) {
    if (base -> rear + 1 == base -> front) {
        if (base -> rear == 0) {
            base -> rear = (MAX-1);
        } else {
            base -> rear--;
        }
    } else {
        base -> rear++;
    }

    printf("\n\t Enter the number to be inserted : ");
    scanf("%d",&(base -> arr[base -> rear]));

}

void deleteFront(dq *base) {
    if (base -> front == base -> rear) {
        base -> front = -1,base -> rear = -1;

        return ;
    }

    printf("\n\t %d Deleted!\n",base -> arr[base -> front]);
    base -> arr[base -> front] = 0;
    base -> front++;

    if (base -> front == (MAX)) {
        base -> front = 0;
    }

}

void deleteRear(dq *base) {
    if (base -> front == base -> rear || base -> arr[base -> front] == 0 && base -> arr[base -> rear] == 0) {
        base -> front = -1,base -> rear = -1;

        return ;
    }

    base -> rear++;

    if (base -> rear == (MAX)) {
        base -> rear = 0;
    }

}

int isEmpty(dq *base) {
    if (base -> front == -1 && base -> rear == -1) {
        printf("\n\t The Deque is Empty! \n");
        return 0;
    } else if (base -> arr[base -> front] == 0 || base -> arr[base -> rear] == 0) {
        printf("\n\t The Deque is Empty! \n");
        return 0;
    }

    return 1;
}

int isFull(dq *base) {
    if ((base -> front == 0 && base -> rear == (MAX-1)) || (base -> rear == 0 && base -> front == (MAX-1)) || 
         (base -> front == (MAX-1) && base -> rear == -1 && base -> arr[base -> front]!= 0) || (base -> rear == (MAX-1) && base -> front == -1 && base -> arr[base -> rear]!= 0)) {
        printf("\n\t The Deque is Full! \n");
        return 0;
    } else if ((base -> front + 1 == base -> rear && base -> rear != 0) || (base -> rear + 1 == base -> front && base -> front != 0)) {
        printf("\n\t The Deque is Full! \n");
        return 0;
    }

    return 1;
}

void display(dq *base) {
    
    printf("\n\t Deque with front and rear : \n");
    if (base -> front == base -> rear) {
        printf("\n\t |_%d_| <- front <- rear \n");
        return ;
    }

    for (int i = 0 ; i < MAX ; i++) {
        if (base -> front == i) {
            printf("\n\t |_%d_| <- front ",base -> arr[base -> front]);
        } else if (base -> rear == i) {
            printf("\n\t |_%d_| <- rear ",base -> arr[i]);
        } else {
            printf("\n\t |_%d_| ",base -> arr[i]);
        }
    }
    printf("\n");
}

/*
    Output ->                                
*/