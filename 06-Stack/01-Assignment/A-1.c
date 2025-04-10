/*
    A-1 ->  write a c program to create a stack and perform push and pop operation (Using Array). 
*/

#include<stdio.h>

#define MAX 4

int push(int,int[]);
int pop(int);
int isEmpty(int);
int isFull(int);
void print(int,int[]);

int main() {
    int arr[MAX];
    int top = -1;
   while (1) {
        int choice;
        printf("\n\t *****************");
        printf("\n\t Stack using array");
        printf("\n\t *****************");
        printf("\n\t 1. Push");
        printf("\n\t 2. Pop");
        printf("\n\t 3. Exit");
        printf("\n\n\t Enter your choice : ");
        scanf("%d",&choice);

        switch (choice) {
        case 1:
            if(!(isFull(top))) {
                break;
            }
            top = push(top,arr);
            print(top,arr);
            break;
        
        case 2:
            if(!(isEmpty(top))) {
                break;
            }
            top = pop(top);
            print(top,arr);
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

int push(int top, int arr[]) {
    top++;
    printf("\n\t Enter the number to be entered on the stack : ");
    scanf("%d",&arr[top]);
    return top;
}

int pop(int top) {
    top--;
    return top;
}

int isEmpty(int top) {
    if(top == -1) {
        printf("\n\t Stack is empty!\n");
        return 0;
    }
    return 1;
}

int isFull(int top) {
    if(top == (MAX - 1)) {
        printf("\n\t Stack is full!\n");
        return 0;
    }
    return 1;
}

void print(int top,int arr[]) {
    if (!(isEmpty(top))) {
        return;
    }
    int x = top;
    while (top != -1) {
        if(x == top) {
            printf("\n\t |_%d_| <- top",arr[top]);
        }
        else {
            printf("\n\t |_%d_| ",arr[top]);
        }
        top--;
    } 
    printf("\n\t -----\n");
}

