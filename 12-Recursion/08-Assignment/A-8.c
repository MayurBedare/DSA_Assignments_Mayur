/*
    A-8 ->  Accept number 'N' and calculate factorial of 'N' using recursion 
*/

#include<stdio.h>

int factorial(int);

int main() {
    printf("\n\t ***** Factorial of N using Recursion ***** \n");

    int n;
    printf("\n\t Enter the value of N : ");
    scanf("%d",&n);

    n = factorial(n);

    printf("\n\t The factorial of the given number : %d \n\n",n);

    return 0;   
}

int factorial(int n) {
    if (n == 1) return 1;
    else    return n*factorial(n-1);
}

