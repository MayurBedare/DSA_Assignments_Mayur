/*
    A-10 -> accept number and check whether the number is a palidrome or not  using recursion  
*/

#include<stdio.h>
#include<string.h>

int palindrome_or_not(char[],int,int,int);

int main() {
    printf("\n\t ***** Checking Palindrome or not using Recursion ***** \n");

    char string[30],mid;
    printf("\n\t Enter the number to check palindrome : ");
    scanf("%s",string);

    mid = palindrome_or_not(string,0,strlen(string)-1,strlen(string)/2);

    if (mid != 0) printf("\n\t The given number is palindrome \n\n"); 
    else    printf("\n\t The given number is not a palindrome \n\n");

    return 0;   
}

int palindrome_or_not(char string[],int first,int n,int m) {
    if (string[first] == string[n]) { 
        if (n == m) return 1;
        palindrome_or_not(string,++first,--n,m); 
    } else  return 0; 
}

