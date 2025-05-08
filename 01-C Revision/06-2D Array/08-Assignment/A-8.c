/*
    A-8 ->  Accept  4*4 matrix and display the following patern
    
            * 1 1 1
            0 * 1 1
            0 0 * 1
            0 0 0 *  
*/

#include<stdio.h>

#define N 4

int main() {
    int arr[N][N];

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (j == 0) printf("\n\t");

            if (j > i)  printf("1 ");

            if (j == i) printf("* ");
            
            if (j < i)    printf("0 ");
        }
    }
    printf("\n\n");

    return 0;   
}

