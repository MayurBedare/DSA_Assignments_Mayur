/*
    A-9 ->  accept n elements in  2D - array and perform 90 degree right rotaion and 90 degree left rotation (rotate N elements (N is an user input)) .  
            (Allocate the (N x M) 2D - array dynamically) 
*/

#include<stdio.h>
#include<stdlib.h>

void leftRotation(int**,int**,int**,int,int);
void rightRotation(int**,int**,int**,int,int);
void display(int**,int,int);

int main() {
    printf("\n\t ***** N times 90 Degree Left / Right Rotation on 2D arr[n][m] ***** \n");

    int N,M;
    printf("\n\t Enter the no. of rows and columns of array / matrix : ");
    scanf("%d %d",&N,&M);

    int **arr = NULL,**rotate = NULL,**buffer = NULL;
    arr = (int**)malloc(N*sizeof(int*));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    rotate = (int**)malloc(N*sizeof(int*));
    if (rotate == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    buffer = (int**)malloc(N*sizeof(int*));
    if (buffer == NULL) {
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
        rotate[i] = (int*)malloc(M*sizeof(int));
        if (rotate[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        buffer[i] = (int*)malloc(M*sizeof(int));
        if (buffer[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
    
        for (int j = 0 ; j < M ; j++) {
            if (j == 0) printf("\n");
            printf("\t Enter arr[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]); 

            buffer[i][j] = arr[i][j];
        }
    }

    while (1) {
        int ch;
        printf("\n\t ----------------------------------------");
        printf("\n\t 1. N times 90 Degree Left Rotation ");
        printf("\n\t 2. N times 90 Degree Right Rotation ");
        printf("\n\t 3. Exit ");
        printf("\n\t ----------------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t ---------------------------------------- \n");

        switch (ch) {
            case 1:
                leftRotation(arr,buffer,rotate,N,M);
                break;

            case 2:
                rightRotation(arr,buffer,rotate,N,M);
                break;

            case 3:
                printf("\n\t Program Exited Successfully! \n\n");
                exit(0);
            
            default:
                printf("\n\t Invalid Choice Entered! \n");
                break;
        }
    }

    if (arr != NULL && buffer != NULL && rotate != NULL) {
        for (int i = 0 ; i < N ; i++) {
            free(arr[i]);
            free(buffer[i]);
            free(rotate[i]);
        }
        free(arr);
        arr = NULL;
        free(buffer);
        buffer = NULL;
        free(rotate);
        rotate = NULL;
    }

    return 0;   
}

void leftRotation(int **arr,int **buffer,int **rotate,int n,int m) {
    int n_rotate,h;
    printf("\n\t Enter the no. of times to rotate the given arr[%d][%d] : ",n,m);
    scanf("%d",&n_rotate);
    h = n_rotate;

    while (n_rotate != 0) {
        int k = m-1;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                rotate[i][j] = buffer[j][k];
            }
            k--;
        }

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (n_rotate - 1 != 0)  buffer[i][j] = rotate[i][j];
                else    buffer[i][j] = arr[i][j];
            }
        }

        n_rotate--;
    }

    printf("\n\t The given arr[%d][%d] : \n",n,m);
    display(arr,n,m);

    printf("\n\n\t After rotating the given arr[%d][%d] %d times ie. %d Degree Left : \n",n,m,h,90*h);
    display(rotate,n,m);
}

void rightRotation(int **arr,int **buffer,int **rotate,int n,int m) {
    int n_rotate,h;
    printf("\n\t Enter the no. of times to rotate the given arr[%d][%d] : ",n,m);
    scanf("%d",&n_rotate);
    h = n_rotate;

    while (n_rotate != 0) {
        int k = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                rotate[i][j] = buffer[m-1-j][k];
            }
            k++;
        }

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (n_rotate - 1 != 0)  buffer[i][j] = rotate[i][j];
                else    buffer[i][j] = arr[i][j];
            }
        }

        n_rotate--;
    }

    printf("\n\t The given arr[%d][%d] : \n",n,m);
    display(arr,n,m);

    printf("\n\n\t After rotating the given arr[%d][%d] %d times ie. %d Degree Right : \n",n,m,h,90*h);
    display(rotate,n,m);
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

