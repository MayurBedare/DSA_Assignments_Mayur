/*
    A-6 ->  Accept n elements in an array and revert the array
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int i = 0;
    int size = 1;
    int *arr = NULL;
    arr = (int*)malloc(sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Note -> Enter arr[last] : -1 to exit \n");
    printf("\n\t Enter the elements of arr[n] one by one : \n");

    while (1) {
        printf("\n\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);

        if (arr[i] == -1) {
            size--;
            break;
        }   

        size++;
        arr = (int*)realloc(arr,(size)*sizeof(int));
        if (arr == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        i++;
    }

    int *revert = NULL;
    revert = (int*)malloc(size*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    printf("\n\t The given array arr[%d] : \n",size);
    int j = size-1;
    for (int i = 0 ; i < size ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
        revert[i] = arr[j--];
    }

    printf("\n\n\t The given array after reverting arr[%d] : \n",size);
    for (int i = 0 ; i < size ; i++) {
        if (i == 0) printf("\n\t |_%d_|",revert[i]);
        else    printf("_%d_|",revert[i]);
    }
    printf("\n\n");

    free(arr);
    arr = NULL;
     
    free(revert);
    revert = NULL;

    return 0;   
}