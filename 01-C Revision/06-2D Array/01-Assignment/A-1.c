/*
    A-1 ->  - Write a C program which allocates 2D array dynamically (N X M).
            - Implement logic to get: 
                                - Sum of all elements. 
                                - sum of elements from the 2nd column
                                - Display left and right diagonals
                                - sum of left diagonal
                                - sum of right diagonal
                                - larger element from left diagonal 
                                - smaller element from left diagonal
                                - larger element from right diagonal
                                - smaller element from right diagonal 
                                - Sort the left diagonal
                                - sort the right diagonal
*/

#include<stdio.h>
#include<stdlib.h>
// for rectangular matrix N : 3 , M : 4
// for square matrix
#define N 4
#define M 4

void sum_allElements(int **);
void sum_2ndColumnElements(int **);
void display_LeftRightDiagonals(int **);
void sum_leftDiagonal(int **);
void sum_rightDiagonal(int **);
void largerElement_leftDiagonal(int **);
void smallerElement_leftDiagonal(int **);
void largerElement_rightDiagonal(int **);
void smallerElement_rightDiagonal(int **);
void sort_leftDiagonal(int **);
void sort_rightDiagonal(int **);
void display(int**);

int main() {
    int **arr = NULL;
    arr = (int**)malloc(N*sizeof(int*));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    printf("\n\t ***** 2D array different Operations ***** \n");

    printf("\n\t Enter the elements in an arr[%d][%d] : \n",N,M);
    for (int i = 0 ; i < N ; i++) {
        arr[i] = (int*)malloc(M*sizeof(int)); // arr[i] == *(arr + i)
        if (arr[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        for (int j = 0 ; j < M ; j++) {
            if (j == 0) printf("\n");
            printf("\t Enter arr[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]); // scanf("%d",*(arr + i) + j); also same scanf("%d",arr[i]+j);
        }
    }

    display(arr);

    while (1) {
        int ch;
        printf("\n\t ----------------------------------------");
        printf("\n\t  1. Sum of all elements ");
        printf("\n\t  2. Sum of elements from the 2nd column ");
        printf("\n\t  3. Display left and right diagonals ");
        printf("\n\t  4. Sum of left diagonal ");
        printf("\n\t  5. Sum of right diagonal ");
        printf("\n\t  6. Larger element from left diagonal ");
        printf("\n\t  7. Smaller element from left diagonal ");
        printf("\n\t  8. Larger element from right diagonal");
        printf("\n\t  9. Smaller element from right diagonal ");
        printf("\n\t 10. Sort the left diagonal ");
        printf("\n\t 11. sort the right diagonal ");
        printf("\n\t 12. Exit ");
        printf("\n\t ----------------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t ----------------------------------------\n");

        switch (ch) {
            case 1: 
                display(arr);
                sum_allElements(arr);
                break;
            
            case 2:
                display(arr);
                sum_2ndColumnElements(arr);
                break;

            case 3:
                display(arr);
                display_LeftRightDiagonals(arr);
                break;

            case 4:
                display(arr);
                sum_leftDiagonal(arr);
                break;

            case 5:
                display(arr);
                sum_rightDiagonal(arr);
                break;

            case 6:
                display(arr);
                largerElement_leftDiagonal(arr);
                break;

            case 7:
                display(arr);
                smallerElement_leftDiagonal(arr);
                break;

            case 8:
                display(arr);
                largerElement_rightDiagonal(arr);
                break;
            
            case 9:
                display(arr);
                smallerElement_rightDiagonal(arr);
                break;

            case 10:
                display(arr);
                sort_leftDiagonal(arr);
                break;

            case 11:
                display(arr);
                sort_rightDiagonal(arr);
                break;
            
            case 12: 
                printf("\n\t Program Exited Successfully! \n\n");
                exit(0);
            
            default:
                printf("\n\t Invalid Choice Entered! \n");
                break;
        }
    }

    if (arr != NULL) {
        for (int i = 0 ; i < N ; i++) {
            free(arr[i]);
        }
        free(arr);
        arr = NULL;
    }

    return 0;   
}

void display(int **arr) {
    printf("\n\t The given arr[%d][%d] : \n",N,M);

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (j == 0) printf("\n\t |_%d_|",arr[i][j]);// arr[i][j] same as *(arr[i] + j) same as *(*(arr+i)+j) 
            else    printf("_%d_|",arr[i][j]);
        }
    }
    printf("\n");
}

void sum_allElements(int **arr) {
    int sum = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            sum = sum + arr[i][j];
        }
    }

    printf("\n\t The sum of all elements of given arr[%d][%d] : %d \n",N,M,sum);
}

