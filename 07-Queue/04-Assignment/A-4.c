/*
    A-4 ->  write a c program to create a circular queue and perform enqueue and dequeue operations (with Linked List) 
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

que* enqueue(que**,que*,que**,int*);
que* dequeue(que*,int*);
int isEmpty(que*,que*);
int isFull(que*,que*,int);
void display(que*,que*,que*);

void main() {
    que *front = NULL,*rear = NULL,*temp = NULL;
    int i = -1;

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
                // if (!isFull(front, rear,i)) {
                //     break;
                // }
                rear = enqueue(&front, rear, &temp, &i);
                display(front, rear, temp);
                break;
        
            case 2:
                if (!isEmpty(front, rear)) { 
                    break;
                }
                front = dequeue(front, &i);
                display(front, rear, temp);      
                break;

            case 3:
                exit(0);
            
            default:
                printf("\n\t Invalid Choice Entered!");
                break;
        }
    }
}

que* enqueue(que **front,que *rear,que **temp,int *i) {
    if (*i == (MAX - 1))
        rear -> next = (*temp);

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

    return rear;    
}

que* dequeue(que *front, int *i) {

    front -> no = 0;
    strcpy(front -> name,"--");
    front = front -> next;
    (*i)--;

    return front;
}

int isEmpty(que *front,que *rear) {
    if ((front == NULL) && (rear == NULL)) {
        printf("\n\t Queue is Empty!");
        return 0;
    } else if ((rear -> next == front) && (rear -> no == 0)) {
        printf("\n\t Queue is Empty!");
        return 0;
    } else {
        return 1;
    }
}

int isFull(que *front,que *rear, int i) {
    if (i == MAX) {
        printf("\n\t Queue is Full!");
        return 0;
    } else if ((rear -> next == front) && (rear -> no != 0)) {
        printf("\n\t Queue is Full!");
        return 0;
    } else {
        return 1;
    }
} 

void display(que *front,que *rear,que *temp) {
    que *p;
    int i = 0;
    if (front == rear) {
        for (p = temp ; i != MAX ; i++, p = p -> next) {
            if (front == p)
                printf("\n\t |_%d_|_%s_| <- Front <- Rear", p -> no, p -> name);
            else 
                printf("\n\t |_%d_|_%s_|", p -> no = 0, strcpy(p -> name,"--"));
        }
    } else {
        for (p = temp ; i != MAX ; i++, p = p -> next) {
            if (front == p) {
                printf("\n\t |_%d_|_%s_| -> Front", p -> no, p -> name);
            } else if (rear == p) {
                printf("\n\t |_%d_|_%s_| -> Rear", p -> no, p -> name);
            } else {
                printf("\n\t |_%d_|_%s_|", p -> no, p -> name);
            }
        }
    }
    printf("\n");
}