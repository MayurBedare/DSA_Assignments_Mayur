/*
    A-5 ->  - Write a C program which allocates an array dynamically.
            - Implement logic that returns 2nd large element from the array 
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main() {
    int largest = 0,second_largest = 0;
    int *arr = NULL;
    arr = (int*)malloc(SIZE*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter the elements of arr[10] one by one : \n");
    for (int i = 0 ; i < SIZE ; i++) {
        printf("\n\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);

        if (i == 0) {
            largest = arr[i];
        } else {
            if (arr[i] > largest) {
                second_largest = largest;
                largest = arr[i];
            } else {
                if (second_largest == 0) {
                    second_largest = arr[i];
                }
            }
        } 
    }

    if (second_largest == 0) {
        printf("\n\t Array contains only one element (duplicate)! \n\n");
        exit(1);
    } else {
        printf("\n\t The second largest element in the given array : %d \n\n",second_largest);
    }

    free(arr);
    arr = NULL;

    return 0;   
}
