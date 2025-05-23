/*
    A-3 ->  - Write a C program which allocates an array dynamically.
	        - Implement logic that removes duplicate elements from the array.
*/

/* 
    Input ->    arr[10] = {1,2,3,3,2,1,4,4,5,5}                  
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main() {
    int *arr = NULL;
    arr = (int*)malloc(SIZE*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed!\n\n");
        exit(1);
    }

    int size = 0,flag = 1;
    int *unique = NULL;
    unique = (int*)malloc(sizeof(int));
    if (unique == NULL) {
        printf("\n\t Memory Allocation Failed!\n\n");
        exit(1);
    }

    printf("\n\t Enter the elements of arr[10] one by one : \n\n");

    for (int i = 0 ; i < SIZE ; i++) {
        printf("\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
        
        if (i != 0) {
            for (int k = 0 ; k < size ; k++) {
                if (unique[k] == arr[i]) {
                    flag = 0;
                } else {
                    if (flag != 0) {
                    flag = 1;
                    }
                }
            }

            if (flag != 0) {
                unique = (int*)realloc(unique,(size+1)*sizeof(int));
                if(unique == NULL) {
                    printf("\n\t Memory Allocation Failed!\n\n");
                    exit(1);
                }
                unique[size] = arr[i];
                size++;
            }
            flag = 1;
        } else {
            unique[i] = arr[i];
            size++;
        }
    }

    printf("\n\t Array with removal of duplicate elements from the given array : \n");
    printf("\n\t arr[%d] : ",size);
    printf("|_%d_|",unique[0]);
    for (int i = 1 ; i < size ; i++) {
        printf("_%d_|",unique[i]);
    }
    printf("\n\n");

    free(arr); 
    arr = NULL;

    free(unique); 
    unique = NULL;

    return 0;   
}

/*
    Output -> 
                Enter the elements of arr[10] one by one : 

                Enter arr[0] : 1 
                Enter arr[1] : 2
                Enter arr[2] : 3
                Enter arr[3] : 3
                Enter arr[4] : 2
                Enter arr[5] : 1
                Enter arr[6] : 4
                Enter arr[7] : 4
                Enter arr[8] : 5
                Enter arr[9] : 5

                Array with removal of duplicate elements from the given array : 

                arr[5] : |_1_|_2_|_3_|_4_|_5_|                             
*/