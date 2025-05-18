/*
    A-2 ->  write a c program to Create a queue and perform enqueue and dequeue operations(using Linked List) 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 4

typedef struct queue
{
    int no;
    char name[20];
    struct queue *next;
} que;

que* enqueue(que**, que*,int*);
que* dequeue(que*);
int isEmpty(que*,que*);
int isFull(int*);
void display(que*,que*);

void main() {
    int i = -1;
    que *front = NULL,*rear = NULL;
    que arr[MAX];

    while (1) {
        int ch;
        printf("\n\t ***********************");
        printf("\n\t Queue using Linked List");
        printf("\n\t ***********************");
        printf("\n\t 1. Enqueue");
        printf("\n\t 2. Dequeue");
        printf("\n\t 3. Exit");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);

        switch (ch) {
            case 1:
                if (!isFull(&i)) {
                    break;
                }
                rear = enqueue(&front,rear, &i);
                display(front, rear);
                break;
        
            case 2:
                if (rear -> next == front && i <= (MAX-1)) {
                    printf("\n\t These operation not allowed!");
                    break;
                }
                if (!isEmpty(front, rear)) { 
                    break;
                }
                front = dequeue(front);
                display(front, rear);      
                break;

            case 3:
                exit(0);
            
            default:
                printf("\n\t Invalid Choice Entered!");
                break;
        }
    }
}

que* enqueue(que **front,que *rear, int *i) {
    que *nw = NULL;
    nw = malloc(sizeof(que));
    printf("Enter the number and name to be enqueued : ");
    scanf("%d", &(nw -> no));
    getchar();//Clear the buffer using fgets 
    fgets(nw -> name, sizeof(nw -> name), stdin);
    nw -> name[strcspn(nw -> name, "\n")] = '\0';//Remove newline character
    nw -> next = NULL;

    if (rear == NULL && (*front) == NULL) {
        (*front) = nw;
    } else {
        (rear) -> next = nw;
    }
    (rear) = nw;
    (*i)++;

    return (rear);    
}

que* dequeue(que *front) {
    front = front -> next;

    return (front);
}

int isEmpty(que *front, que *rear) {
    if ((front == NULL) && (rear == NULL)) {
        printf("\n\t Queue is Empty!\n");
        return 0;
    } else if (rear -> next == front) {
        printf("\n\t Queue is Empty technically!\n");
        return 0;
    }
    return 1;
}

int isFull(int *i) {
    if ((*i) == (MAX-1)) {
        printf("\n\t Queue is Full!\n");
        return 0;
    }  
    return 1;
} 

void display(que *front,que *rear) {
    if (front == rear) {
        printf("\n\t |_%d_|_%s_| <- Front <- Rear", front -> no, front -> name);
    } else {
        for (que *i = front ; i != rear -> next ; i = i -> next) {
            if (front == i) {
                printf("\n\t |_%d_|_%s_| -> Front", front -> no, front -> name);
            } else if (rear == i) {
                printf("\n\t |_%d_|_%s_| -> Rear", rear -> no, rear -> name);
            } else {
                printf("\n\t |_%d_|_%s_|", i -> no, i -> name);
            }
        }
    }
    printf("\n");
}