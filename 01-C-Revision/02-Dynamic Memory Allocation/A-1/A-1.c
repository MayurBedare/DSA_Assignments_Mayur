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

    if (x_i == NULL) {
        printf("\n\tMemory allocation failed for integer variable");
    }
    else {
        printf("\n\tMemory allocated successful for interger variable");
        free(x_i);
        x_i = NULL;
    }
    
    if (x_c == NULL) {
        printf("\n\tMemory allocated failed for character variable");
    }
    else {
        printf("\n\tMemory allocation successful for character variable");
        free(x_c);
        x_c = NULL;
    }

    if (x_f == NULL) {
        printf("\n\tMemory allocation failed for float variable");
    }
    else {
        printf("\n\tMemory allocation successful for float variable\n\n");
        free(x_f);
        x_f = NULL;
    }   
    
    return 0;
}

/*
    Output ->  
                Memory is allocated for interger variable
                Memory is allocated for character variable
                Memory is allocated for float variable                              
*/