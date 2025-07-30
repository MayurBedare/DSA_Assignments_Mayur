/*
    A-6 ->  Write C program to reverse an integer number using recursion
*/

#include<stdio.h>

int no = 0 ;

void reverse_number(int);

int main() {
    printf("\n\t ***** Reversing the given integer number using recursion ***** \n");

    int n;
    printf("\n\t Enter the number to reverse : ");
    scanf("%d",&n);

    printf("\n\t The given number after reversing : ");
    reverse_number(n);
    printf("%d",no);
    printf("\n\n");

    return 0;
}

void reverse_number(int x) {
    if (x == 0) return;
    int y = x / 10;
    x = x % 10; 
    if (no == 0)    no = x;
    else    no = no*10 + x;
    reverse_number(y);
}

