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
    char div[2];
    char std[10];
} S;

int main() {

    S nw;

    strcpy(nw.name,"soham");
    nw.roll_no = 3;
    strcpy(nw.div,"B");
    strcpy(nw.std,"7th");

    printf("\n\t Student Details :");
    printf("\n\t Student Name : %s",nw.name);
    printf("\n\t Student Roll No : %d",nw.roll_no);
    printf("\n\t Student Division : %s",nw.div);
    printf("\n\t Student Standard : %s\n\n",nw.std);

    return 0;   
}

/*
    Output ->
                Student Details :
                Student Name : soham
                Student Roll No : 3
                Student Division : B
                Student Standard : 7th                                
*/