/*
    A-10 -> - Write a C program which accepts an array dynamically
            - Find the subarray with maximum sum 
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main() {
    int max_sum = 0,index = 0,size_subarr = 1,x = 1,check_all_minus = 0;
    int *arr = NULL;
    arr = (int*)malloc(SIZE*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Falied! \n\n");
        exit(1);
    }

    printf("\n\t ***** Finding subarray with maximum sum of given array ***** \n");

    printf("\n\t Enter the elements of arr[%d] one by one : \n",SIZE);
    for (int i = 0 ; i < SIZE ; i++) {
        printf("\n\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);

        if (arr[i] < 0) {
            check_all_minus++;
        }
    }

    printf("\n\t The given arr[%d] : \n",SIZE);
    for (int i = 0 ; i < SIZE ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }

    if (check_all_minus == SIZE) {
        max_sum = arr[0];
    }

    while (x <= SIZE) {
        for (int m = 0 ; m < SIZE ; m++) {
            int sum = 0;
            for (int n = m ; n < m+x && n < SIZE ; n++) {
                sum = sum + arr[n];
            }
            if (sum > max_sum) {
                max_sum = sum;
                index = m,size_subarr = x;
            }
        }
        if (x == 1 && check_all_minus == SIZE) {
            break;
        }
        x++;
    }

    printf("\n\n\t The subarray with maximum sum : \n");
    for (int j = index ; j < index + size_subarr ; j++) {
        if (j == index) printf("\n\t |_%d_|",arr[j]);
        else    printf("_%d_|",arr[j]);
    }

    printf("\n\n\t The maximum sum of subarray of arr[%d] : %d \n\n",SIZE,max_sum);

    free(arr);
    arr = NULL;

    return 0;   
}

