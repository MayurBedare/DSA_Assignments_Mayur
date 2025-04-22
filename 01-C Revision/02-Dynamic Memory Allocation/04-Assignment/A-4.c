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
#include<string.h>

typedef struct Student
{
    char name[20];
    int roll_no;
    char div[2];
    char std[10];
} Student;

int main() 
{
    Student *p = NULL;
    p = malloc(sizeof(Student));
    if (p == NULL) {
        printf("Memory Allocation Failed!");
        exit(1);
    }
    
    printf("\n\t Enter Student Name : ");
    fgets(p -> name,20,stdin);
    p -> name[strcspn(p -> name,"\n")] = '\0';

    printf("\t Enter Student Roll No. : ");
    scanf("%d",&(p -> roll_no));

    printf("\t Enter Student Division : ");
    scanf("%s",p -> div);

    printf("\t Enter Student Standard : ");
    scanf("%s",p -> std);

    printf("\n\tStudent Name : %s", p -> name);
    printf("\tRoll No : %d", p -> roll_no);
    printf("\tDivision : %s", p -> div);
    printf("\tStandard : %s\n\n", p -> std);

    free(p);
    p = NULL; 
    
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