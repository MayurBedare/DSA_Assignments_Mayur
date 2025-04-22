/*
    A-5 -> write Program to print addresses and size of all types of pointer variables.
*/

#include<stdio.h>

int main()
{
    //Integer Pointer
    int i = 10;
    int *i_p = &i;

    //Character Pointer
    char c = 'a';
    char *c_p = &c;

    //Float Pointer
    float f = 1.5;
    float *f_p = &f;

    //Double Pointer
    double d = 12.56;
    double *d_p = &d;

    printf("\tAddress of Integer Pointer \t: %p\tSize of Integer Pointer \t: %d\n",i_p,sizeof(i_p));
    printf("\tAddress of Character Pointer \t: %p\tSize of Character Pointer \t: %d\n",c_p,sizeof(c_p));
    printf("\tAddress of Float Pointer \t: %p\tSize of Float Pointer \t\t: %d\n",f_p,sizeof(f_p));
    printf("\tAddress of Double Pointer \t: %p\tSize of Double Pointer \t\t: %d\n",d_p,sizeof(d_p));

    return 0;
}

/*
    Output ->   
                Address of Integer Pointer      : 0061FF0C      Size of Integer Pointer         : 4
                Address of Character Pointer    : 0061FF0B      Size of Character Pointer       : 4
                Address of Float Pointer        : 0061FF04      Size of Float Pointer           : 4
                Address of Double Pointer       : 0061FEF8      Size of Double Pointer          : 4                             
*/