/*

    Write a Program to print a string using pointer.
  
*/

/*
    p
    |
    v
    +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
    | S | o | f | t | w | a | r | e |   | D | e | v | e | l | o | p | e | r | \0|
    +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17   18
*/

#include<stdio.h>

int main()
{
    char string[] = "Software Developer";

    char *p = string;

    for (int i=0; i<sizeof(string)-1 ; i++)
    {
        printf("%c",*(p+i));
    }

	return 0;
}

/*
    Output -> 
                Software Developer
*/