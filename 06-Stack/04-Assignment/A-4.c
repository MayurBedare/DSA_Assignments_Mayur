/*
    A-4 -> Write the code to covert the below expression from Infix to Postfix 
*/

/* 
    Input ->  F*(A+B)/E-D*(G+H/K)                     
*/

#include<stdio.h>
#include<string.h>

int precedence(char,char);
int priority(char);
char* operandPostfixStack(char[][30],int*,char);

int main() {
    int stk = -1;
    int postfix = -1;
    char arr[30];
    char stkOperator[10];
    char stkPostfixOperand[10][30];

    printf("\n\t ***** Infix -> Postfix *****");
    printf("\n\t Enter the Infix Equation : ");
    scanf("%s",arr);

    for (int i = 0 ; i < strlen(arr) ; i++) {

        if (arr[i] == '+' || arr[i] == '-' || arr[i] == '/' || arr[i] == '*' || arr[i] == '^'  || arr[i] == '(' || arr[i] == ')') {
            
            if(arr[i] == '(') {
                stk++;
                stkOperator[stk] = arr[i];
            }
            if (arr[i] == ')') {
                while (stkOperator[stk] != '(') {
                    strcpy(stkPostfixOperand[postfix],operandPostfixStack(stkPostfixOperand,&postfix,stkOperator[stk]));
                    stk--;
                }
                stk--;
            }
            if (arr[i] == '+' || arr[i] == '-' || arr[i] == '/' || arr[i] == '*' || arr[i] == '^') {
                if (stkOperator[stk] == '+' || stkOperator[stk] == '-' || stkOperator[stk] == '*' || stkOperator[stk] == '/' || stkOperator[stk] == '^') {
                    if (precedence(arr[i],stkOperator[stk])) {
                        strcpy(stkPostfixOperand[postfix],operandPostfixStack(stkPostfixOperand,&postfix,stkOperator[stk]));
                        stkOperator[stk] = arr[i];
                    } else {
                        stk++;
                        stkOperator[stk] = arr[i];
                    }
                } else {
                    stk++;
                    stkOperator[stk] = arr[i];
                }
            }
        } else {
            strcpy(stkPostfixOperand[postfix],operandPostfixStack(stkPostfixOperand,&postfix,arr[i]));
        }
    }
    while (stk != -1) {
        if (stkOperator[stk] != '(' && stk >= 0) {
            strcpy(stkPostfixOperand[postfix],operandPostfixStack(stkPostfixOperand,&postfix,stkOperator[stk]));
            stk--;
        }
    }
    
    printf("\n\t The Postfix Expression of the given Infix Expression : %s\n\n",stkPostfixOperand[postfix]);

    return 0;
}

int precedence(char i,char j) {
    int p1,p2;
    p1 = priority(i);
    p2 = priority(j);
    if (p1 <= p2)
        return 1;
    else return 0;
}

int priority(char ch) {
    int p;
    if (ch == '+' || ch == '-') p = 1;
    if (ch == '*' || ch == '/' || ch == '%') p = 2;
    if (ch == '^')  p = 3;  
    return p;
}

char* operandPostfixStack(char stkPostfixOperand[][30],int *postfix,char i) {
    char temp[2] = {i,'\0'};
    char string[30];
    if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^' || i == '%') {
        (*postfix)--;
        strcpy(string,stkPostfixOperand[(*postfix)]);
        (*postfix)++;
        strcat(string,stkPostfixOperand[(*postfix)]);
        strcat(string,temp);
        (*postfix)--;
        strcpy(stkPostfixOperand[(*postfix)],string);
    } else {
        (*postfix)++;
        strcpy(stkPostfixOperand[(*postfix)],temp);
    }
    return stkPostfixOperand[(*postfix)];
}

/*
    Output ->    
                ***** Infix -> Postfix *****
                Enter the Infix Equation : F*(A+B)/E-D*(G+H/K)

                The Postfix Expression of the given Infix Expression : FAB+*E/DGHK/+*-                    
*/