/*
    A-1 -> write a c program to create and display a node. with structure "Student" with following data members:   
            -Name 
            -Roll no
            -standard
            -Division
*/

/* 
    Input -> |_Mayur_|_21_|_Graduate_|_Dequeue_|                     
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
    char std_name[20];
    int std_rollNo;
    char std_standard[10];
    char std_div[10];
} Student;

int main()
{
    Student *nw;

    nw = (Student*)malloc(sizeof(Student));
    printf("Enter the Student name : ");
    scanf("%s", &nw -> std_name);
    printf("Enter the Student rollno : ");
    scanf("%d", &nw -> std_rollNo);
    printf("Enter the Student standard : ");
    scanf("%s", &nw -> std_standard);
    printf("Enter the Student division : ");
    scanf("%s", &nw -> std_div);

    printf("%s %d %s %s",nw -> std_name, nw -> std_rollNo, nw -> std_standard, nw -> std_div);

    return 0;
}

/*
    Output ->                                
*/