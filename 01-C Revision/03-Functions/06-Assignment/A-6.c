/*
    A-6 ->  write a  C program to pass an array of structures to a user define function
            - create a structure which accepts student details.
            - create an array of structure for "N" number of students.
            - Pass  array  of structure to a function as an argument and search for the perticular student details. 
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

void studentDetails(Student*,int);

int main() 
{
    int n;
    printf("\n\tEnter the number of students : ");
    scanf("%d", &n); 
    
    Student *arr = malloc(sizeof(Student)*n); // *arr same as arr[]
    if (arr == NULL) {
        printf("Memory Allocation Failed!");
        exit(1);
    }

    for (int i = 0 ; i < n ; i++)
    {   
        printf("\n\tGive the Student %d details : \n",i+1);

        printf("\n\tEnter Student Name : ");
        getchar();
        fgets((arr + i) -> name,20,stdin);
        (arr + i) -> name[strcspn((arr + i) -> name,"\n")] = '\0';
    
        printf("\tEnter Student Roll No. : ");
        scanf("%d",&((arr + i) -> roll_no));
        
        printf("\tEnter Student Division : ");
        scanf("%s",(arr + i) -> div);

        printf("\tEnter Student Standard : ");
        scanf("%s",(arr + i) -> std);
    }

    studentDetails(arr,n);

    free(arr);
    arr = NULL;

    return 0;
}

void studentDetails(Student *arr,int n) {
    int num,ch = 1,i;
    while (ch) {
        printf("\n\t Enter the roll no. to get particular student details : ");
        scanf("%d",&num);

        for (i = 0 ; (arr + i) -> roll_no != num && i < n ; i++);
            if ((arr + i) -> roll_no == num) {
            printf("\n\t Student details : ");
            printf("\n\t Student Name : %s", (arr + i) -> name);
            printf("\tRoll No : %d", (arr + i) -> roll_no);
            printf("\tDivision : %s", (arr + i) -> div);
            printf("\tStandard : %s\n", (arr + i) -> std);
    
            printf("\n\t Do you want to search more records ( Yes (1) / No (0) ) : ");
            scanf("%d",&ch);

            if (ch == 1) continue;
            else    break;
            } else {
                printf("\n\t Invalid Number Entered!\n");
                continue;
            }
    }
}

/*
    Output ->         
                Enter the number of students : 3

                Give the Student 1 details : 

                Enter Student Name : kartik
                Enter Student Roll No. : 1
                Enter Student Division : B
                Enter Student Standard : 7th

                Give the Student 2 details : 

                Enter Student Name : chirag
                Enter Student Roll No. : 2
                Enter Student Division : B
                Enter Student Standard : 7th

                Give the Student 3 details : 

                Enter Student Name : soham
                Enter Student Roll No. : 3
                Enter Student Division : B
                Enter Student Standard : 7th

                Enter the roll no. to get particular student details : 2

                Student details :
                Student Name : chirag  Roll No : 2     Division : B    Standard : 7th

                Do you want to search more records ( Yes (1) / No (0) ) : 1

                Enter the roll no. to get particular student details : 1

                Student details :
                Student Name : kartik  Roll No : 1     Division : B    Standard : 7th

                Do you want to search more records ( Yes (1) / No (0) ) : 1

                Enter the roll no. to get particular student details : 3

                Student details :
                Student Name : soham   Roll No : 3     Division : B    Standard : 7th

                Do you want to search more records ( Yes (1) / No (0) ) : 1

                Enter the roll no. to get particular student details : 5

                Invalid Number Entered!

                Enter the roll no. to get particular student details : 0

                Invalid Number Entered!

                Enter the roll no. to get particular student details : 3

                Student details :
                Student Name : soham   Roll No : 3     Division : B    Standard : 7th

                Do you want to search more records ( Yes (1) / No (0) ) : 0                       
*/