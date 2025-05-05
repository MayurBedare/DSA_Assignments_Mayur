/*
    A-9 ->  In C, check if a password is strong enough, some conditions are : 
            Password Strength Conditions:
                1. Must be at least 8 characters long
                2. Must contain at least one uppercase letter
                3. Must contain at least one lowercase letter
                4. Must contain at least one digit (0–9)
                5. Must contain at least one special character (e.g. @, #, $, %, &, *, etc.)
                6. Must not contain any spaces
            Sample 1:
                    INPUT:
                            Soham@5643
                    OUTPUT:
                            Strong password!
            Sample 2:
                    INPUT:
                            soham5643
                    OUTPUT:
                            Weak password! missing uppercase and special character
            Sample 3:
                    INPUT:
                        Soham 5643
                    OUTPUT:
                        Weak password! contains space
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    char string[50];

    printf("\n\t ***** Strong Password Checker ***** \n");

    while (1) {
        int valid[6] = {0},flag = 0,ch;

        printf("\n\t Enter the password : ");
        fgets(string,50,stdin);
        string[strcspn(string,"\n")] = '\0';

        for (int i = 0 ; string[i] != '\0' ; i++) {
            if (i == 8) valid[0] = 1;
            if (isupper(string[i])) valid[1] = 1;
            if (islower(string[i])) valid[2] = 1;
            if (isdigit(string[i])) valid[3] = 1;
            if (string[i] == '!' || string[i] == '@' || string[i] == '#' || string[i] == '$' || string[i] == '%' || 
                string[i] == '^' || string[i] == '&' || string[i] == '*' || string[i] == '_' || string[i] == '-')
                valid[4] = 1;
            if (isspace(string[i])) valid[5] = 1; 
        }    
    
        for (int i = 0 ; i < 5 ; i++) {
            if (valid[i] == 0) {
                if (i == 0) printf("\n\t Password must be at least 8 characters long!");
                if (i == 1) printf("\n\t Missing Uppercase letter , must contains at least 1 letter!");
                if (i == 2) printf("\n\t Missing Lowercase letter , must contains at least 1 letter!");
                if (i == 3) printf("\n\t Missing Digit , must contains at least 1 digit!");
                if (i == 4) printf("\n\t Missign Special character , must contains at least 1 special character!");
                flag = 1;
            } 
        }
    
        if (valid[5] == 1) {
            printf("\n\t Contains space!");
            flag = 1;
        }
    
        if(!flag) {
            printf("\n\t Strong Password!\n");
        } else {
            printf("\n\n\t Weak password! \n");
        }

        printf("\n\t Do you want to enter more password to check ( Yes(1) / No(0) ) : ");
        scanf("%d",&ch);
        if (ch) {
            getchar();
            continue;
        } 
        else {
            printf("\n\t Program Executed Successfully. \n\n");
            break;
        }
    }

    return 0;   
}
