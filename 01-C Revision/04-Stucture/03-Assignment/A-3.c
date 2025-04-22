/*
    A-3 ->  Write a c program which demonstrate a nested structure 
            - define a structure employee inside a structure person.
            - structure person data: 
                                Name, Age, Date of birth, blood group.
            - structure employee data:
                                Company name, Emp id, salary, years of experiance.
                                
            - create objects of structure and display the all details of a person. 
*/

#include<stdio.h>
#include<string.h>

typedef struct person
{
    char name[20];
    int age;
    char dob[10];
    char bg[5];
    struct employee
    {
        char c_name[10];
        int id;
        int salary;
        int expr;
    } E;  
} P;


int main() {
    P nw;

    strcpy(nw.name,"Mayur Bedare");
    nw.age = 22;
    strcpy(nw.dob,"26/06/2003");
    strcpy(nw.bg,"B+");
    strcpy(nw.E.c_name,"MediClick");
    nw.E.id = 4341;
    nw.E.salary = 50000;
    nw.E.expr = 2;

    printf("\n\t Person's Details : ");
    printf("\n\n\t Person Name : %s",nw.name);
    printf("\n\t Person Age(Years) : %d",nw.age);
    printf("\n\t Person Date Of Birth (DD/MM/YYYY) : %s",nw.dob);
    printf("\n\t Person Blood Group : %s",nw.bg);
    printf("\n\n\t Person as an Employee's Details : ");
    printf("\n\n\t Employee Company Name : %s",nw.E.c_name);
    printf("\n\t Employee Id : %d",nw.E.id);
    printf("\n\t Employee Salary(INR) : %d",nw.E.salary);
    printf("\n\t Employee Experience(Years) : %d\n\n",nw.E.expr);

    return 0;   
}

/*
    Output ->      
                Person's Details : 

                Person Name : Mayur Bedare
                Person Age(Years) : 22
                Person Date Of Birth (DD/MM/YYYY) : 26/06/2003B+
                Person Blood Group : B+

                Person as an Employee's Details : 

                Employee Company Name : MediClick
                Employee Id : 4341
                Employee Salary(INR) : 50000
                Employee Experience(Years) : 2                          
*/