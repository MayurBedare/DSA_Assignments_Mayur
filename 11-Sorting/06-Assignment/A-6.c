/*
    A-6 -> Write a C program to Accept an array and Perform Radix sort.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 8

int power(int,int);
void display(int[]);

int main() {
    printf("\n\t ***** Radix Sort : Sorting ***** \n");

    printf("\n\t ------------------------------------------------------------ ");
    printf("\n\t The Time Complexity of the Radix Sort [worst cases] : O(nxk) \n");
    printf("\t ------------------------------------------------------------ \n");

    int digit,t = 1;

    printf("\n\t Enter the maximum digit number to be entered in an arr[%d] : ",SIZE);
    scanf("%d",&digit);

    int *arr = NULL;
    arr = (int*)malloc(SIZE*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    printf("\n\t Enter elements of arr[%d] one by one : \n\n",SIZE);

    for (int i = 0 ; i < SIZE ; i++) {
        printf("\t Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    printf("\n\t The given arr[%d] : \n",SIZE);
    display(arr);
    printf("\n");

    while (digit != 0) {

        int **temp = NULL;
        temp = (int**)malloc(10*sizeof(int*));
        if (temp == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }
        for (int i = 0 ; i < 10 ; i++) {
            temp[i] = NULL;
        }

        int *size = NULL;
        size = (int*)calloc(10,sizeof(int));
        if (size == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        int x;
        
        for (int i = 0 ; i < SIZE ; i++) {
            x = arr[i] % power(10,t);
            if (t > 1) {
                x = x / power(10,t-1);
            } 
            if (temp[x] == NULL) {
                temp[x] = (int*)malloc(sizeof(int));
                if (temp[x] == NULL) {
                    printf("\n\t Memory Allocation Failed! \n\n");
                    exit(1);
                }
            } else {
                temp[x] = (int*)realloc(temp[x],(size[x]+1)*sizeof(int));
                if (temp[x] == NULL) {
                    printf("\n\t Memory Allocation Failed! \n\n");
                    exit(1);
                }
            }
            temp[x][size[x]] = arr[i];
            size[x]++;
        }
        t++;

        int m = 0,n = 0;
        while (n < 10 && m < SIZE) {
            if (temp[n] != NULL && size[n] > 0) {
                if (size[n] == 1) {
                    arr[m++] = temp[n++][0];
                } else {
                    int l = 0,k = n;
                    while (size[k] != 0) {
                        arr[m++] = temp[k][l++];
                        size[k]--;
                    }
                    n++;
                }
            } else {
                n++;
            }
        }

        for (int i = 0 ; i < 10 ; i++) {
            free(temp[i]);
        }
        free(temp);
        temp = NULL;

        free(size);
        size = NULL;

        digit--;
        
    }

    printf("\n\t The given arr[%d] after Sorting : \n",SIZE);
    display(arr);
    printf("\n\n");
    
    free(arr);
    arr = NULL;
    
    return 0;
}

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

void display(int arr[]) {
    for (int i = 0 ; i < SIZE ; i++) {
        if (i == 0) printf("\n\t |_%d_|",arr[i]);
        else    printf("_%d_|",arr[i]);
    }
}