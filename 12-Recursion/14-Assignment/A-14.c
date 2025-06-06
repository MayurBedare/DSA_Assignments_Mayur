/*
    A-14 -> write C program to find the LCM (Lowest Common Multiple) of given numbers using recursion 
*/

#include<stdio.h>
#include<stdlib.h>

int lcm(int[],int[],int);
int common_multiple(int[],int,int,int,int);

int main() {
    printf("\n\t ***** Finding the LCM of the given numbers ***** \n");

    int n;
    printf("\n\t Enter the number of elements to be entered to find LCM : ");
    scanf("%d",&n);

    int *arr = NULL,LCM;
    arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    int *elements = NULL;
    elements = (int*)malloc(n*sizeof(int));
    if (elements == NULL) {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }

    for (int j = 0 ; j < n ; j++) {
        printf("\n\t Enter the element %d : ",j+1);
        scanf("%d",&arr[j]);
        elements[j] = arr[j];
    }

    LCM = lcm(arr,elements,n);

    printf("\n\t The LCM of the given numbers : %d \n\n",LCM);

    if (arr != NULL && elements != NULL) {
        free(arr);
        arr = NULL;
        free(elements);
        elements = NULL;
    }

    return 0;   
}

int lcm(int arr[],int elements[],int n) {
    int flag = 0,no;

    for (int i = 0 ; i < n ; i++) {
        arr[i] = common_multiple(elements,elements[i],arr[i]/elements[i],arr[i],n);
        if (i == 0) no = arr[i];
        if (no == arr[i]) {
            flag++;
        }
    }

    if (flag == n) {
        return no;
    } else {
        lcm(arr,elements,n);
    }
}

int common_multiple(int elements[],int no,int multiple,int nw_no,int n) {
    int flag = 0;

    for (int i = 0 ; i < n ; i++) {
        if (nw_no%elements[i] == 0)  flag++;
    }

    if (flag == n) {
        return nw_no;
    } else {
        common_multiple(elements,no,++multiple,no*multiple,n);
    }
}



