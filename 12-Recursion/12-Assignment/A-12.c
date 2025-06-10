/*
    A-12 ->  accept two numbers and find the GCD of the numbers  using recursion
*/

#include<stdio.h>
#include<stdlib.h>

int factors(int**,int,int,int);
int prime_or_not(int,int);

int main() {
    printf("\n\t ***** Finding GCD of the numbers using Recursion ***** \n");

    int n = 2,i = 0;

    int **arr = NULL;
    arr = (int**)malloc(n*sizeof(int*));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    int factor_size[2];

    int common_factor_length = 1;

    while (n != 0) {
        int j = 0;
        arr[i] = (int*)malloc(sizeof(int));
        if (arr[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        
        printf("\n\t Enter the Element %d : ",i+1);
        scanf("%d",&arr[i][j]);
        
        factor_size[i] = factors(arr,i,j,arr[i][j]);

        if (factor_size[i] > common_factor_length) {
            common_factor_length = factor_size[i];
        }

        i++,n--;
    }

    int gcd = 1;
    if (factor_size[0] == factor_size[1]) {
        for (int x = 0 ; x < common_factor_length ; x++) {
            if (arr[0][x] == arr[1][x]) {
                gcd *= arr[0][x];
            }
        } 
    } else {
        int temp;
        if (factor_size[0] > factor_size[1]) {
            temp = factor_size[0];
            factor_size[0] = factor_size[1];
            factor_size[1] = temp;
        }
        for (int x = 0 ; x < factor_size[0] ; x++) {
            for (int y = 0 ; y < factor_size[1] ; y++) {
                if (arr[0][x] == arr[1][y]) {
                    gcd *= arr[0][x];
                    arr[1][y] = 0;
                    break;
                }
            }
        }
    }

    printf("\n\t The GCD of the given numbers : %d \n\n",gcd);

    if (arr != NULL) {
        for (int f = 0 ; f < i ; f++) {
            free(arr[f]);
        }
        free(arr);
        arr = NULL;
    }

    return 0;   
}

int factors(int **arr,int i,int j,int n) {
    if (prime_or_not(n,2)) {
        if (j != 0) {
            arr[i] = realloc(arr[i],(j+1)*sizeof(int));
            if (arr[i] == NULL) {
                printf("\n\t Memory Allocation Failed! \n\n");                
                exit(1);
            }
        } 
        arr[i][j] = n;
        return j+1;
    }
    if (n == 1) return j;

    int m;
    for (m = 2 ; m < 9 ; m++) {
        if (n % m == 0 && n == m && j == 0) {
            arr[i][j] = m;
            return j+1;
        } else if (n % m == 0) {
            if (j == 0) {
                arr[i][j] = m;
            } else {
                arr[i] = realloc(arr[i],(j+1)*sizeof(int));
                if (arr[i] == NULL) {
                    printf("\n\t Memory Allocation Failed! \n\n");                
                    exit(1);
                }
            }
            arr[i][j] = m;
            j++;
            break;
        } 
    }

    factors(arr,i,j,n/m);
}

int prime_or_not(int n,int m) {
    if (n == 1) return 0;
    
    if (n%m == 0 && m != n) { return 0; }
    else if (m == n) { return 1; }
    else { prime_or_not(n,++m); }   
}


