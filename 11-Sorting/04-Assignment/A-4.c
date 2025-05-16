/*
    A-2 ->  Write a C program to Accept an array and Perform Selection sort.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

int main() {
    printf("\n\t ***** Selection Sort : Sorting ***** \n");

    printf("\n\t ----------------------------------------------------------------");
    printf("\n\t The Time Complexity of the Selection Sort [worst cases] : O(n^2) \n");
    printf("\t ---------------------------------------------------------------- \n");

    int *arr = NULL,smallest,temp;
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

    for (int i = 0 ; i < 8 ; i++) {
        smallest = i;
        for (int j = i+1 ; j < 8 ; j++) {
            if (arr[j] < arr[i]) {
                smallest = j;
            }
        }
        if (smallest != i) {
            temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        } 
    }

    printf("\n\n\t The given arr[%d] after sorting : \n",SIZE);
    for (int i = 0 ; i < SIZE ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }
    printf("\n\n");

    return 0;   
}