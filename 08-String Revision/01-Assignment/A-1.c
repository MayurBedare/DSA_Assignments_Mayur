/*
    A-1 ->  Accept a string and copy the string into another string without using the inbuilt copy function 
*/

#include<stdio.h>
#include<string.h>

int main() {
    char string[50];
    char newString[50];
    char newstring2[50];

    printf("\n\t Enter the string : ");
    fgets(string,50,stdin);
    string[strcspn(string,"\n")] = '\0';
    
    int i = 0;
    for ( ; string[i] != '\0'; i++) {
        newString[i] = string[i];
    }
    newString[i] = '\0';

    strcpy(newstring2,string);

    printf("\n\t The new string which is the copy of given string (using inbuilt function) : %s \n",newstring2);
    printf("\n\t The new string which is the copy of given string : %s \n\n",newString);

    return 0; 
}