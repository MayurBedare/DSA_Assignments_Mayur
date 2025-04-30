/*
    A-4 ->  In C, we want to take input of a person’s name in a character string, but it only stores the first name, and after a space it doesn’t store anything!

            (i) Why does this happen?
            (ii) How can this issue be solved with an explanation?
            (iii) Explore all the options ex- scanf(),gets(),fgets()   and write functions for each appraoch 
            INPUT: Soham Yashwant Gadekar
            OUTPUT: Soham
            INPUT: Soham Yashwant Gadekar
            OUTPUT: Soham Yashwant Gadekar
*/

/*
    (i) -> Whenever we store person's name in a character string it depends on what function we are using to store that character string.
    (ii) -> * If we use scanf() it stores the stdin until "tab,whitespace or newline" occurs , that is reason why only the character string stores person's first name only
              and rest character string after space will be in the input buffer along with newline so to remove that clear_buffer logic needs to be implemented.
            * If we use gets() it is somehow dangerous to use which stores the stdin until newline character occurs irrespective of character string size ,
              even though it stores whitespaces but it also indepenet on size of string which causes input buffer overloading.
              - It removes newline character and replaces with '\0'.
            * If we use fgets() which is preferrable to use in these case which stores the stdin from user as per size bounds given in its syntax until newline comes, 
              and to remove newline character strcspn logic need to be implemented
*/

// (iii) ->

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void approach1_scanf(char[]);
void approach2_gets(char[]);
void approach3_fgets(char[]);

int main() {
    char string[50];

    printf("\n\t ***** Approach of String input for spaces ***** \n");
    while (1) {
        int ch;
        printf("\n\t ------------------");
        printf("\n\t 1. scanf approach ");
        printf("\n\t 2. gets approach ");
        printf("\n\t 3. fgets approach ");
        printf("\n\t 4. Exit ");
        printf("\n\t ------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        getchar();// to clear newline character
        printf("\t ------------------\n");

        switch (ch) {
            case 1:
                approach1_scanf(string);
                break;
            
            case 2: 
                approach2_gets(string);
                break;
            
            case 3: 
                approach3_fgets(string);
                break;
            
            case 4: 
                exit(0);
            
            default: 
                printf("\n\t Invalid Choice Entered! \n");
                break;
        }
    }

    return 0;   
}

void approach1_scanf(char string[50]) {
    printf("\n\t Enter the string : ");
    scanf("%s",string);
    int ch;
    while ((ch = getchar()) != '\n');// ch is used to get each character present in input buffer which is
// not part of the string after space inclustion and getchar() consumes them with newline character at the end

    printf("\n\t The given string : %s \n",string);
}

void approach2_gets(char string[50]) {
    printf("\n\t Enter the string : ");
    gets(string); // it removes newline character on its own

    printf("\n\t The given string : %s \n",string);
}

void approach3_fgets(char string[50]) {
    printf("\n\t Enter the string : ");
    fgets(string,50,stdin);
    string[strcspn(string,"\n")] = '\0';//removing new line character

    printf("\n\t The given string : %s \n",string);
}

                                 
