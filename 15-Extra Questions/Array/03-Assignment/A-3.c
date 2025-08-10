//  A-3 ->  Given an array of integers find the first repeating element in the array

#include<stdio.h>
#include<stdlib.h>

int main() {
    int element = 0,arr2L = 0;
    int n;
    printf("\n\t Enter the value of n : ");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    if (!arr) {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }
    
    printf("\n\t Enter the values of array : ");
    for (int i = 0 ; i < n ; i++)   scanf("%d",&arr[i]);
    
    int *arr2 = (int*)malloc(sizeof(int));
    if (arr2 == NULL) {
        printf("\n\t Memory Allocation Failed!\n\n");
        return 1;
    }
    arr[arr2L++];

    for (int i = 1 ; i < n ; i++) {
        for (int k = 0 ; k < arr2L ; k++) {
            if (arr[k] == arr[i]) {
                element = arr[i];
                break;
            }
        }
        if (element == 0) {
            arr2 = realloc(arr2,sizeof(int)*(arr2L+1));
            if (arr2 == NULL) {
                printf("Memory Allocation Failed! \n\n");
            }
            arr2[arr2L++] = arr[i];
        }
    }

    if (element) {
        printf("\n\t The first repeating element : %d \n\n",element);
    } else {
        printf("\n\t Their doesn't exist any first repeated element! \n\n");
    }

    free(arr);
    arr = NULL;
    free(arr2);
    arr2 = NULL;
    
    return 0;
}