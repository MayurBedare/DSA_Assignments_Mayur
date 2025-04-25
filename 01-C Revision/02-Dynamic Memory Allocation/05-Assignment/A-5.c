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
    int i = 0,ch;
    
    while (ch) {
        Student *arr = NULL;
        arr = malloc(sizeof(Student));
        if (arr == NULL) {
            printf("\n\t Memory Allocation Failed!");
            exit(1);
        }
               
        printf("\n\t Give the Student %d details : \n",i+1);
        printf("\n\t Enter Student Name : ");
        if (i > 0)  getchar();
        fgets(arr -> name,20,stdin);
        arr -> name[strcspn(arr -> name,"\n")] = '\0';
    
        printf("\t Enter Student Roll No. : ");
        scanf("%d",&(arr -> roll_no));
        
        printf("\t Enter Student Division : ");
        scanf("%s",arr -> div);

        printf("\t Enter Student Standard : ");
        scanf("%s",arr -> std);

        printf("\n\t Student Name : %s", arr -> name);
        printf("\t Roll No : %d", arr -> roll_no);
        printf("\t Division : %s", arr -> div);
        printf("\t Standard : %s\n", arr -> std);

        printf("\n\t Do you want to add more details of student ( Yes(1) / No(0) ) : ");
        scanf("%d",&ch); 
        printf("\n");

        i++;

        free(arr);
        arr = NULL;
    }

    printf("\n\t Total Number Of Student Details Entered : %d\n\n",i);
    
    return 0;
}


/*
    Output -> 
                Give the Student 1 details : 

                Enter Student Name : kartik
                Enter Student Roll No. : 1
                Enter Student Division : B
                Enter Student Standard : 7th

                Student Name : kartik   Roll No : 1     Division : B    Standard : 7th

                Do you want to add more details of student ( Yes(1) / No(0) ) : 1


                Give the Student 2 details : 

                Enter Student Name : chirag
                Enter Student Roll No. : 2
                Enter Student Division : B
                Enter Student Standard : 7th

                Student Name : chirag   Roll No : 2     Division : B    Standard : 7th

                Do you want to add more details of student ( Yes(1) / No(0) ) : 1


                Give the Student 3 details : 

                Enter Student Name : soham
                Enter Student Roll No. : 3
                Enter Student Division : B
                Enter Student Standard : 7th

                Student Name : soham    Roll No : 3     Division : B    Standard : 7th

                Do you want to add more details of student ( Yes(1) / No(0) ) : 0


                Total Number Of Student Details Entered : 3     
*/
