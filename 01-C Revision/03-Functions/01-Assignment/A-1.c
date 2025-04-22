/*
    A-1 ->  Write a function to calculate the sum of all elements of an array
*/

/* 
    Input ->    arr[5] = {1,2,3,4,5}                   
*/

#include<stdio.h>

int calculateSum(int arr[],int);

int main() {
    int arr[5];
    int sum, len = sizeof(arr)/sizeof(int);
    printf("\n\t Enter the elements of an array : \n");
    for (int i = 0 ; i < len ; i++) {
        printf("\n\t arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    sum = calculateSum(arr,len);

    printf("\n\t The sum of all elements of array : %d \n\n",sum);

    return 0;
    
}

int calculateSum(int arr[],int size) {
    int sum = 0;
    for (int i = 0 ; i < size ; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

/*
    Output -> 
                Enter the elements of an array : 

                arr[0] : 1

                arr[1] : 2

                arr[2] : 3

                arr[3] : 4

                arr[4] : 5

                The sum of all elements of array : 15                               
*/