/*
    A-2 ->  Accept  two different n*m matrix and store and display the addition of two matrix in 3rd matrix
*/

#include<stdio.h>
#include<stdlib.h>

void display(int **,int,int);

int main() {
    int N,M,n,m;

    printf("\n\t ***** Addition of 2 n*m matrix to 3rd matrix ***** \n");

    while (1) {
        printf("\n\t Enter the no. of rows and columns of arr_1 / matrix_1 : ");
        scanf("%d %d",&N,&M);
        printf("\n\t Enter the no. of rows and columns of arr_2 / matrix_2 : ");
        scanf("%d %d",&n,&m);

        if (N != n && M != m) {
            printf("\n\t Addition of two matrix is not possible! \n");
            printf("\n\t | Rows and columns of both arr_1 / matrix_1 and arr_2 / matrix_2 must be equal | \n\n");
            continue;
        } else {
            break;
        }
    }

    int **arr1 = NULL,**arr2 = NULL,**arr3 = NULL;

    arr1 = (int**)malloc(N*sizeof(int*));
    if (arr1 == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    arr2 = (int**)malloc(N*sizeof(int*));
    if (arr2 == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    arr3 = (int**)malloc(N*sizeof(int*));
    if (arr3 == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter the elements in an arr_1[%d][%d] : \n",N,M);
    for (int i = 0 ; i < N ; i++) {
        arr1[i] = (int*)malloc(M*sizeof(int));
        if (arr1[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        arr2[i] = (int*)malloc(M*sizeof(int));
        if (arr2[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        arr3[i] = (int*)malloc(M*sizeof(int));
        if (arr3[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        for (int j = 0 ; j < M ; j++) {
            if (j == 0) printf("\n");
            printf("\t Enter arr_1[%d][%d] : ",i,j);
            scanf("%d",&arr1[i][j]); 
        }
    }

    printf("\n\t Enter the elements in an arr_2[%d][%d] : \n",N,M);
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (j == 0) printf("\n");
            printf("\t Enter arr_2[%d][%d] : ",i,j);
            scanf("%d",&arr2[i][j]);

            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("\n\t The given arr_1[%d][%d] : \n",N,M);
    display(arr1,N,M);

    printf("\n\t The given arr_2[%d][%d] : \n",N,M);
    display(arr2,N,M);

    printf("\n\t Addition of arr_1[%d][%d] and arr_2[%d][%d] : \n",N,M,n,m);
    printf("\n\t arr[%d][%d] : \n");
    display(arr3,N,M);
    printf("\n");

    if (arr1 != NULL && arr2 != NULL && arr3 != NULL) {
        for (int i = 0 ; i < N ; i++) {
            free(arr1[i]);
            free(arr2[i]);
            free(arr3[i]);
        }
        free(arr1);
        arr1 = NULL;
        free(arr2);
        arr2 = NULL;
        free(arr3); 
        arr3 = NULL;
    }

    return 0;   
}

void display(int **arr,int n,int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (j == 0) printf("\n\t |_%d_|",arr[i][j]);
            else    printf("_%d_|",arr[i][j]);
        }
    }
    printf("\n");
}

