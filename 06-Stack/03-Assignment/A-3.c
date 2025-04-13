/*
    A-1 ->  Use Stacks to check a program for balanced symbols (such as {}, (), []). 
            The closing symbol should be matched with the most recently seen opening symbol.
            Example: {()} is legal, {() ({})} is legal, but {((} and {(}) are not legal
*/

/*
    Input -> expression : {(a+b)(c+d{m-n})}
*/

#include<stdio.h>
#include<string.h>

int main() {
    char arr[30];
    char stk[10];
    int top = -1;
    printf("\n\t Note : Don't add the ' ' and numbers in between expression!\n");
    printf("\n\t Enter the expression to check the balanced parenthesis : ");
    scanf("%s",arr);

    for (int i = 0; i < strlen(arr) ; i++) {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[') {
            top++;
            stk[top] = arr[i];
        }
        if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']') {
            top--;
        }
    }
    if (top == -1)  printf("\n\t The given expression is balanced with bracket paranthesis \n\n");
    else    printf("\n\t The given expression is not balanced with bracket paranthesis \n\n");
    return 0;
}

/*
    Output -> 
                Note : Don't add the ' ' and numbers in between expression!

                Enter the expression to check the balanced parenthesis : {(a+b)(c+d{m-n})}

                The given expression is balanced with bracket paranthesis
*/