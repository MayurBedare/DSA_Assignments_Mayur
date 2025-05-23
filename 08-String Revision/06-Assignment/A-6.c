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
#include<string.h>

int main() {
    char string1[50];
    char string2[50];

    printf("\n\t ***** Password Checker ***** \n");
    printf("\n\t Set the strong password : ");
    fgets(string1,50,stdin);
    string1[strcspn(string1,"\n")] = '\0';

    while (1) {
        int flag = 0,ch;

        printf("\n\t Re-enter the password   : ");
        fgets(string2,50,stdin);
        string2[strcspn(string2,"\n")] = '\0';

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
            printf("\n\t Do you want to attempt one more chance ( Yes(1) / No(0) ) : ");
            scanf("%d",&ch);
            getchar();
            if (ch) {
                continue;
            } 
            else {
                printf("\n\t Program Executed Successfully. \n\n");
                break;
            }
        }
    }

    return 0;   
}
