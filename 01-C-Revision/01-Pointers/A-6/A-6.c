/*
    A-6 -> Write a function which reads pointers of 2 different array as arguments, 
           return the pointer of array which elements are sum of  two array element.
*/

/*
    arr1[5] = {1,2,3,4,5}
    arr2[5] = {5,4,3,2,1}
*/

#include<stdio.h>

int* sumTwoArrays(int*,int*);

int main()
{
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {5,4,3,2,1};
    int *p;

    p = sumTwoArrays(arr1,arr2);

    printf("\n\tThe array with sum of two different arrays : \n\n"); 
    
    for (int i = 0; i < 5 ; i++)
    {
        printf("\tarr[%d] : %d\n",i,*(p+i));
    }

    return 0;
}

int* sumTwoArrays(int* arr1, int* arr2) 
{
    int *arr = arr1;

    for (int i = 0; i < 5 ; i++)
    {
        *(arr + i) = *(arr1 + i) + *(arr2 + i);
    }

    return arr;
}

/*
    Output ->       
                The array with sum of two different arrays : 

                arr[0] : 6
                arr[1] : 6
                arr[2] : 6
                arr[3] : 6
                arr[4] : 6                         
*/