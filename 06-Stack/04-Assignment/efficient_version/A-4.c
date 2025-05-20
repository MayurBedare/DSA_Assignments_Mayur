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
char* prefix(char*);
int isAlpha(char);
int prior(char);
void evaluate(char*);
int push(char operand[][MAX],int top,char ch);
void reverse(char*);

int main() {
    int ch;
    char str[MAX],*post = NULL,*pre = NULL;
    while (1) {
        printf("\n *** Infix Conversion *** ");
        printf("\n 1. Enter Infix Expression ");
        printf("\n 2. Convert to postfix ");
        printf("\n 3. Convert to prefix ");
        printf("\n 4. Evaluate Postfix ");
        printf("\n 5. Exit ");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        getchar();
        switch (ch) {
            case 1:
                printf("Enter the infix expression : ");
                scanf("%s",str);
                break;
            
            case 2:
                post = postfix(str);
                if (post != NULL)   printf(" Postfix : %s\n",post);
                break;
            
            case 3:
                pre = prefix(str);
                if (pre != NULL)    printf(" Prefix : %s\n",pre);
                break;
            
            case 4:
                if (post != NULL)   evaluate(post);
                else    printf(" Please convert to postfix..!\n");
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
        case '(': case '-': return 2;
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
                top = push(operand,top,op[top--]);
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

void evaluate(char *s) {
    int stack[MAX],top = -1,i;
    for (i = 0 ; s[i] != '\0' ; i++) {
        if (isdigit(s[i])) {
            stack[++top] = s[i] - '0';
        } else if (isalpha(s[i])) {
            int val;
            printf(" Enter value for %c : ",s[i]);
            scanf("%d",&val);
            stack[++top] = val;
        } else {
            if (top < 1) {
                printf(" Invalid postfix expression!");
                return;
            }
            int b = stack[top--];
            int a = stack[top--];
            switch (s[i]) {
                case '+' : stack[++top] = a + b; break;
                case '-' : stack[++top] = a - b; break;
                case '*' : stack[++top] = a * b; break;
                case '/' : stack[++top] = a / b; break;
                case '%' : stack[++top] = a % b; break;
                case '^' : stack[++top] = (int)pow(a,b); break;
                default: printf(" Unknown operator : %c ",s[i]); return;
            }
        }
    }
    if (top == 0)   printf(" Result : %d\n",stack[top]);
    else    printf(" Invalid postfix expression..!");
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0 ; i < len/2 ; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

char* prefix(char* infix) {
    static char rev[MAX],tmp[MAX],*post;
    strcpy(tmp,infix);
    reverse(tmp);
    for (int i = 0 ; tmp[i] != '\0' ; i++) {
        if (tmp[i] == '(') tmp[i] = ')';
        else if (tmp[i] == ')') tmp[i] = '(';
    }
    post = postfix(tmp);
    if (post == NULL)   return NULL;
    strcpy(rev,post);
    reverse(rev);
    return rev;
}
