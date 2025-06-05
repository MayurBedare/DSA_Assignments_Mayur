/*
    A-2 ->  Accept a  number 'N' and Count the number of digits in the number using recursion
*/

#include<stdio.h>

int digit_cnt(int,int);

int main() {
    printf("\n\t ***** Counting No. of digits in the given Number ***** \n");

    int n,cnt = 0;
    printf("\n\t Enter the number to find no. of digits : ");
    scanf("%d",&n);

    n = digit_cnt(n,cnt);

    printf("\n\t No. of digits present in the given Number : %d \n\n",n);

    return 0;   
}

int digit_cnt(int n,int cnt) {
    if (n == 0) return cnt;
    else    digit_cnt(n/10,++cnt);
}



