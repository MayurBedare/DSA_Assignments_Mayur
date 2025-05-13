/*
    A-2 ->  write a C program to input and print text using Dynamic Memory Allocation.
            - create memory for text string at run time using malloc() function, 
            - text string will be inputted by the user and displayed.
            - Using free() function  release the occupied memory.
*/

/* 
    Input ->    text string : MERN Stack Developer               
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *text_string = NULL;

    //Memory created
    text_string = (char*)malloc(sizeof(char)*50);
    if (text_string == NULL)
    {
        printf("\n\tMemory Allocated Failed!");
        exit(1);
    }
    
    //Input text string
    printf("\n\tEnter the text string : ");
    fgets(text_string, 50, stdin);
    //Print text string
    printf("\n\tThe given text string : %s\n", text_string);
   
    //Freed Memory
    free(text_string);
    text_string = NULL;

    return 0;
}

/*
    Output ->    
                Enter the text string : MERN Stack Developer 

                The given text string : MERN Stack Developer                            
*/