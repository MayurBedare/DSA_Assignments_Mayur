/*
    A-2 ->  write a C program to read and print an employee's detail using structure.
            - read and print the employee's details like name, employee id, salary etc using structure.
*/

/* 
    Input ->    Employee name : Mayur Bedare , id : 4341 , salary : 50000 , role : Software Developer                      
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Employee
{
    char name[20];
    int id;
    int salary;
    char role[30];
} Emp;

int main() {

    Emp *p = (Emp*)malloc(sizeof(Emp));
    if (p == NULL) {
        printf("\n\t Memory Allocation Failed!");
        exit(1);
    }

    printf("\n\t Enter the Employee's Details : \n");
    printf("\n\t Enter Employee Name : ");
    fgets(p -> name,20,stdin);
    p -> name[strcspn(p -> name, "\n")] = '\0';

    printf("\n\t Enter Employee Id : ");
    scanf("%d",&(p -> id));

    printf("\n\t Enter Employee Salary : ");
    scanf("%d",&(p -> salary));

    printf("\n\t Enter Employee role : ");
    getchar();
    fgets(p -> role,30,stdin);
    p -> role[strcspn(p -> role, "\n")] = '\0';

    printf("\n\n\t Employee's Details : ");
    printf("\n\t Employee Name : %s",p -> name);
    printf("\n\t Employee Id : %d",p -> id);
    printf("\n\t Employee Salary : %d",p -> salary);
    printf("\n\t Employee role : %s\n\n",p -> role);

    free(p);
    p = NULL;
    
    return 0;   
}

/*
    Output -> 
                Enter the Employee's Details : 

                Enter Employee Name : Mayur Bedare

                Enter Employee Id : 4341

                Enter Employee Salary : 50000

                Enter Employee role : Software Developer


                Employee's Details : 
                Employee Name : Mayur Bedare
                Employee Id : 4341
                Employee Salary : 50000
                Employee role : Software Developer                               
*/