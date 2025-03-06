/* 

    Write a Program to swap elements between two array using pointers.

*/

/* 
    Input -> 
                arr1 : {1,2,3,4,5}  
                arr2 : {6,7,8,9,0}           
*/

#include<stdio.h>

int main()
{
	int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,0};

    int *p1 = arr1;
    int *p2 = arr2;

    int *temp;

    temp = p1;
    p1 = p2;
    p2 = temp;


    for (int i=0; i<=4 ; i++)
    {
        printf("arr1[%d] is %d\t",i,*(p1+i));
        printf("arr2[%d] is %d\n",i,*(p2+i));
    }
	
	return 0;
}  

/*
    Output -> 
                arr1[0] is 6    arr2[0] is 1
                arr1[1] is 7    arr2[1] is 2
                arr1[2] is 8    arr2[2] is 3
                arr1[3] is 9    arr2[3] is 4
                arr1[4] is 0    arr2[4] is 5
*/