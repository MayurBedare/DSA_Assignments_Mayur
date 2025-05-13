/*
    A-3 ->  write a C program to read a one dimensional array, print sum of all elements along with inputted array 
            elements using Dynamic Memory Allocation.
            - allocate memory for one dimensional array and print the array elements along with sum of all elements. 
            - Memory will be allocated in this program using malloc() and released using free().
*/

/* 
    Input ->  arr[5] = {1,2,3,4,5}                      
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int *p = NULL;
    int sum = 0;
    p = (int*)malloc(sizeof(int)*5);
    if (p == NULL)
    {
        printf("\n\tMemory is not Allocated!");
        exit(1);
    }

    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\tEnter arr[%d]: ",i);
        scanf("%d",p + i);
        sum = sum + *(p + i);
    }

    printf("\n\tThe sum of given array : %d\n\n", sum);

    free(p);
    p = NULL;
    
    return 0;
}

/*
    Output ->        
                Enter arr[0]: 1
                Enter arr[1]: 2
                Enter arr[2]: 3
                Enter arr[3]: 4
                Enter arr[4]: 5

                The sum of given array : 15                        
*/