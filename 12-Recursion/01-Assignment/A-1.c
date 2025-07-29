/*
    A-1 ->  Accept N numbers and calculate sum of all numbers using recursion
*/

#include<stdio.h>
#include<stdlib.h>

int sum(int[],int);

int main() {
    printf("\n\t ***** Sum of N numbers using Recursion ***** \n");
    
    int n,s;

    printf("\n\t Total numbers to be entered : ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    if (!arr) {
        printf("\n\t Memory Allocation Failed! ");
        exit(1);
    }

    printf("\n\t Enter the numbers one by one -> \n\t");
    for (int i = 0 ; i < n ; i++) {
        scanf("%d",&arr[i]);
    }

    s = sum(arr,n-1);

    printf("\n\t The sum of %d natural no.s : %d \n\n",n,s);

    return 0;   
}

int sum (int arr[],int n) {
    if (n == -1) return 0;
    else    return arr[n] + sum(arr,n-1);
}



