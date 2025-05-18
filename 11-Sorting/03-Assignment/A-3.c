/*
    A-3 ->  Write a C program to Accept an array and Perform Insertion sort.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

int main() {
    printf("\n\t ***** Insertion Sort : Sorting ***** \n");

    printf("\n\t ----------------------------------------------------------------");
    printf("\n\t The Time Complexity of the Insertion Sort [worst cases] : O(n^2) \n");
    printf("\t ---------------------------------------------------------------- \n");

    int *arr = NULL;
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

    printf("\n\t The given arr[%d] : \n",SIZE);
    for (int i = 0 ; i < SIZE ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }

    for (int i = 1 ; i < 8 ; i++) {
        int j,b;
        for (j = i-1,b = arr[i] ; j >= 0 && arr[j] > b ; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = b;
    }

    printf("\n\n\t The given arr[%d] after sorting : \n",SIZE);
    for (int i = 0 ; i < SIZE ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }
    printf("\n\n");

    free(arr);
    arr = NULL;

    return 0;   
}