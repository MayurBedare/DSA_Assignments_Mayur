/*
    A-3 ->  Accept elements in two n*m matrix and display the multiplication of two matrix
*/

#include<stdio.h>
#include<stdlib.h>

void display(int **,int,int);

int main() {
    int N1,M1,N2,M2;

    printf("\n\t ***** Multiplication of 2 n*m matrix ***** \n");

    while (1) {
        printf("\n\t Enter the no. of rows and columns of arr_1 / matrix_1 : ");
        scanf("%d %d",&N1,&M1);
        printf("\n\t Enter the no. of rows and columns of arr_2 / matrix_2 : ");
        scanf("%d %d",&N2,&M2);

        if (M1 != N2) {
            printf("\n\t Multiplication of 2 matrix is not possible! \n");
            printf("\n\t | Columns of arr_1 / matrix_1 must be equal to Rows of arr_2 / matrix_2 | \n\n");
            continue;
        } else {
            break;
        }
    }

    int **arr1 = NULL,**arr2 = NULL,**arr3 = NULL;

    arr1 = (int**)malloc(N1*sizeof(int*));
    if (arr1 == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    arr2 = (int**)malloc(N2*sizeof(int*));
    if (arr2 == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    arr3 = (int**)malloc(N1*sizeof(int*));
    if (arr3 == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter the elements in an arr_1[%d][%d] : \n",N1,M1);
    for (int i = 0 ; i < N1 ; i++) {
        arr1[i] = (int*)malloc(M1*sizeof(int));
        if (arr1[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        arr3[i] = (int*)malloc(M2*sizeof(int));
        if (arr3[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        for (int j = 0 ; j < M1 ; j++) {
            if (j == 0) printf("\n");
            printf("\t Enter arr_1[%d][%d] : ",i,j);
            scanf("%d",&arr1[i][j]); // scanf("%d",(arr + i + j)); also same
        }
    }

    printf("\n\t Enter the elements in an arr_2[%d][%d] : \n",N2,M2);
    for (int i = 0 ; i < N2 ; i++) {
        arr2[i] = (int*)malloc(M2*sizeof(int));
        if (arr2[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        for (int j = 0 ; j < M2 ; j++) {
            if (j == 0) printf("\n");
            printf("\t Enter arr_2[%d][%d] : ",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }

    printf("\n\t The given arr_1[%d][%d] : \n",N1,M1);
    display(arr1,N1,M1);

    printf("\n\t The given arr_2[%d][%d] : \n",N2,M2);
    display(arr2,N2,M2);

    int sum = 0;
    for (int i = 0 ; i < N1 ; i++) {
        for (int j = 0 ; j < M2 ; j++) {
            for (int k = 0,l = 0 ; k < M1 ; k++,l++) { // M1 == N2
                    sum = sum + arr1[i][k]*arr2[l][j];
            }
            arr3[i][j] = sum;
            sum = 0;
        }
    }

    printf("\n\t Multiplication of arr_1[%d][%d] and arr_2[%d][%d] : \n",N1,M1,N2,M2);
    printf("\n\t arr[%d][%d] : \n",N1,M2);
    display(arr3,N1,M2);
    printf("\n");

    if (arr1 != NULL && arr3 != NULL) {
        for (int i = 0 ; i < N1 ; i++) {
            free(arr1[i]);
            free(arr3[i]);
        }
        free(arr1);
        arr1 = NULL;
        free(arr3); 
        arr3 = NULL;
    }

    if (arr2 != NULL) {
        for (int i = 0 ; i < N2 ; i++) {
            free(arr2[i]);
        }
        free(arr2);
        arr2 = NULL;
    }

    return 0;   
}

void display(int **arr,int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (j == 0) printf("\n\t |_%d_|",arr[i][j]);
            else    printf("_%d_|",arr[i][j]);
        }
    }
    printf("\n");
}