void sum_2ndColumnElements(int **arr) {
    int sum = 0;
    for (int i = 0 ; i < N ; i++) {
        sum = sum + arr[i][1]; 
    }

    printf("\n\t The sum of 2nd Column elements of given arr[%d][%d] : %d \n",N,M,sum);
}

void display_LeftRightDiagonals(int **arr) {
    printf("\n\t Displaying the Left Diagonals of the given arr[%d][%d] : \n",N,M);
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (i == j) {
                if (j == 0) printf("\n\t |_%d_|",arr[i][j]);
                else    printf("_%d_|",arr[i][j]);
            } else {
                if (j == 0) printf("\n\t |_ _|");
                else    printf("_ _|");
            }
        }
    }
    printf("\n");

    printf("\n\t Displaying the Right Diagonals of the given arr[%d][%d] : \n",N,M);
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (j == M-(i+1)) {
                if (j == 0) printf("\n\t |_%d_|",arr[i][j]);
                else    printf("_%d_|",arr[i][j]);
            } else {
                if (j == 0) printf("\n\t |_ _|");
                else    printf("_ _|");
            }
        }
    }
    printf("\n");
}

void sum_leftDiagonal(int **arr) {
    int sum = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (i == j) {
                sum = sum + arr[i][j];
            } 
        }
    }

    printf("\n\t The sum of left diagonal of the given arr[%d][%d] : %d \n",N,M,sum);
}

void sum_rightDiagonal(int **arr) {
    int sum = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (j == M-(i+1)) {
                sum = sum + arr[i][j];
            }
        }
    }

    printf("\n\t The sum of right diagonal of the given arr[%d][%d] : %d \n",N,M,sum);    
}

void largerElement_leftDiagonal(int **arr) {
    int larger = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (i == j) {
                if (larger == 0)    larger = arr[i][j];
                else if (arr[i][j] > larger) larger = arr[i][j];
            } 
        }
    }

    printf("\n\t The larger element from the left diagonal of the given arr[%d][%d] : %d \n",N,M,larger);
}

void smallerElement_leftDiagonal(int **arr) {
    int smaller = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (i == j) {
                if (smaller == 0)    smaller = arr[i][j];
                else if (arr[i][j] < smaller) smaller = arr[i][j];
            }
        }
    }
    
    printf("\n\t The smaller element from the left diagonal of the given arr[%d][%d] : %d \n",N,M,smaller);
}

void largerElement_rightDiagonal(int **arr) {
    int larger = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (j == M-(i+1)) {
                if (larger == 0)    larger = arr[i][j];
                else if (arr[i][j] > larger) larger = arr[i][j];
            } 
        }
    }

    printf("\n\t The larger element from the right diagonal of the given arr[%d][%d] : %d \n",N,M,larger);

}

void smallerElement_rightDiagonal(int **arr) {
    int smaller = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (j == M-(i+1)) {
                if (smaller == 0)    smaller = arr[i][j];
                else if (arr[i][j] < smaller) smaller = arr[i][j];
            }
        }
    }
    
    printf("\n\t The smaller element from the right diagonal of the given arr[%d][%d] : %d \n",N,M,smaller);
}

void sort_leftDiagonal(int **arr) {
    int temp;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (i == j) {
                for (int k = i+1 ; k < N ; k++) {
                    if (arr[i][j] > arr[k][k]) {
                        temp = arr[i][j];
                        arr[i][j] = arr[k][k];
                        arr[k][k] = temp;
                    }
                }
            }
        }
    }
    
    printf("\n\t After sorting left diagonals the new arr[%d][%d] : \n",N,M);
    display(arr);
}

void sort_rightDiagonal(int **arr) {
    int temp,l;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (j == M-(i+1)) {
                l = j-1;
                for (int k = i+1 ; k < N ; k++,l--) {
                    if (arr[i][j] > arr[k][l]) {
                        temp = arr[i][j];
                        arr[i][j] = arr[k][l];
                        arr[k][l] = temp;
                    }
                }
            }
        }
    }
    
    printf("\n\t After sorting right diagonals the new arr[%d][%d] : \n",N,M);
    display(arr);
}

