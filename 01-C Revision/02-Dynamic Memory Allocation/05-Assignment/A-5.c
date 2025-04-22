/*
    A-5 ->  write a C program to read and print the N student details using structure and Dynamic Memory Allocation.
            - create a structure with N number of student details and print the inputted details. 
	        - Memory to store and print structure will be allocated at run time by using malloc() and released by free().
*/

/* 
    Input ->    Student 1 name - kartik, roll no - 1, division - B, standard - 7th  
                Student 2 name - chirag, roll no - 2, division - B, standard - 7th     
                Student 3 name - soham, roll no - 3, division - B, standard - 7th                     
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
    int n;
    printf("\n\tEnter the number of students : ");
    scanf("%d", &n);    
    
    for (int i = 0; i < n; i++)
    {
        Student *p = NULL;
        p = malloc(sizeof(Student));
        if (p == NULL) {
            printf("\n\t Memory Allocation Failed!");
            exit(1);
        }
        
        printf("\n\tGive the Student %d details : \n",i+1);

        printf("\n\tEnter Student Name : ");
        getchar();
        fgets(p -> name,20,stdin);
        p -> name[strcspn(p -> name,"\n")] = '\0';
    
        printf("\tEnter Student Roll No. : ");
        scanf("%d",&(p -> roll_no));
        
        printf("\tEnter Student Division : ");
        scanf("%s",p -> div);

        printf("\tEnter Student Standard : ");
        scanf("%s",p -> std);

        printf("\n\tStudent Name : %s", p -> name);
        printf("\tRoll No : %d", p -> roll_no);
        printf("\tDivision : %s", p -> div);
        printf("\tStandard : %s\n\n", p -> std);

        free(p);
        p = NULL;
    }
    
    return 0;
}


/*
    Output -> 
                Enter the number of students : 3

                Give the Student 1 details : 

                Enter Student Name : kartik
                Enter Student Roll No. : 1
                Enter Student Division : B
                Enter Student Standard : 7th

                Student Name : kartik   Roll No : 1     Division : B    Standard : 7th


                Give the Student 2 details : 

                Enter Student Name : chirag
                Enter Student Roll No. : 2
                Enter Student Division : B
                Enter Student Standard : 7th

                Student Name : chirag   Roll No : 2     Division : B    Standard : 7th


                Give the Student 3 details :

                Enter Student Name : soham
                Enter Student Roll No. : 3
                Enter Student Division : B
                Enter Student Standard : 7th

                Student Name : soham    Roll No : 3     Division : B    Standard : 7th                               
*/
