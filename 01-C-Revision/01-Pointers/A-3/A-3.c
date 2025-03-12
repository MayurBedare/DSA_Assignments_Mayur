/*

   write a Program to read array elements and print with addresses.

*/

/* 
    Input -> 
                arr : {1,2,3,4,5}             
*/

#include<stdio.h>

int main()
{
   int arr[5];
   
   for (int i=0 ; i<5 ; i++)
   {
        printf("Enter array element arr[%d] : ",i);
        scanf("%d",&arr[i]);    
   }
   
   for (int i=0 ; i<5 ; i++)
   {
    printf("The array element arr[%d] : %d \t",i,arr[i]);
    printf("The address of arr[%d] : %p \n",i,&arr[i]);     
   }

	return 0;
}

/*
    Output -> 
               Enter array element arr[0] : 1
               Enter array element arr[1] : 2
               Enter array element arr[2] : 3
               Enter array element arr[3] : 4
               Enter array element arr[4] : 5
               The array element arr[0] : 1    The address of arr[0] : 0061FF04 
               The array element arr[1] : 2    The address of arr[1] : 0061FF08
               The array element arr[2] : 3    The address of arr[2] : 0061FF0C
               The array element arr[3] : 4    The address of arr[3] : 0061FF10
               The array element arr[4] : 5    The address of arr[4] : 0061FF14                
*/