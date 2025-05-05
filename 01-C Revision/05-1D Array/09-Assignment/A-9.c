/*
    A-9 ->  Accept n elements in an array and display the differance between the sum of 1st half  
            and 2nd half of that array 
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int i = 0,key,size = 1,flag = 0;
    int *arr = NULL;
    arr = (int*)malloc(sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t ***** Finding difference between 1st and 2nd half of array ***** \n");

    printf("\n\t Note -> Enter arr[last] : -1 to exit \n");
    printf("\n\t Enter the elements of arr[n] one by one : \n");

    while (1) {
        printf("\n\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);

        if (arr[i] == -1) {
            size--;
            break;
        } 

        size++;
        arr = (int*)realloc(arr,(size)*sizeof(int));
        if (arr == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        i++;
    }

    int mid = size/2,sum_1 = 0,sum_2 = 0;
    printf("\n\t The given arr[%d] : \n",size);
    for (int i = 0 ; i < size ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);

        if (i < mid) {
            sum_1 = sum_1 + arr[i];
        } else {
            sum_2 = sum_2 + arr[i];
        }
    }
    printf("\n");

    int diff = sum_1 - sum_2;

    printf("\n\t The difference between the 1st half and 2nd half of given arr[%d] : %d \n\n",size,diff);

    return 0;   
}
