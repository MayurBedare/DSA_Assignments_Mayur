/*
    A-7 ->  Accept n elements in an array and search a perticular element  
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int i = 0,key,size = 1,flag = 0;
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

    printf("\n\t Enter the Key/Value ie. particular array element to serach : ");
    scanf("%d",&key);

    printf("\n\t In the given arr[%d] : \n",size);
    for (int i = 0 ; i < size ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
        
        if (arr[i] == key)  flag = 1;
    }

    if (flag)   printf("\n\n\t Key %d found.\n\n",key);
    else    printf("\n\n\t Key %d not found!\n\n",key);

    free(arr);
    arr = NULL;

    return 0;   
}
