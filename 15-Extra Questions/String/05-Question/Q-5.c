/*
    Q-5 ->  Accept string and check whether the string is palindrome or not 
*/

#include<stdio.h>

int main() {
    char string[50];
    char newString[50];

    printf("\n\t Enter the string : ");
    scanf("%s",string); 

    int i = 0,flag = 0, size;
    for ( ; string[i] != '\0' ; i++);
    size = i;
    for (int j = 0 ; j != size/2 ; j++) {
        if (string[j] == string[--i]) {
            flag = 1;
        } else {
            flag = 0;
            break;
        } 
    } 

    if (flag == 1) {
        printf("\n\t The given string is Palindrome.\n\n");
    } else {
        printf("\n\t The given string is not Palindrome.\n\n");
    }

    return 0;   
}

/*
    Output 1 -> 
                Enter the string : malayalam

                The given string is Palindrome.                              
*/

/*
    Output 2 -> 
                Enter the string : marathi

                The given string is not Palindrome.                               
*/