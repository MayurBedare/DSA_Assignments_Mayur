/*
    A-1 ->  write a c program to create a stack and perform push and pop operation (Using Array)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX],top = -1;

void push();
void pop();
void peek();
int isEmpty();
int isFull();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n\t *********************");
        printf("\n\t Stack using Array");
        printf("\n\t *********************");
        printf("\n\t 1. PUSH");
        printf("\n\t 2. POP");
        printf("\n\t 3. PEEK");
        printf("\n\t 4. IS EMPTY?");
        printf("\n\t 5. IS FULL?");
        printf("\n\t 6. DISPLAY");
        printf("\n\t 7. EXIT");
        printf("\n\t Enter the choice : ");
        scanf("%d",&choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop();  break;
            case 3: peek(); break;
            case 4: printf(isEmpty() ? "\n\t Stack is empty" : "\n\t Stack is not empty");  break;
            case 5: printf(isFull() ? "\n\t Stack if full" : "\n\t Stack is not full"); break;
            case 6: display();  break;
            case 7: exit(0);
            default: printf("\n\t Invalid choice! Please try again."); 
        }
    }
    return 0;
}

void push() {
    if (isFull()) {
        printf("\n\t Stack Overflow! Cannot push.");
        return;
    }
    int value;
    printf("\n\t Enter the element to push: ");
    scanf("%d",&value);
    stack[++top] = value;
    printf("\n\t %d pushed to stack", value);
}

void pop() {
    if (isEmpty()) {
        printf("\n\t Stack Underflow! No elements to pop.");
        return;
    }
    printf("\n\t %d popped from stack",stack[top--]);
}

void peek() {
    if (isEmpty()) {
        printf("\n\t Stack is empty! No top element.");
        return;
    }
    printf("\n\t Top element is: %d",stack[top]);
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void display() {
    if (isEmpty()) {
        printf("\n\t Stack is empty");
        return;
    }
    printf("\n\t Stack elements:");
    for (int i = top ; i >= 0 ; i--) {
        printf("\n\t %d",stack[i]);
    }
}