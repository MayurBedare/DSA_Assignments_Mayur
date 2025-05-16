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
#include<string.h>

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
    if (nw == NULL)
    {
        printf("Memory Allocation Failed!");
        exit(1);
    }

    printf("\n\tEnter the Student name : ");
    fgets(nw -> std_name,20,stdin);
    nw -> std_name[strcspn(nw -> std_name,"\n")] = '\0';
    printf("\n\tEnter the Student rollno : ");
    scanf("%d", &(nw -> std_rollNo));
    printf("\n\tEnter the Student standard : ");
    getchar();
    fgets(nw -> std_standard,10,stdin);
    nw -> std_standard[strcspn(nw -> std_standard,"\n")] = '\0';
    printf("\n\tEnter the Student division : ");
    fgets(nw -> std_div,10,stdin);
    nw -> std_div[strcspn(nw -> std_div,"\n")] = '\0';

    printf("\n\tnw --> |_%s_|_%d_|_%s_|_%s_|",nw -> std_name, nw -> std_rollNo, nw -> std_standard, nw -> std_div);

    free(nw);
    nw = NULL;
    
    return 0;
}

/*
    Output ->    
                nw --> |_Mayur_|_21_|_Graduate_|_Dequeue_|                       
*/