/*
    A-4 ->  Write a function to concatenate  two strings 
*/

/* 
    Input ->    string1[] = "Hello"
                string2[] = "World!"        
*/

#include<stdio.h>

void strconcat(char[],char[]);

int main() {
    char string1[50];
    char string2[50];

    printf("\n\t Enter the first string  : ");
    scanf("%s",string1);
    printf("\n\t Enter the second string : ");
    scanf("%s",string2);

    strconcat(string1,string2);

    printf("\n\t The final concatenated string : %s \n\n",string1);

    return 0;   
}

void strconcat(char string1[],char string2[]) {
    int i;
    for (i = 0 ; string1[i] != '\0' ; i++);
    for (int j = 0 ; string2[j] != '\0' ; j++,i++) {
        string1[i] = string2[j];
    }
    string1[i] = '\0';
}

/*
    Output ->    
                Enter the first string  : Hello

                Enter the second string : World!

                The final concatenated string : HelloWorld!                            
*/