/*
    A-5 ->  write a C program to read and print the N student details using structure and Dynamic Memory Allocation.
            - create a structure with N number of student details and print the inputted details. 
	        - Memory to store and print structure will be allocated at run time by using malloc() and released by free().
*/

/* 
    Input ->    Student 1 name - kartik, roll no - 1, division - B, standard - 7th  
                Student name - chirag, roll no - 2, division - B, standard - 7th     
                Student name - soham, roll no - 3, division - B, standard - 7th                     
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
    char *name;
    int *roll_no;
    char *div;
    char *std;
} Student;

int main() 
{
    Student *p;
    p = malloc(sizeof(Student));

    int n;
    printf("\n\tEnter the number of students : ");
    scanf("%d", &n);    
    
    for (int i = 0; i < n; i++)
    {
        p -> name = malloc(sizeof(char)*20);
        p -> roll_no = malloc(sizeof(int));
        p -> div = malloc(sizeof(char)*2);
        p -> std = malloc(sizeof(char)*10);
        
        printf("\n\tGive the Student %d details : \n",i+1);

        if (p -> name == NULL)
        {
            printf("Memory Allocation Failed!");
        }
        else 
        {
            printf("\n\tEnter Student Name : ");
            scanf("%s",p -> name);
        }
        
        if (p -> roll_no == NULL)
        {
            printf("Memory Allocation Failed!");
        }
        else 
        {
            printf("\tEnter Student Roll No. : ");
            scanf("%d",&(p -> roll_no));
        }
        
        if (p -> div == NULL)
        {
            printf("Memory Allocation Failed!");
        }
        else 
        {
            printf("\tEnter Student Division : ");
            scanf("%s",p -> div);
        }

        if (p -> std == NULL)
        {
            printf("Memory Allocation Failed!");
        }
        else 
        {  
            printf("\tEnter Student Standard : ");
            scanf("%s",p -> std);
        }

        printf("\n\tStudent Name : %s", p -> name);
        printf("\tRoll No : %d", p -> roll_no);
        printf("\tDivision : %s", p -> div);
        printf("\tStandard : %s\n\n", p -> std);

        free(p -> name);
        p -> name = NULL;

        free(p -> roll_no);
        p -> roll_no = NULL;

        free(p -> div);
        p -> div = NULL;

        free(p -> std);
        p -> std = NULL;
    }
    

    free(p);
    
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
