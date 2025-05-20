/*
    A-2 ->  write a c program to create a stack and perform push and pop operation (Using Linked List) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    int no;
    char name[20];
    struct stack *next;
} stk;

stk* push(stk*);
stk* pop(stk*);
void disp(stk*);
void freeStack(stk*);

int main() {
    stk *top = NULL;
    int ch;

    while (1) {
        printf("\n\t **********************");
        printf("\n\t Stack with Linked List");
        printf("\n\t **********************");
        printf("\n\t 1. PUSH");
        printf("\n\t 2. POP");
        printf("\n\t 3. PRINT");
        printf("\n\t 4. EXIT");
        printf("\n\t Enter the choice: ");
        scanf("%d",&ch);

        switch (ch) {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                disp(top);
                break;
            case 4:
                freeStack(top);
                exit(0);
            default:
                printf("\n\t Invalid choice! Please try again.");
        }
    }
    return 0;
}

stk* push(stk* top) {
    stk *nw = (stk*)malloc(sizeof(stk));
    if (!nw) {
        printf("\n\t Memory Allocation Failed!");
        return top;
    }
    printf("\n\t Enter the no and name: ");
    scanf("%d %19s",&nw->no,nw->name);
    nw->next = top;
    return nw;
}

stk* pop(stk* top) {
    if (top == NULL) {
        printf("\n\t Stack is empty");
        return NULL;
    } else {
        stk *p = top->next;
        printf("\n\t %d (%s) is popped",top->no,top->name);
        free(top);
        return p;
    }
}

void disp(stk *p) {
    if (p == NULL) {
        printf("\n\t Stack is empty");
    } else {
        printf("\n\t Stack elements:");
        for (; p != NULL ; p = p->next)
            printf("\n\t No = %d, Name = %s",p->no,p->name);
    }
}

void freeStack(stk* top) {
    while (top) {
        stk* temp = top;
        top = top->next;
        free(temp);
    }
    printf("\n\t Memory freed. Exiting.");
}