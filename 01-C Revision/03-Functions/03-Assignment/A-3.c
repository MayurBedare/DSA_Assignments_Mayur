/*
    A-3 ->  Write a separate function to copy one string into another string 
*/

/* 
    Input ->    string[] = "Marbello"                   
*/

#include<stdio.h>

void strcopy(char[],char[]);

int main() {
    char string[50];
    char newString[50];

    printf("\n\t Enter the string : ");
    scanf("%s",string);
    
    strcopy(newString,string);

    printf("\n\t The new string which is the copy of given string : %s \n\n",newString);

    return 0; 
}

void strcopy(char newString[],char string[]) {
    int i;
    for (i = 0 ; string[i] != '\0'; i++) {
        newString[i] = string[i];
    }
    newString[i] = '\0';
}

/*
    Output ->     
                Enter the string : Marbello

                The new string which is the copy of given string : Marbello                             
*/