/*
    A-1 ->  Write a C program to Accept an array and Perform Exchange sort.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

int main() {
    printf("\n\t ***** Exchange Sort : Sorting ***** \n");

    printf("\n\t ------------------------------------------------------------");
    printf("\n\t The Time Complexity of the Exchange Sort [worst cases]: O(n) \n");
    printf("\t ------------------------------------------------------------ \n");

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

    printf("\n\n\t The given arr[%d] after sorting : \n",SIZE);
    for (int i = 0 ; i < SIZE ; i++) {
        for (int j = i + 1 ; j < SIZE ; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }
    printf("\n\n");

    return 0;   
}