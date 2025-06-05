/*
    A-9 ->  write a C Program to print Fibonacci series using Recursion 
*/

#include<stdio.h>

void fibonacii(int,int,int);

int main() {
    printf("\n\t ***** Printing Fibonacci series of N number using Recurstion ***** \n");

    int n;
    printf("\n\t Enter the value of  N to print fibonacci series : ");
    scanf("%d",&n);

    printf("\n\t The fibonacci series of %d number : \n",n);
    fibonacii(0,1,n);
    printf("\n\n");
}

void fibonacii(int x,int y,int n) {
    if (n == -1) {
        return;
    } else {
        if (x == 0) {
            printf("\n\t %d",x);
        }
        else {
            printf(" %d",x);
        }
        fibonacii(y,x+y,--n);
    }
}

