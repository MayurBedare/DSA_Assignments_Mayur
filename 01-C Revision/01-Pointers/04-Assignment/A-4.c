/*

  write a  Program to count vowels and consonants in a string using pointer.

*/

/* 
    Input -> User given Eg. Mayur Bedare CSE
                             
*/

#include<stdio.h>
#include<ctype.h>

int main()
{
    char string[50];
    char *p = string;

    printf("Enter the string to count vowels and consonants :");
    fgets(p, 50, stdin);

    int count_v = 0;
    int count_c = 0;

    for (int i=0; *(p+i) != '\0' ; i++)
    {
        if (*(p+i) == ' ' || *(p+i) == '\n')
            continue;
        
        if(*(p+i) == 'a' || *(p+i) == 'e' || *(p+i) == 'i' || *(p+i) == 'o' || *(p+i) == 'u' 
            || *(p+i) == 'A' || *(p+i) == 'E' || *(p+i) == 'I' || *(p+i) == 'O' || *(p+i) == 'U')
        {
            count_v++;
        }
        else if (isalpha(*(p+i)))
        {
            count_c++;
        } 
    }

    printf("The total number of vowels in the given string : %d \n",count_v);
    printf("The total number of consonants in the given string : %d ",count_c);

	return 0;
}

/*
    Output -> 
                Enter the string to count vowels and consonants :Mayur Bedare CSE
                The total number of vowels in the given string : 6 
                The total number of consonants in the given string : 8                                 
*/