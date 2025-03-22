/*
    A-7 -> Write a Program to read and print student details using structure pointer.
*/

/*
    Student / p --> |_Soham_|_3_|_B_|_7th_|
*/

#include<stdio.h>

typedef struct Student
{
    char name[20];
    int roll_no;
    char div[2];
    char std[10];
} Student;

int main()
{
    Student *p;
    
    printf("\n\tEnter Student Name : ");
    scanf("%s", p -> name);
    printf("\n\tEnter Student Roll No. : ");
    scanf("%d", &(p -> roll_no));
    printf("\n\tEnter Student Division : ");
    scanf("%s", p -> div);
    printf("\n\tEnter Student Standard : ");
    scanf("%s", p -> std);

    printf("\n\tStudent Name \t\t: %s", p -> name);
    printf("\n\tStudent Roll No. \t: %d", p -> roll_no);
    printf("\n\tStudent Division \t: %s", p -> div);
    printf("\n\tStudent Standard \t: %s\n\n", p -> std);

    return 0;
}

/*
    Output ->
                Enter Student Name : Soham

                Enter Student Roll No. : 3

                Enter Student Division : B

                Enter Student Standard : 7th

                Student Name            : Soham
                Student Roll No.        : 3
                Student Division        : B
                Student Standard        : 7th                                
*/