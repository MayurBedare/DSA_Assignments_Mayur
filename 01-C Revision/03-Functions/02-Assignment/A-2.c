/*
    A-2 ->  Write a function to find the length of a string.
*/

/* 
    Input ->    String[] -> "Simultaneous"                 
*/

#include<stdio.h>
#include<string.h>

int stringLength(char[]);

int main() {
    int len;
    char string[50];

    printf("\n\t Enter the string : ");
    scanf("%s",string);

    len = stringLength(string);

    printf("\n\t The length of the given string : %d \n\n",len);

    return 0;    
}

int stringLength(char string[]) {   
    int sum = 0;
    for (int i = 0 ; string[i] != '\0' ; i++) {
        sum++;
    }
    return sum;
}

/*
    Output -> 
                Enter the string : Simultaneous

                The length of the given string : 12                               
*/