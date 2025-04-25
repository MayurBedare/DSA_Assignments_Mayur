/*
    Q-4 ->  Accept a string and reverse the content of string 
*/

/* 
    Input ->    string[] = "EngineeR"                  
*/

#include<stdio.h>

int main() {

    char string[50];
    char reverseString[50];

    printf("\n\t Enter the string : ");
    scanf("%s",string);

    int i,j;
    for (i = 0 ; string[i] != '\0' ; i++);
    for (i--,j = 0 ; i != -1 ; i--,j++) {
        reverseString[j] = string[i];
    }
    reverseString[j] = '\0';

    printf("\n\t Reverse of the given string : %s \n\n",reverseString);

    return 0;
    
}

/*
    Output ->   
                Enter the string : EngineeR

                Reverse of the given string : ReenignE                             
*/