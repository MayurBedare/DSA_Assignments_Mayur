/*
    A-1 ->  - Write a C program which allocates an array dynamically.
	        - Implement logic to check the frequency of each element throughout the array
*/

/* 
    Input ->    arr[10] = {1,2,3,3,2,1,4,4,5,5}                  
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main() {
    int *arr = NULL;
    arr = malloc(SIZE*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed!\n\n");
        exit(1);
    }

    int size = 0,flag = 1;
    int **freq = NULL;
    freq = malloc(sizeof(int*));
    if (freq == NULL) {
        printf("\n\t Memory Allocation Failed!\n\n");
        exit(1);
    }
    *freq = (int*)malloc(2*sizeof(int));
    if (*freq == NULL) {
        printf("\n\t Memory Allocation Failed!\n\n");
        exit(1);
    }

    printf("\n\t Enter the elements of arr[10] one by one : \n\n");

    for (int i = 0 ; i < SIZE ; i++) {
        printf("\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
        
        if (i != 0) {
            for (int k = 0 ; k < size ; k++) {
                if (freq[k][0] == arr[i]) {
                    flag = 0;
                    freq[k][1]++;
                } else {
                    if (flag != 0) {
                    flag = 1;
                    }
                }
            }

            if (flag != 0) {
                freq = (int**)realloc(freq,(size+1)*sizeof(int*));
                if(freq == NULL) {
                    printf("\n\t Memory Allocation Failed!\n\n");
                    exit(1);
                }
                freq[size] = (int*)malloc(2*sizeof(int));
                if(freq[size] == NULL) {
                    printf("\n\t Memory Allocation Failed!\n\n");
                    exit(1);
                }
                freq[size][0] = arr[i];
                freq[size][1] = 1;
                size++;
            }
            flag = 1;
        } else {
            freq[i][0] = arr[i];
            freq[i][1] = 1;
            size++;
        }
    }

    printf("\n\t arr[10] : ");
    printf("|_%d_|",arr[0]);
    for (int i = 1 ; i < SIZE ; i++) {
        printf("_%d_|",arr[i]);
    }
    printf("\n");

    printf("\n\t Frequency of given array elements : \n");
    for (int i = 0 ; i < size ; i++) {
        printf("\n\t Frequency of %d : %d ",freq[i][0],freq[i][1]);
    }
    printf("\n\n");

    free(arr); 
    arr = NULL;

    free(freq); 
    freq = NULL;

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

                arr[10] : |_1_|_2_|_3_|_3_|_2_|_1_|_4_|_4_|_5_|_5_|

                Frequency of given array elements : 

                Frequency of 1 : 2 
                Frequency of 2 : 2 
                Frequency of 3 : 2 
                Frequency of 4 : 2 
                Frequency of 5 : 2                                
*/