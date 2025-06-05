/*
    A-7 ->  write C program to check a given number is prime or not using recursion. 
*/

#include<stdio.h>

int prime_or_not(int,int);

int main() {
    printf("\n\t ***** Checking a given number is Prime or not using Recursion ***** \n");

    int n;
    printf("\n\t Enter the number : ");
    scanf("%d",&n);

    n = prime_or_not(n,2);
    
    if (n != 0)  printf("\n\t The given number is Prime Number \n\n");
    else    printf("\n\t The given number is not a Prime Number \n\n");    

    return 0;   
}

int prime_or_not(int n,int m) {
    if (n == 1) return 0;
    
    if (n%m == 0 && m != n) { return 0; }
    else if (m == n) { return 1; }
    else { prime_or_not(n,++m); }   
}
