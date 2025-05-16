/*
    A-1 -> Write a C program to implement Linear Search. Also, print the time complexity at the start of the program. Follow this pattern for all upcoming questions.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 8

int linearSearch(int[],int,int,int);

int main() {

    printf("\n\t ***** Linear Search : Searching ***** \n");

    printf("\n\t ------------------------------------------------------------");
    printf("\n\t The Time Complexity of the Linear Search [worst cases]: O(n) \n");
    printf("\t ------------------------------------------------------------ \n");

    int *arr = NULL,i = -1,key;
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
    
    printf("\n\t Enter the array element to be searched : ");
    scanf("%d",&key);

    i = linearSearch(arr,i,SIZE,key);

    if (i != -1)    printf("\n\t The array element %d is found at arr[%d] \n\n",key,i);     
    else    printf("\n\t The array element %d is not found! \n\n",key);   

    return 0;   
}

int linearSearch(int arr[],int i,int n,int key) {
    for (int j = 0 ; j < n ; j++) {
        if (arr[j] == key) {
            i = j;
            break;
        }
    }
    
    return i;
}
