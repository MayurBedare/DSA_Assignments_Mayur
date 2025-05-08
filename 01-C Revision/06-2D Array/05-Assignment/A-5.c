/*
    A-5 ->  Accept elements in 3x3 matrix and check whether it is magic square or not(magic square: 
            sum of all elements in row and column and both diagonals are same)
*/

#include<stdio.h>
#include<stdlib.h>

#define N 3

void magicSquare();

int main() {
    printf("\n\t ***** Checking the Magic Square Matrix of 3*3 ***** \n");

    while (1) {
        int ch;
        printf("\n\t -------------------------------------------");
        printf("\n\t 1. Check the matrix is magic square or not ");
        printf("\n\t 2. Exit ");
        printf("\n\t -------------------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t ------------------------------------------- \n");

        switch (ch) {
            case 1:
                magicSquare();
                break;
            
            case 2:
                printf("\n\t Program Exited Successfully! \n\n");
                exit(0);
            
            default:
                printf("\n\t Invalid Choice Entered! \n");
                break;
        }
    }  

    return 0;
}

void magicSquare() {
    int flag = 0;

    int **arr = NULL;
    arr = (int**)malloc(N*sizeof(int*));
    if (arr == NULL) {
        printf("\n\t Memeory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter the elements in an arr[%d][%d] : \n",N,N);
    
    for (int i = 0 ; i < N ; i++) {
        arr[i] = (int*)malloc(N*sizeof(int));
        if (arr[i] == NULL) {
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

    int sum_rows = 0,sum_cols = 0,sum_L_diag = 0,sum_R_diag = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int k = 0 ; k < N ; k++) {
            sum_rows = sum_rows + arr[i][k];
            sum_cols = sum_cols + arr[k][i];
        }

        if (sum_rows != sum_cols)   flag = 1;
        
        for (int j = 0 ; j < N ; j++) {
            sum_rows = 0,sum_cols = 0;

            if (j == 0) printf("\n\t |_%d_|",arr[i][j]);
            else    printf("_%d_|",arr[i][j]);
             
            if (i == j) sum_L_diag = sum_L_diag + arr[i][j];
            if (j == N - 1 - i) sum_R_diag = sum_R_diag + arr[i][j];
        }
    }
    printf("\n");

    if ((sum_L_diag == sum_R_diag) && flag != 1) {
        printf("\n\t The given arr[%d][%d] is a Square Matrix. \n", N, N);
        printf("\n\t | The sum of all rows , all columns and both diagonals : %d | \n",sum_rows);
    } else {
        printf("\n\t The given arr[%d][%d] is not a Square Matrix! \n",N,N);
        printf("\n\t | The sum of all rows , all columns and both diagonals is not same | \n",sum_rows);
    }

    if (arr != NULL) {
        for (int i = 0 ; i < N ; i++) {
            free(arr[i]);
        }
        free(arr);
        arr = NULL;
    }
}


