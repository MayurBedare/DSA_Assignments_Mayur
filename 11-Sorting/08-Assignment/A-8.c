/*
    A-8 -> Write a C program to Accept an array and Perform Merge sort.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

void mergeSort(int[],int,int);
void merge(int[],int,int,int);
void display(int[]);

int main() {
    printf("\n\t ***** Merge Sort : Sorting ***** \n");

    printf("\n\t -------------------------------------------------------------- ");
    printf("\n\t The Time Complexity of the Merge Sort [worst cases] : O(nlogn) \n");
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

    mergeSort(arr,0,SIZE-1);

    printf("\n\t The given arr[%d] : \n",SIZE);
    display(arr);
    printf("\n\n");
    
    free(arr);
    arr = NULL;
    
    return 0;
}

void mergeSort(int arr[],int i,int j) {
    int mid = (i+j)/2;

    if (mid != i || mid != j) {
        mergeSort(arr,i,mid);
        mergeSort(arr,mid+1,j);
        merge(arr,i,mid,j);
    } else {
        return;
    }
}

void merge(int arr[],int i,int m,int j) {
    int k = -1,temp;
    for (int k = i ; k <= j ; k++) {
        for (int l = m+1 ; l <= j ; l++) {
            if (k < l) {
                if (arr[k] > arr[l]) {
                    temp = arr[k];
                    arr[k] = arr[l];
                    arr[l] = temp; 
                }
            }
        }
    }
}  

void display(int arr[]) {
    for (int i = 0 ; i < SIZE ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }
}