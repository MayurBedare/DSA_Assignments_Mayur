/*
    A-5 ->  Write a function to reverse the  strings
*/

/* 
    Input ->    string[] = "EngineeR"                  
*/

#include<stdio.h>

void reverse(char[],char[]);

int main() {

    char string[50];
    char reverseString[50];

    printf("\n\t Enter the string : ");
    scanf("%s",string);

    reverse(reverseString,string);

    printf("\n\t Reverse of the given string : %s \n\n",reverseString);

    return 0;
    
}

void reverse(char reverseString[], char string[]) {
    int i,j;
    for (i = 0 ; string[i] != '\0' ; i++);
    for (i--,j = 0 ; i != -1 ; i--,j++) {
        reverseString[j] = string[i];
    }
    reverseString[j] = '\0';
}

/*
    Output ->   
                Enter the string : EngineeR

                Reverse of the given string : ReenignE                             
*/