/*
    A-1 ->  Accept a string and copy the string into another string without using the inbuilt copy function 
*/

/* 
    Input ->    string[] = "Marbello"                   
*/

#include<stdio.h>

int main() {
    char string[50];
    char newString[50];

    printf("\n\t Enter the string : ");
    scanf("%s",string);
    
    int i = 0;
    for ( ; string[i] != '\0'; i++) {
        newString[i] = string[i];
    }
    newString[i] = '\0';

    printf("\n\t The new string which is the copy of given string : %s \n\n",newString);

    return 0; 
}

/*
    Output ->     
                Enter the string : Marbello

                The new string which is the copy of given string : Marbello                             
*/