/*
    A-1 ->  write a C program to create, declare and initialize structure.
            - define a structure "student", which includes the details of students,
            - declare an object of the structure and initialize the structure members.
*/

/* 
    Input ->    Student name - soham, roll no - 1, division - B, standard - 7th                      
*/

#include<stdio.h>
#include<string.h>

typedef struct Student
{
    char name[20];
    int roll_no;
    char div[3];
    char std[10];
} S;

int main() {

    S nw;

    printf("\n\t Enter Student Name : ");
    fgets(nw.name,20,stdin);
    nw.name[strcspn(nw.name,"\n")] = '\0';

    printf("\n\t Enter Student Roll No : ");
    scanf("%d", &nw.roll_no);
    getchar();

    printf("\n\t Enter Student Division : ");
    fgets(nw.div,3,stdin);
    nw.div[strcspn(nw.div,"\n")] = '\0';  

    printf("\n\t Enter Student Standard : ");      
    fgets(nw.std,10,stdin);
    nw.std[strcspn(nw.std,"\n")] = '\0';
    
    printf("\n\t Student Details :");
    printf("\n\t Student Name : %s",nw.name);
    printf("\n\t Student Roll No : %d",nw.roll_no);
    printf("\n\t Student Division : %s",nw.div);
    printf("\n\t Student Standard : %s\n\n",nw.std);

    return 0;   
}

/*
    Output ->
                Enter Student Name : soham

                Enter Student Roll No : 3

                Enter Student Division : B

                Enter Student Standard : 7th

                Student Details :
                Student Name : soham
                Student Roll No : 3
                Student Division : B
                Student Standard : 7th                               
*/