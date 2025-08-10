/*
    Q-3 ->  Accept two strings and compare the content of those string
*/

#include<stdio.h>

int main() {
    char string1[50];
    char string2[50];

    printf("\n\t Enter the first string  : ");
    scanf("%s",string1);
    printf("\n\t Enter the second string : ");
    scanf("%s",string2);

    int i = 0,cmp;
    for ( ; string1[i] != '\0' && string2[i] != '\0' ; i++) {
        if (string1[i] == string2[i]) {
            cmp = 0;
            continue;
        } else {
            cmp = 1;
        }
        if (string1[i] < string2[i]) {
            cmp = (int)(string1[i] - string2[i]);
            break;
        }
        if (string1[i] > string2[i]) {
            cmp = (int)(string1[i] - string2[i]);
            break;
        }
    }

    if (cmp == 0) {
        printf("\n\t The given two strings are equal.\n\n");
    } else {
        printf("\n\t The given two strings are not equal.\n\n");
    }

    return 0;   
}

/*
    Output 1 -> 
                Enter the first string  : HappyBirthday

                Enter the second string : HappyBirthday

                The given two strings are equal.                              
*/

/*
    Output 2 -> 
                Enter the first string  : HappyBirthday

                Enter the second string : HappBirthday

                The given two strings are not equal.                               
*/