/*
    A-13 -> write C program to find the HCF (Highest Common Factor) of a numbers using recursion 
*/

#include<stdio.h>
#include<stdlib.h>

int factors(int**,int,int,int);
int prime_or_not(int,int);
int function();

int main() {
    printf("\n\t ***** Finding GCD of the numbers using Recursion ***** \n");

    int n,i = 0,n1;
    printf("\n\t Enter the no. of elements to be entered to find HCF : ");
    scanf("%d",&n);
    n1 = n;

    int **arr = NULL;
    arr = (int**)malloc(n*sizeof(int*));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    int *factor_size = NULL;
    factor_size = (int*)malloc(n*sizeof(int));
    if (factor_size == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

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

        if (i == 0) common_factor_length = factor_size[i];
        if (factor_size[i] < common_factor_length) {
            common_factor_length = factor_size[i];
        }
 
        i++,n--;
    }

    int gcd = 1,flag = 0,same = 0;
    while (i != 0) {
        if (factor_size[n] != factor_size[n+1]) {
            flag = 1;
            break;
        }
        n++,i--;
    }
    if (flag == 0) {
        while (common_factor_length != 0) {
            while (n != 0) {
                if (arr[i][common_factor_length] != arr[++i][common_factor_length]) {
                    same = 1;
                    break;
                }
                n--;
            }
            if (same == 0) {
                gcd *= arr[0][common_factor_length];
            }
            common_factor_length--;
            n = n1,i = 0,same = 0;
        }
    } else {
        for (int a = 0; a < common_factor_length; a++) {
        int factor = arr[0][a];  
        int is_common = 1; 

        for (int b = 1; b < n1; b++) {
            int found = 0;
            for (int k = 0; k < factor_size[b]; k++) {
                if (arr[b][k] == factor) {
                    arr[b][k] = 0;  
                    found = 1;
                    break;
                }
            }
            if (!found) {
                is_common = 0;  
                break;
            }
        }

        if (is_common) {
            gcd *= factor;
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

    free(factor_size);
    factor_size = NULL;

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



