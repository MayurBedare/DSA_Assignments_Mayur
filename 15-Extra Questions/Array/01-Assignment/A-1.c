/*  A-1 -> Given an array of n integers find if their exist a pair of elements whose sum is equal to a given no. k */

/*
        arr[] = {10,15,3,7}
        input -> 17
        output -> Pair Found : 10+7 = 17
*/

#include<stdio.h>
#include<stdlib.h>

int hasPair(int[],int);

int main() {
    int n;
    printf("\n\t Enter the value of n : ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    if (!arr) {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    printf("\n\t Enter the values of array : ");
    for (int i = 0 ; i < n ; i++)   scanf("%d",&arr[i]);

    int flag = 0,val;
    printf("\n\t Enter the value to check : ");
    scanf("%d",&val);
    flag = hasPair(arr,val);
    if (flag) {
        printf("\n\t Pair Found \n\n");
    } else {
        printf("\n\t Pair Not Found \n\n");
    }

    free(arr);
    arr = NULL;

    return 0;
}

int hasPair(int arr[],int val) {
    for (int i = 0 ; i < 4 ; i++) 
        if (val == arr[i]) return 1;
    
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = i+1 ; j < 4 ; j++) {
            int sum = arr[i];
            while (j != 4) {
                sum += arr[j];
                if (val == sum) {
                    return 1;
                }
                sum = arr[i] + arr[j];
                if (val == sum) {
                    return 1;
                }
                j++;
            }
        }
    }
    
    return 0;
}