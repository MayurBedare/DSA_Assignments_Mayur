/*
    A-5 ->  In C, we want to take the FULL name as input and make sure that the 1st letter of the first, middle, and last name is capitalized and the rest are in small,
            if not, then make it in that format and also check if there are any numbers or special characters in the name, if there then print invalid name.
            Sample 1: 
            INPUT: sOhaM YashWANT gaDeKaR
            OUTPUT: Soham Yashwant Gadekar
            Sample 2: 
            INPUT: sOhaM Y@shWANT gaDeKaR3
            OUTPUT: Invalid name
            Sample 3: 
            INPUT: sOhaM
            OUTPUT: Enter your FULL name! FIRST MIDDLE LAST
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int fullName(char[],int);
int upper(char*,int);

int main() {
    char string[50];
    int flag = 0;

    printf("\n\t ***** Checking Full Name (First Middle Last) with first letter as capital and Invalid Name ***** \n");
    while(1) {
        int ch;
        printf("\n\t ------------------");
        printf("\n\t 1. Check the Name ");
        printf("\n\t 2. Exit ");
        printf("\n\t ------------------");
        printf("\n\t Enter you choice : ");
        scanf("%d",&ch);
        printf("\t ------------------\n");

        switch (ch) {
            case 1:
                flag = fullName(string,flag);
                if (flag) {
                    printf("\n\t Invalid Full Name!\n");
                    break;
                }
                break;
            
            case 2:
                exit(0);

            default: 
                printf("\n\t Invalid Choice Entered! \n");
                break;
        } 
    }

    return 0;   
}

int fullName(char string[50],int flag) {
    flag = 0;
    int space_no = 0;

    printf("\n\t Enter the string : ");
    getchar();
    fgets(string,50,stdin);
    string[strcspn(string,"\n")] = '\0';

    int c = 0;
    while (string[c] != '\0') {
        if (!c) { 
            flag = upper(&string[c],flag);
            if (flag)   return flag;  
            c++;
        }

        while ((!isspace(string[c])) && string[c] != '\0') {
            if (isalpha(string[c])) {
                if (!islower(string[c])) {
                    string[c] = tolower(string[c]);
                } 
            } else {
                flag = 1;
                return flag;
            }
            c++;
        }

        if (isspace(string[c])) {
            space_no++;
            c++;
        }

        if (string[c]) {
            flag = upper(&string[c],flag);
            if (flag)   return flag;
            c++;
        }
    }

    if (space_no != 2) {
        printf("\n\t Enter your FULL name! FIRST MIDDLE LAST \n");
        return flag;
    }

    printf("\n\t The Full Name given with / without changes including \n\t first letter of each name in capital letters : \n");
    printf("\n\t %s \n ",string);

    return flag;
}

int upper(char *c,int flag) {
    if (isalpha(*c)) {
        if(!isupper(*c)) {
            *c = toupper(*c);
        } 
    } else {
        flag = 1;
    }

    return flag;
}