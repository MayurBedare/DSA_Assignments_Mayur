/*
    A-3 ->  Accept a  number 'N' and calculate the sum  of digits in the number using recursion 
*/

#include<stdio.h>

int digit_sum(int);

int main() {
    printf("\n\t ***** Calculating Sum of digits in the given Number ***** \n");

    int n;
    printf("\n\t Enter the number to find the sum of digits : ");
    scanf("%d",&n);

    n = digit_sum(n);

    printf("\n\t The sum of digits of the given number : %d \n\n",n);
    return 0;   
}

int digit_sum(int n) {
    if (n == 0) return 0;
    else {
        return n%10 + digit_sum(n/10);
    }
}