/*
    A-5 -> Write a C program to Accept an array and Perform Shell sort.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 9

void insertionSort(int[]);
void display(int[]);

int main() {    
    printf("\n\t ***** Shell Sort : Sorting ***** \n");

    printf("\n\t ------------------------------------------------------------ ");
    printf("\n\t The Time Complexity of the Shell Sort [worst cases] : O(n^2) \n");
    printf("\t ------------------------------------------------------------ \n");

    int *arr = NULL;
    arr = (int*)malloc(SIZE*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter elements of arr[%d] one by one : \n\n",SIZE);

    for (int i = 0 ; i < SIZE ; i++) {
        printf("\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    printf("\n\t The given arr[%d] : \n",SIZE);
    display(arr);
    printf("\n");

    int gap = SIZE/2;

    while (gap > 0) {
        int i = 0, j = gap;
        while (j < SIZE) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++,j++;
        }
        gap = gap/2;
    }

    insertionSort(arr);

    printf("\n\t The given arr[%d] after Sorting : \n",SIZE);
    display(arr);
    printf("\n\n");

    free(arr);
    arr = NULL;

    return 0;
}

void insertionSort(int arr[]) {
    for (int i = 1 ; i < SIZE ; i++) {
        int j,b;
        for (j = i-1,b = arr[i] ; j >= 0 && arr[j] > b ; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = b;
    }
}

void display(int arr[]) {
    for (int i = 0 ; i < SIZE ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }
}

