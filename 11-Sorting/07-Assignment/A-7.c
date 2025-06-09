/*
    A-7 ->  Write a C program to Accept an array and Perform Quick sort.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

void quickSort(int[],int,int);
void display(int[]);

int main() {
    printf("\n\t ***** Quick Sort : Sorting ***** \n");

    printf("\n\t -------------------------------------------------------------- ");
    printf("\n\t The Time Complexity of the Quick Sort [worst cases] : O(nlogn) \n");
    printf("\t -------------------------------------------------------------- \n");

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

    quickSort(arr,-1,SIZE-1);

    printf("\n\t The given arr[%d] : \n",SIZE);
    display(arr);
    printf("\n\n");
    
    free(arr);
    arr = NULL;
    
    return 0;
}

void display(int arr[]) {
    for (int i = 0 ; i < SIZE ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }
}

void quickSort(int arr[], int i,int n) {
    if (i == n) { return; }
    else if (i > n) { return; }

    int j = i+1,temp,pivot = arr[n],p_i = n;

    for ( ; j < n ; j++) {
        if (arr[j] < pivot) {
            temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    if (arr[i+1] > pivot) {
        temp = arr[i+1];
        arr[i+1] = arr[j];
        arr[j] = temp;
        p_i = i+1;
    }

    if (i == p_i-1) i = -1;

    quickSort(arr,i,p_i-1);
    quickSort(arr,p_i,n);
}