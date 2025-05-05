/*
    A-4 ->  - Write a C program which allocates two array dynamically.
            - Implement logic to merge and sort two array.  
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int main() {
    int *arr_1 = NULL,*arr_2 = NULL;

    arr_1 = (int*)malloc(SIZE*sizeof(int));
    if (arr_1 == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    } 

    arr_2 = (int*)malloc(SIZE*sizeof(int));
    if (arr_2 == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter the elements of arr_1[5] one by one : \n");
    for (int i = 0 ; i < SIZE ; i++) {
        printf("\n\t Enter arr_1[%d] : ",i);
        scanf("%d",(arr_1+i));// &arr[i] == arr + i
    }
    arr_1 = (int*)realloc(arr_1,SIZE*2*sizeof(int));
    if (arr_1 == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\n\t Enter the elements of arr_2[5] one by one : \n");
    for (int i = 0 ; i < SIZE ; i++) {
        printf("\n\t Enter arr_2[%d] : ",i);
        scanf("%d",(arr_2+i));// &arr[i] == arr + i

        arr_1[SIZE+i] = arr_2[i];
    }    

    int temp;
    for (int i = 0 ; i < SIZE*2 ; i++) {
        for (int j = i+1 ; j < SIZE*2 ; j++) {
            if (arr_1[i] > arr_1[j]) {
                temp = arr_1[i];
                arr_1[i] = arr_1[j];
                arr_1[j] = temp;
            }
        }
    }

    printf("\n\t Array after merging and sorting of two given array (arr_1,arr_2) : \n");
    printf("\n\t arr[10] : ");
    printf("|_%d_|",arr_1[0]);
    for (int i = 1 ; i < SIZE*2 ; i++) {
        printf("_%d_|",arr_1[i]);
    }
    printf("\n\n");

    free(arr_1);
    arr_1 = NULL;

    free(arr_2);
    arr_2 = NULL;

    return 0;   
}

