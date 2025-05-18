/*
    A-2 ->  Write a C program to implement Binary Search.  
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

int binarySearch(int[],int,int,int);

int main() {
    printf("\n\t ***** Binary Search : Searching ***** \n");

    printf("\n\t ----------------------------------------------------------------");
    printf("\n\t The Time Complexity of the Binary Search [worst cases]: O(log n) \n");
    printf("\t ------------------------------------------------------------------ \n");

    int *arr = NULL,flag = 0,key;
    arr = (int*)malloc(SIZE*sizeof(int));    
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter the elements of arr[%d] one by one : \n\n",SIZE);

    for (int i = 0 ; i < SIZE ; i++) {
        printf("\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    
    printf("\n\t Enter the array element to be searched : ");
    scanf("%d",&key);

    flag = binarySearch(arr,flag,SIZE,key);

    if (flag == 1)    printf("\n\t The array %d element is found \n\n",key);     
    else    printf("\n\t The array element %d is not found! \n\n",key);  

    return 0;   
}

int binarySearch(int arr[],int flag,int n, int key) {
    int low = 0,high = n-1,mid;

    while (low <= high) {
        mid = (high + low)/2;

        if (key == arr[mid]) {
            flag = 1;
            break;
        } 

        if (key > arr[mid]) {
            low = mid+1;
        } else {
            high = mid-1;
        } 
    }

    return flag;
}