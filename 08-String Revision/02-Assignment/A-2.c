/*
    A-2 ->  Accept two strings and concatinate the contents into 3rd string
*/

#include<stdio.h>
#include<string.h>

int main() {
    char string1[50];
    char string2[50];
    char newstring[50];

    printf("\n\t Enter the first string  : ");
    fgets(string1,50,stdin);
    string1[strcspn(string1,"\n")] = '\0';
    printf("\n\t Enter the second string : ");
    fgets(string2,50,stdin);
    string2[strcspn(string2,"\n")] = '\0';

    strcpy(newstring,string1);
    strcat(newstring,string2);

    int i;
    for (i = 0 ; string1[i] != '\0' ; i++);
    for (int j = 0 ; string2[j] != '\0' ; j++,i++) {
        string1[i] = string2[j];
    }
    string1[i] = '\0';

    printf("\n\t The final concatenated string (using inbuilt function) : %s \n",newstring);
    printf("\n\t The final concatenated string : %s \n\n",string1);

    return 0;   
}
