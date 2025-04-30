/*
    A-6 ->  In C, tell the user to set a password, then ask them to re-enter the password for confirmation. Take password input in a character array, 
            compare the passwords and show a relevant message.
            Sample 1: 
            INPUT: 
            Soham@5643
            soham@5643
            OUTPUT: Password didn’t match! Please try again
            Sample 2: 
            INPUT: 
                    #include<CipherCoding>
                    #include>CipherCoding>
            OUTPUT: Password didn’t match! Please try again
            Sample 3: 
            INPUT: 
                    eru42*sj#tdd$sfsea@uiji
                    eru42*sj#tdd$sfsea@uiji
            OUTPUT: Password matched!
*/

#include<stdio.h>

int main() {
    char string1[50];
    char string2[50];

    printf("\n\t ***** Password Checker ***** \n");
    printf("\n\t Set the strong password : ");
    scanf("%s",string1);

    while (1) {
        int flag = 0;

        printf("\n\t Re-enter the password   : ");
        scanf("%s",string2);

        for (int c = 0 ; string1[c] != '\0' && string2[c] != '\0' ; c++) {
            if (string1[c] != string2[c]) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            printf("\n\t Password matched! \n\n");
            break;
        } else {
            printf("\n\t Password didn't match! Please try again \n");
            continue;
        }
    }

    return 0;   
}

/*
    Output ->                                
*/