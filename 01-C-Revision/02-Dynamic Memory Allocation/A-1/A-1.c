/*
    A-1 ->  write a C program to create memory for int, char and float variable at run time.
            - create memory for int, char and float variables at run time using malloc() function
            - and before exiting the program release the memory allocated at run time by using free() function.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *x_i;
    char *x_c;
    float *x_f;
    
    x_i = malloc(sizeof(int));
    x_c = malloc(sizeof(char));
    x_f = malloc(sizeof(float));

    if (sizeof(*(x_i)) != sizeof(int)) {
        printf("\n\tMemory is not allocated for integer variable");
    }
    else {
        printf("\n\tMemory is allocated for interger variable");
        free(x_i);
    }
    
    if (sizeof(*(x_c)) != sizeof(char)) {
        printf("\n\tMemory is not allocated for character variable");
    }
    else {
        printf("\n\tMemory is allocated for character variable");
        free(x_c);
    }

    if (sizeof(*(x_f)) != sizeof(float)) {
        printf("\n\tMemory is not allocated for float variable");
    }
    else {
        printf("\n\tMemory is allocated for float variable\n\n");
        free(x_f);
    }   
    
    return 0;
}

/*
    Output ->  
                Memory is allocated for interger variable
                Memory is allocated for character variable
                Memory is allocated for float variable                              
*/