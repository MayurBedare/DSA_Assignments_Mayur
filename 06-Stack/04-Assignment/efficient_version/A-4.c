/*
    A-4 ->  Write the code to covert the below expression from Infix to Postfix : F*(A+B)/E-D*(G+H/K)      
                                                                         OUTPUT : FAB+*E/DGHK/+*-
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX 50

char* postfix(char*);
int isAlpha(char);
int prior(char);
int push(char operand[][MAX],int top,char ch);

int main() {
    int ch;
    char str[MAX],*post = NULL,*pre = NULL;
    while (1) {
        printf("\n *** Infix Conversion *** ");
        printf("\n 1. Enter Infix Expression ");
        printf("\n 2. Convert to postfix ");
        printf("\n 3. Exit ");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        getchar();
        switch (ch) {
            case 1:
                printf(" Enter the infix expression : ");
                scanf("%s",str);
                break;
            
            case 2:
                post = postfix(str);
                if (post != NULL)   printf(" Postfix : %s\n",post);
                break;
            
            default:
                exit(0);
        }
    }
    return 0;
}

int isAlpha(char ch) {
    return isalnum(ch);
}

int prior(char ch) {
    switch (ch) {
        case '^': return 4;
        case '*': case '/': case '%': return 3;
        case '+': case '-': return 2;
        case '(': return 1;
        default: return 0;
    }
}

int push(char operand[][MAX],int top,char ch) {
    char t[MAX];
    t[0] = ch;
    t[1] = '\0';
    if (top > 0) {
        strcat(operand[top-1],operand[top]);
        strcat(operand[top-1],t);
        top--;
    } else {
        printf(" Invalid expression..!");
        exit(1);
    }
    return top;
}

char* postfix(char *str) {
    static char result[MAX];
    char operand[MAX][MAX],op[MAX];
    int top = -1,top1 = -1,i;
    for (i = 0 ; str[i] != '\0' ; i++) {
        if (isAlpha(str[i])) {
            top++;
            operand[top][0] = str[i];
            operand[top][1] = '\0';
        } else if (str[i] == '(') {
            op[++top1] = str[i];
        } else if (str[i] == ')') {
            while (top >= 0 && op[top1] != '(') {
                top = push(operand,top,op[top1--]);
            }
            if (top1 == -1) {
                printf(" Invalid, parentheses mismatched..!");
                return NULL;
            }
            top1--;
        } else {
            while (top1 >= 0 && prior(str[i]) <= prior(op[top1]) && op[top1] != '(') {
                top = push(operand,top,op[top1--]);
            }
            op[++top1] = str[i];
        }
    } 
    while (top1 >= 0) {
        if (op[top1] == '(') {
            printf(" Invalid, parentheses mismatched..!");
            return NULL;
        }
        top = push(operand,top,op[top1--]);
    }
    strcpy(result,operand[top]);
    return result;
}
