/*
    A-1 ->  Accept  N  numbers and calculate sum of all numbers using recursion
*/

#include<stdio.h>

int sum(int);

int main() {
    printf("\n\t ***** Sum of N numbers using Recursion ***** \n");
    
    int n,s;

    printf("\n\t Enter the value of N to find sum of N natural no.s : ");
    scanf("%d",&n);

    s = sum(n);

    printf("\n\t The sum of %d natural no.s : %d \n\n",n,s);

    return 0;   
}

int sum (int n) {
    if (n == 0) return 0;
    else    return n + sum(n - 1);
}



