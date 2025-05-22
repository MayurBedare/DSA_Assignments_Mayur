/*
    A-2 ->  - Write a C program which allocates an array dynamically.
	        - Implement logic which accepts only unique elements in array
*/

/* 
    Input ->    arr[10] = {1,2,3,3,2,1,4,4,5,5}                  
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int SIZE;
    printf("\n\t Enter the size of an array : ");
    scanf("%d",&SIZE);

    int *arr = NULL;
    arr = (int*)malloc(SIZE*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed!\n\n");
        exit(1);
    }

    printf("\n\t Enter the elements of arr[10] one by one : \n\n");
    int i = 0,j = 0;
    while (i < SIZE) {
        printf("\t Enter arr[%d] : ",j++);
        scanf("%d",&arr[i]);
        
        if (i != 0) {
            for (int k = 0 ; k < i ; k++) {
                if (arr[k] == arr[i]) {
                    i--;
                    arr = (int*)realloc(arr,(SIZE--)*sizeof(int));
                    if (arr == NULL) {
                        printf("\n\t Memory Allocation Failed!\n\n");
                        exit(1);
                    }
                    break;
                } 
            }
        } 
        i++;
    }

    printf("\n\t Array with accepting only unique elements from the given array : \n");
    printf("\n\t arr[%d] : ",SIZE);
    printf("|_%d_|",arr[0]);
    for (int i = 1 ; i < SIZE ; i++) {
        printf("_%d_|",arr[i]);
    }
    printf("\n\n");

    free(arr); 
    arr = NULL;

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

                Array with accepting only unique elements from the given array :

                arr[5] : |_1_|_2_|_3_|_4_|_5_|                            
*/