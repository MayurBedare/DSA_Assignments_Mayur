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

que* enqueue(que**,que*,int*,int *);
que* dequeue(que*,int*,int*);
int isEmpty(que*,que*);
int isFull(que*,que*,int);
void display(que*,que*,que*,int);

void main() {
    que *front = NULL,*rear = NULL,*head = NULL;
    int i = -1,j = 0;

    printf("\n\t ***** Circular Queue using array *****\n");
    while (1) {
        int ch;
        printf("\n\t --------------------");
        printf("\n\t 1.Enqueue");
        printf("\n\t 2.Dequeue");
        printf("\n\t 3.Exit");
        printf("\n\t --------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t --------------------\n");

        switch (ch) {
            case 1:
                if (!isFull(front, rear,i)) {
                    break;
                }
                rear = enqueue(&front, rear, &i, &j);
                if (rear -> next == rear)    head = rear;
                display(front, rear, head,j);
                break;
        
            case 2:
                if (!isEmpty(front, rear)) { 
                    break;
                }
                front = dequeue(front, &i,&j);
                display(front, rear,head,j);      
                break;

            case 3:
                exit(0);
            
            default:
                printf("\n\t Invalid Choice Entered!");
                break;
        }
    }
}

que* enqueue(que **front,que *rear,int *i,int *j) {
    que *nw = NULL;
    nw = malloc(sizeof(que));

    if (*j != MAX) {
        printf("\n\t Enter the number and name to be enqueued : ");
        scanf("%d %s",&(nw -> no),nw -> name);
        nw -> next = nw;
        (*j)++;

        if (rear == NULL && (*front) == NULL) {
            (*front) = nw;
        } else {
            nw -> next = rear -> next;
            rear -> next = nw;
        }
        rear = nw;
        (*i)++;
    } else {
        if (*i == MAX-2) {
            rear = rear -> next;
        }
        printf("\n\t Enter the number and name to be enqueued : ");
        scanf("%d %s",&(rear -> no),rear -> name);
        (*i)++;
        (*j)++;
    }

    return rear;    
}

que* dequeue(que *front, int *i,int *j) {

    front -> no = 0;
    strcpy(front -> name,"--");
    front = front -> next;
    (*i)--;
    (*j)--;

    return front;
}

int isEmpty(que *front,que *rear) {
    if ((front == NULL) && (rear == NULL)) {
        printf("\n\t Queue is Empty!");
        return 0;
    } else {
        return 1;
    }
}

int isFull(que *front,que *rear, int i) {
    if (i == MAX-1) {
        printf("\n\t Queue is Full!");
        return 0;
    } else {
        return 1;
    }
} 

void display(que *front,que *rear,que *head,int j) {
    que *p = NULL;
    int i = 0;
    if (front == rear) {
        for (p = head ; i != MAX ; i++,head = head -> next) {
            if (j == (MAX)) {
                if (front == p) 
                    printf("\n\t |_%d_|_%s_| <- Front <- Rear", p -> no, p -> name);
                else 
                    printf("\n\t |_%d_|_%s_| <- Front <- Rear", p -> no = 0, strcpy(p -> name,"--"));
            } else { 
                if (front == p && p != p -> next) {
                    printf("\n\t |_%d_|_%s_| <- Front <- Rear", p -> no, p -> name);
                } else if (i == 0) {
                    printf("\n\t |_%d_|_%s_| <- Front <- Rear", p -> no, p -> name);
                } else {
                    printf("\n\t |_%d_|_%s_|", 0, "--");
                }
            }
        }
    } else {
        int m = 1,n = 1;
        for (p = head ; i != MAX ; i++, p = p -> next) {
            if (j == (MAX)) {
                if (front == p) {
                    printf("\n\t |_%d_|_%s_| -> Front", p -> no, p -> name);
                } else if (rear == p) {
                    printf("\n\t |_%d_|_%s_| -> Rear", p -> no, p -> name);
                } else {
                    printf("\n\t |_%d_|_%s_|", p -> no, p -> name);
                }
            } else {
                if (front == p && m != 0) {
                    m = 0;
                    printf("\n\t |_%d_|_%s_| -> Front", p -> no, p -> name);
                } else if (rear == p && n != 0) {
                    n = 0;
                    printf("\n\t |_%d_|_%s_| -> Rear", p -> no, p -> name);
                } else if (front -> next == rear) {
                        printf("\n\t |_%d_|_%s_|", 0,"--");
                } else if (front -> next -> next == rear) {
                    if (rear -> next -> next == front)
                        printf("\n\t |_%d_|_%s_|", p -> no, p -> name);
                    else
                        printf("\n\t |_%d_|_%s_|", 0,"--");
                }
            } 
        }
    }
    printf("\n");
}