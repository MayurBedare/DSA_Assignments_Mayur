/*
    A-6 ->  Accept elements in n*m matrix and display its saddle point 
            (sadle point : the element which is the highest in the row and at the same time lowest in the column )
*/

#include<stdio.h>
#include<stdlib.h>

void saddlePoint();

int main() {
    printf("\n\t ***** Checking Saddle Point in n*m matrix ***** \n");

    while (1) {
        int ch;
        printf("\n\t ----------------------------------------");
        printf("\n\t 1. Check the saddle point in n*m matrix ");
        printf("\n\t 2. Exit ");
        printf("\n\t ----------------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t ---------------------------------------- \n");

        switch (ch) {
            case 1:
                saddlePoint();
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

void saddlePoint() {
    int N,M,size = 1;
    printf("\n\t Enter the no. of rows and columns of arr / matrix : ");
    scanf("%d %d",&N,&M);

    int **arr = NULL;

    arr = (int**)malloc(N*sizeof(int*));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter the elements in an arr[%d][%d] : \n",N,M);
    for (int i = 0 ; i < N ; i++) {
        arr[i] = (int*)malloc(M*sizeof(int));
        if (arr[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
    
        for (int j = 0 ; j < M ; j++) {
            if (j == 0) printf("\n");
            printf("\t Enter arr[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]); 
        }
    }

    printf("\n\t The given arr[%d][%d] : \n",N,M);
    
    int **saddlePoint = NULL;

    for (int i = 0 ; i < N ; i++) {
        int max = arr[i][0];

        for (int j = 0 ; j < M ; j++) {
            if (j == 0) printf("\n\t |_%d_|",arr[i][j]);
            else    printf("_%d_|",arr[i][j]);

            if (j != 0 && arr[i][j] > max) {
                max = arr[i][j];
            }
        }

        for (int m = 0 ; m < M ; m++) {
            int max_row = -1;
            if (arr[i][m] == max) {
                max_row = m;
            }

            if (max_row != -1) {
                int min = arr[0][max_row],min_col = i;

                for (int k = 1 ; k < N ; k++) {
                    if (arr[k][max_row] < min) {
                        min = arr[k][max_row];
                        min_col = k;
                    } 
                }
                
                if (max == min) {
                    // saddlePoint[x][0] for saddlePoint , saddlePiont[x][1] for saddlePoint row , saddlePiont[x][2] for saddlePoint column
                    if (saddlePoint == NULL) {
                        saddlePoint = (int**)malloc(sizeof(int*));
                        if (saddlePoint == NULL) {
                            printf("\n\t Memory Allocation Failed! \n\n");
                            exit(1);
                        }
                        *saddlePoint = (int*)malloc(3*sizeof(int));
                        if (*saddlePoint == NULL) {
                            printf("\n\t Memory Allocation Failed! \n\n");
                            exit(1);
                        }
                    } else {
                        size++;
                        saddlePoint = (int**)realloc(saddlePoint,(size)*sizeof(int*));
                        if (saddlePoint == NULL) {
                            printf("\n\t Memory Allocation Failed! \n\n");
                            exit(1);
                        }
                        saddlePoint[size-1] = (int*)malloc(3*sizeof(int));
                        if (saddlePoint[size-1] == NULL) {
                            printf("\n\t Memory Allocation Failed! \n\n");
                            exit(1);
                        }
                    }
                    saddlePoint[size-1][0] = max;
                    saddlePoint[size-1][1] = min_col;
                    saddlePoint[size-1][2] = max_row;
                }
            }
        }
    }
    printf("\n");

    if (saddlePoint != NULL) {
        printf("\n\t Their exist %d Saddle Point in the given arr[%d][%d] : \n",size,N,M);
        if (size == 1) {
            printf("\n\t ******************************************************");
            printf("\n\t Saddle Point : %d \n",saddlePoint[size-1][0]);
            printf("\n\t | The position of Saddle Point is row*column ie. %d*%d | ",saddlePoint[size-1][1],saddlePoint[size-1][2]);
            printf("\n\t ****************************************************** \n");
        } else {
            for (int n = 1 ; n <= size ; n++) {
                printf("\n\t ********************************************************");
                printf("\n\t Saddle Point %d : %d ",n,saddlePoint[n-1][0]);
                printf("\n\t | The position of Saddle Point %d is row*column ie. %d*%d | ",n,saddlePoint[n-1][1],saddlePoint[n-1][2]); 
                if (n == size)  printf("\n\t ******************************************************** \n");
            }

            if (N*M == size) {
                printf("\n\t | All elements in the given arr[%d][%d] are the same. Every element is a saddle point | \n",N,M);
            }
        }
    } else {
        printf("\n\t Their does not exist any Saddle Point in the given arr[%d][%d] : \n",N,M);
        printf("\n\t ********************************************************************************************************");
        printf("\n\t | The Saddle Point is an element which is highest in the row and at the same time lowest in the column | ");
        printf("\n\t ******************************************************************************************************** \n");
    }

    if (arr != NULL && saddlePoint != NULL) {
        for (int k = 0,j = 0 ; k < N ; k++,j++) {
            free(arr[k]);
            if (j < size)  free(saddlePoint[k]);
        }
        free(arr);
        arr = NULL;
        free(saddlePoint);
        saddlePoint = NULL;
    }
}

