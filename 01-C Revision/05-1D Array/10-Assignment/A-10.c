/*
    A-10 -> - Write a C program which accepts an array dynamically
            - Find the subarray with maximum sum 
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main() {
    int positive = 0,sum = 0,largest,largest_negative = 0;
    int *arr = NULL;
    arr = (int*)malloc(SIZE*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Falied! \n\n");
        exit(1);
    }

    printf("\n\t ***** Finding subarray with maximum sum of given array ***** \n");

    printf("\n\t Enter the elements of arr[%d] one by one : \n",SIZE);
    for (int i = 0 ; i < SIZE ; i++) {
        printf("\n\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
         
        if (i == 0) largest = arr[i];
        else if (arr[i] > largest)   largest = arr[i];

        if (arr[i] > 0) {
            positive = 1;
            sum = sum + arr[i];
        } else {
            if(largest_negative == 0)   largest_negative = arr[i];
            else if (arr[i] > largest_negative) largest_negative = arr[i];
        }
    }

    if (positive) {
        printf("\n\t The subarray with maximum sum of given arr[%d] : %d \n\n",SIZE,sum);
    } else {
        printf("\n\t The subarray with maximum sum of given arr[%d] : %d \n\n",SIZE,largest_negative);
    }

    free(arr);
    arr = NULL;

    return 0;   
}

