/*
    A-8 ->  In C, take an email address as input from the user and validate the email, what an email should contain
            [‘@’, ‘.’, UPPER/LOWER case letters, numbers, underscore, dash]. @ and . should not be in starting of the email or at the very end; 
            it should be in between. An email can have only one ‘@’ sign but more than one ‘.’ sign but not consecutively like ‘..’, only one ‘.’ after ‘@’ sign should appear.
            Sample 1: 
            INPUT: 
                    sohamg.3456@gmail.com
            OUTPUT: 
                    Valid email
            Sample 2: 
            INPUT: 
                    .sohamg3456@gmail.com
            OUTPUT: 
                    Invalid email
            Sample 3: 
            INPUT: 
                    soh@mg.3456@.gmail.com
            OUTPUT: 
                    Invalid email
            Sample 4: 
            INPUT: 
                    sohamg..3456@gmail.
            OUTPUT: 
                    Invalid email
*/

#include<stdio.h>
#include<ctype.h>

int main() {
    char string[50];
    int flag = 0;

    printf("\n\t ***** Email-Id Checker ***** \n");

    while (1) {
        printf("\n\t Enter the Email Id : ");
        scanf("%s",string);
        
        int ch,i = 0;
        
        while (string[i] != '\0') {
            int cnt_at = 0;
            if (string[i] == '@' || string[i] == '.') {
                flag = 1;
                break;
            } 
            i++; 

            while (string[i+1] != '@') {
                if (string[i] == '.' || string[i] == '_' || string[i] == '-' || isalpha(string[i]) || isdigit(string[i])) {
                    i++;
                } else { 
                    flag = 1;
                    break;
                }
                if(string[i] == string[i+1] == '.') {
                    flag = 1;
                    break;
                }
            }
            if (string[i] == '.' || string[i] == '-' || string[i] == '_') {
                flag = 1;
                break;
            } 
            i = i + 2;

            if (string[i] == '.') {
                flag = 1;
                break;
            } else {
                i++;
            }
            
            int cnt = 0;
            while (string[i] != '\0') {
                if (string[i] == '@' && cnt_at == 0) {
                    cnt_at = 1;
                    flag = 1;
                    break;
                }
                if (string[i] == '.' && cnt == 0) {
                    cnt = 1;
                    i++;
                    continue;
                }
                i++;
            }
            if (string[i-1] == '.') {
                flag = 1;
                break;
            } 
        }

        if (!flag) {
            printf("\n\t Valid Email Id \n");
        } else {
            printf("\n\t Invalid Email Id! \n");
        }
        printf("\n\t Do you want to enter more Email Id's ( Yes(1) / No(0) ) : ");
        scanf("%d",&ch);
        if (ch) {
            flag = 0;
            continue;
        } 
        else {
            printf("\n\t Program Executed Successfully. \n\n");
            break;
        }
    }

    return 0;   
}