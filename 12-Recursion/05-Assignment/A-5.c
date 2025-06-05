/*
    A-5 ->  accept an array and display the array in reverse order using recursion 
*/

#include<stdio.h>

#define SIZE 8

void reverse_array(int[],int);

int main() {
    printf("\n\t ***** Displaying the given array in reverse order using Recursion ***** \n");

    int arr[SIZE];
    printf("\n\t Enter the array element one by one of arr[%d] : \n",SIZE);

    for (int i = 0 ; i < SIZE ; i++) {
        printf("\n\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    printf("\n\t The given arr[%d] : \n",SIZE);
    printf("\n\t |_%d_|",arr[0]);
    for (int i = 1 ; i < SIZE ; i++) {
        printf("_%d_|",arr[i]);
    }

    printf("\n\n\t The given arr[%d] after reversing : \n",SIZE);
    reverse_array(arr,SIZE);
    printf("\n\n");
    
    return 0;   
}

void reverse_array(int arr[],int n) {
    if (n == 0) return;
    
    if (n == SIZE)  printf("\n\t |_%d_|",arr[n-1]);
    else  printf("_%d_|",arr[n-1]);

    reverse_array(arr,--n);
}


