/*
    A-12 ->  accept two numbers and find the GCD of the numbers  using recursion
*/

#include<stdio.h>
#include<stdlib.h>

int factors(int**,int,int,int);
int gcd(int**,int,int,int,int[],int);

int main() {
    printf("\n\t ***** Finding GCD of the numbers using Recursion ***** \n");

    int n = 2,i = 0;

    int **arr = NULL;
    arr = (int**)malloc(n*sizeof(int*));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    int common_factor_length = 1,common_factor_index = 0;

    while (n != 0) {
        int j = 0;
        arr[i] = (int*)malloc(sizeof(int));
        if (arr[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        
        printf("\n\t Enter the Element %d : ",i+1);
        scanf("%d",&arr[i][j]);

        int c_f;
        c_f = factors(arr,i,j,arr[i][j]);

        if (c_f < common_factor_length) {
            common_factor_length = c_f;
            common_factor_index = i;
        }

        i++,n--;
    }

    int *common_factor = NULL;
    common_factor = malloc(common_factor_length*sizeof(int));
    if (common_factor == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");                
        exit(1);
    }

    n = gcd(arr,i-1,common_factor_index,common_factor_length+1,common_factor,0);

    if (n == 1) {
        printf("\n\t The GCD of the given numbers : %d \n\n",common_factor[0]);
    } else {
        int largest = common_factor[0];
        for (int u = 1 ; u < n ; u++) {
            if (common_factor[u] > largest) {
                largest = common_factor[u];
            }
        }

        printf("\n\t The GCD of the given numbers : %d \n\n",largest);
    }

    if (arr != NULL) {
        for (int f = 0 ; f < i ; f++) {
            free(arr[f]);
        }
        free(arr);
        arr = NULL;
    }

    free(common_factor);
    common_factor = NULL;

    return 0;   
}

int factors(int **arr,int i,int j,int n) {
    if (arr[i][j] == 1) return j+1;
    
    if (arr[i][0] % n == 0) {
        arr[i] = realloc(arr[i],(j+2)*sizeof(int));
        if (arr[i] == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");                
            exit(1);
        }

        arr[i][++j] = n;
    }

    factors(arr,i,j,--n);
}

int gcd(int **arr,int n,int i,int j,int common_factor[],int t) {
    if (j == 0)    return t;

    int flag = 0;
    for (int h = 0 ; h < n+1 ; h++) {
        for (int f = 1 ; h != i && arr[h][f-1] != 1 ; f++) {
            if (arr[i][j] == arr[h][f]) {
                flag++;
                break;
            }
        }
    }

    if (flag == n) {
        common_factor[t++] = arr[i][j];
    }

    gcd(arr,n,i,--j,common_factor,t);
}
