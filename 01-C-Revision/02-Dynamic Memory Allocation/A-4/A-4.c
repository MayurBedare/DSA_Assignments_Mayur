/*
    A-4 ->  write a C program to read and print the student details using structure and Dynamic Memory Allocation.
            - create a structure with student details and print the inputted details. 
            - Memory to store and print structure will be allocated at run time by using malloc() and released by free().
*/

/* 
    Input -> Student name - Soham, roll no - 3, division - B, standard - 7th                    
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
    char *name;
    int *roll_no;
    char *div;
    char *std;
} Student;

int main() 
{
    Student *p;
    p = malloc(sizeof(Student));

    p -> name = malloc(sizeof(char)*20);
    p -> roll_no = malloc(sizeof(int));
    p -> div = malloc(sizeof(char)*2);
    p -> std = malloc(sizeof(char)*10);
    
    if (p -> name == NULL)
    {
        printf("Memory Allocation Failed!");
    }
    else 
    {
        printf("\n\tEnter Student Name : ");
        scanf("%s",p -> name);;
    }
    
    if (p -> roll_no == NULL)
    {
        printf("Memory Allocation Failed!");
    }
    else 
    {
        printf("\tEnter Student Roll No. : ");
        scanf("%d",&(p -> roll_no));
    }
    
    if (p -> div == NULL)
    {
        printf("Memory Allocation Failed!");
    }
    else 
    {
        printf("\tEnter Student Division : ");
        scanf("%s",p -> div);
    }

    if (p -> std == NULL)
    {
        printf("Memory Allocation Failed!");
    }
    else 
    {  
        printf("\tEnter Student Standard : ");
        scanf("%s",p -> std);
    }

    printf("\n\tStudent Name : %s", p -> name);
    printf("\tRoll No : %d", p -> roll_no);
    printf("\tDivision : %s", p -> div);
    printf("\tStandard : %s\n\n", p -> std);

    free(p -> name);
    p -> name = NULL;

    free(p -> roll_no);
    p -> roll_no = NULL;

    free(p -> div);
    p -> div = NULL;

    free(p -> std);
    p -> std = NULL;

    free(p);
    
    return 0;
}

/*
    Output ->      
                Enter Student Name : Soham
                Enter Student Roll No. : 3 
                Enter Student Division : B
                Enter Student Standard : 7th

                Student Name : Soham    Roll No : 3     Division : B    Standard : 7th                          
*/