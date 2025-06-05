/*
    A-11 -> accept a string and calculate the length of string  using recursion 
*/

#include<stdio.h>
#include<string.h>

int stringLength(char[],int);

int main() {
    printf("\n\t ***** Calculating Length of the given String using Recursion ***** \n");

    char string[30],len;
    printf("\n\t Enter the string to find the lenght : ");
    fgets(string,30,stdin);
    string[strcspn(string,"\n")] = '\0';

    len = stringLength(string,0);

    printf("\n\t The length of the given string : %d \n\n",len);

    return 0;   
}

int stringLength(char string[],int m) {
    if (string[m] == '\0')  return m;
    else    stringLength(string,++m);
}

