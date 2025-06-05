/*
    A-4 ->  Write a C program to Calculate Power of a Number using recursion
*/

#include<stdio.h>

int power(int,int);

int main() {
    printf("\n\t ***** Calculating power of the given Number ***** \n");

    int base,expn;
    printf("\n\t Enter the base and exponent to find the power : ");
    scanf("%d %d",&base,&expn);

    base = power(base,expn);

    printf("\n\t The power of the given number : %d \n\n",base);
    return 0;   
}

int power(int base,int expn) {
    if (expn == 0) return 1;
    else    return base*power(base,--expn);
}

