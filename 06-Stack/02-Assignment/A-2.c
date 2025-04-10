/*
    A-2 ->  write a c program to create a stack and perform push and pop operation (Using Linked List) 
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 4

typedef struct stack {
    int no;
    struct stack *next;
    struct stack *prev;
} stk;

stk* push(stk*,int*);
stk* pop(stk*,int*);
int isEmpty(int);
int isFull(int);
void print(stk*,int);

int main() {
    int i = -1;
    stk *top = NULL;
    printf("\n\t ***** Menu Driven Program - Stack using Linked List *****\n");
    while (1) {
        int choice;
        printf("\n\t 1. Push");
        printf("\n\t 2. Pop");
        printf("\n\t 3. Exit");
        printf("\n\n\t Enter your choice : ");
        scanf("%d",&choice);

        switch (choice) {
        case 1:
            if(!(isFull(i))) {
                break;
            }
            top = push(top,&i);
            print(top,i);
            break;
        
        case 2:
            if(!(isEmpty(i))) {
                break;
            }
            top = pop(top,&i);
            print(top,i);
            break;
        
        case 3:
            return 0;

        default:
            printf("\n\t Invalid choice entered! Please try again ");
            break;
        }
    }
    return 0;
}

stk* push(stk *top, int *i) {
    stk *nw = NULL;
    nw = malloc(sizeof(stk));
    nw -> next = NULL;
    nw -> prev = NULL;
    printf("\n\t Enter the number to be entered on the stack : ");
    scanf("%d",&(nw -> no));

    if (top != NULL) {
        top -> next = nw;
        nw -> prev = top;
    }
    top = nw;
    (*i)++;
    return top;
}

stk* pop(stk *top, int *i) {
    if (top -> next == NULL && top -> prev == NULL) {
        free(top);
        top = NULL;
    } else {
        top = top -> prev;
        free(top -> next);
        top -> next = NULL;
    }
    (*i)--;
    return top;
}

int isEmpty(int i) {
    if (i == -1) {
        printf("\n\t Stack is empty!\n");
        return 0;
    }
    return 1;
}

int isFull(int i) {
    if (i >= (MAX-1)) {
        printf("\n\t Stack is full!\n");
        return 0;
    }
    return 1;
}

void print(stk *top,int i) {
    if (!(isEmpty(i))) {
        return;
    }
    stk *t = NULL;
    t = top;
    for (t = top ; t != NULL  ; t = t -> prev) {
        if (t == top) {
            printf("\n\t |_%d_| <- top",t -> no);
        } else {
            printf("\n\t |_%d_|",t -> no);
        }
    }
    printf("\n\t -----\n");
}
