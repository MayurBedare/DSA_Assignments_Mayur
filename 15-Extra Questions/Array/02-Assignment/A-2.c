// A-2 -> Given an array of integers find the length of longest subarray whose sum is equal to the target value k

#include<stdio.h>
#include<stdlib.h>

int findLength(int[],int,int);

int main() {
    int n,k;
    printf("\n\t Enter the value of n : ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    if (!arr) {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    printf("\n\t Enter the values of array : ");
    for (int i = 0 ; i < n ; i++)   scanf("%d",&arr[i]);

    printf("\n\t Enter the value of K to find the lenght of longest subarray : ");
    scanf("%d",&k);

    n = findLength(arr,k,n);

    printf("\n\t The length of longest subarray : %d \n\n",n);

    free(arr);
    arr = NULL;

    return 0;
}

int findLength(int arr[],int k,int n) {
    int beg,end;
    beg = end = 0;

    while (end != n) {
        if (arr[end] == k)  return 1;
        
        int sum = 0;
        for (int i = beg ; i <= end ; i++) {
            sum += arr[i];
        }
    
        if (sum == k) {
            return end-beg+1;
        } else if (sum > k) {
            beg++,end++;
        } else {
            end++;
        }  
        
    }

    return 0;
}