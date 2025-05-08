/*
    A-4 ->  Accept elements in 4*4 matrix and display the Transpose of matrix
*/

#include<stdio.h>
#include<stdlib.h>

#define N 4

int main() {
    int **arr = NULL,**transpose = NULL;
    arr = (int**)malloc(N*sizeof(int*));
    if (arr == NULL) {
        printf("\n\t Memeory Allocation Failed! \n\n");
        exit(1);
    }
    transpose = (int**)malloc(N*sizeof(int*));
    if (transpose == NULL) {
        printf("\n\t Memeory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t ***** Transpose of 4*4 matrix ***** \n");

    printf("\n\t Enter the elements in an arr[%d][%d] : \n",N,N);
    
    for (int i = 0 ; i < N ; i++) {
        arr[i] = (int*)malloc(N*sizeof(int));
        if (arr[i] == NULL) {
            printf("\n\t Memeory Allocation Failed! \n\n");
            exit(1);
        }
        transpose[i] = (int*)malloc(N*sizeof(int));
        if (transpose[i] == NULL) {
            printf("\n\t Memeory Allocation Failed! \n\n");
            exit(1);
        }

        for (int j = 0 ; j < N ; j++) {
            if (j == 0) printf("\n");
            printf("\t Enter arr[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]); 
        }
    }

    printf("\n\t The given arr[%d][%d] : \n",N,N);

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (j == 0) printf("\n\t |_%d_|",arr[i][j]);
            else    printf("_%d_|",arr[i][j]);
        }
    }

    printf("\n\n\t Transpose of 4*4 matrix of arr[%d][%d] : \n",N,N);

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            transpose[i][j] = arr[j][i];
            if (j == 0) printf("\n\t |_%d_|",transpose[i][j]);
            else    printf("_%d_|",transpose[i][j]);
        }
    }
    printf("\n\n");

    if (arr != NULL && transpose != NULL) {
        for (int i = 0 ; i < N ; i++) {
            free(arr[i]);
            free(transpose[i]);
        }
        free(arr);
        arr = NULL;
        free(transpose);
        transpose = NULL;
    }

    return 0;   
}

