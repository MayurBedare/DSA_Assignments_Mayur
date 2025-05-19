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
    char dob[15];
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

    printf("\n\t Enter Person's Name : ");
    fgets(nw.name,20,stdin);
    nw.name[strcspn(nw.name,"\n")] = '\0';

    printf("\n\t Enter Person's Age : ");
    scanf("%d", &nw.age);
    getchar();
    
    printf("\n\t Enter Person's Date Of Birth (DD/MM/YYYY) : ");
    fgets(nw.dob,15,stdin);
    nw.dob[strcspn(nw.dob,"\n")] = '\0';

    printf("\n\t Enter Person's Blood Group : ");
    fgets(nw.bg,5,stdin);
    nw.bg[strcspn(nw.bg,"\n")] = '\0';

    printf("\n\t Enter Person as an Employee Company Name : ");
    fgets(nw.E.c_name,10,stdin);
    nw.E.c_name[strcspn(nw.E.c_name,"\n")] = '\0';

    printf("\n\t Enter Person's Employee Id : ");
    scanf("%d",&nw.E.id);

    printf("\n\t Enter Person's Employee Salary (INR) : ");
    scanf("%d",&nw.E.salary);

    printf("\n\t Enter Person's Employee (Years) : ");
    scanf("%d",&nw.E.expr);

    printf("\n\t Person's Details : ");
    printf("\n\n\t Person Name : %s",nw.name);
    printf("\n\t Person Age : %d",nw.age);
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
                Enter Person's Name : Mayur Bedare

                Enter Person's Age : 22

                Enter Person's Date Of Birth (DD/MM/YYYY) : 26/06/2003

                Enter Person's Blood Group : B+

                Enter Person as an Employee Company Name : MediClick

                Enter Person's Employee Id : 4341

                Enter Person's Employee Salary (INR) : 50000

                Enter Person's Employee (Years) : 2

                Person's Details :

                Person Name : Mayur Bedare
                Person Age : 22
                Person Date Of Birth (DD/MM/YYYY) : 26/06/2003
                Person Blood Group : B+

                Person as an Employee's Details :

                Employee Company Name : MediClick
                Employee Id : 4341
                Employee Salary(INR) : 50000
                Employee Experience(Years) : 2                         
*/