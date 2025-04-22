/*
    A-5 ->  Create a structure "Students" with below member variables:
            - Name of student,
            - Roll no. Of Student,
            - array of 5 Subject marks,
            - Total Percentage.
            Calculate the Percentage for "N" number of students,
            Display all details for all students,
            Display the details of topper.
            (use array of structure)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Students
{
    char name[20];
    int no;
    int s_marks[5];
    float percentage;
} S;


int main() {
    int n;
    printf("\n\t Enter the number of students : ");
    scanf("%d", &n); 
    
    S *arr = malloc(sizeof(S)*n); // *arr same as arr[]
    if (arr == NULL) {
        printf("Memory Allocation Failed!");
        exit(1);
    }

    for (int i = 0 ; i < n ; i++) {
        int sum = 0;

        printf("\n\t Enter Student %d Name : ",++i);
        getchar();
        i--;
        fgets((arr + i) -> name,20,stdin);
        (arr + i) -> name[strcspn((arr + i) -> name,"\n")] = '\0';

        printf("\t Enter Student Roll No. : ");
        scanf("%d",&((arr + i) -> no));

        printf("\t Enter Student's 5 Subject Marks (Out of 100) :\n");
        for (int i = 0 ; i < 5 ; i++) {
            printf("\t Enter Subject %d Marks : ",++i);
            i--;
            scanf("%d",&((arr + i) -> s_marks[i]));
            sum = sum + (arr + i) -> s_marks[i];
        }

        (arr + i) -> percentage = (sum/5);
    
        printf("\n\t Student Details : ");
        printf("\n\t Student Name : %s",(arr + i) -> name);
        printf("\n\t Student Roll No. : %d",(arr + i) -> no);
        printf("\n\t Student Subject Marks : ");
        for (int j = 0 ; j < 5 ; j++) {
        printf("\n\t Subject %d Marks : %d",j,(arr + j) -> s_marks[j]);
        }
        printf("\n\t Student Percentage : %f\n\n",(arr + i) -> percentage);

    }
    int i = -1;

    for (int k = 0 ; k < n ; k++) {
        for (int l = 0 ; l < n; l++) {
            if (k != l) {
                if (((arr + k) -> percentage) >= ((arr + l) -> percentage)) {
                    i = k;
                }
            }
        }
    }

    if (i != -1) {
        printf("\n\n\t ***** Toppers Details ***** ");
        printf("\n\t Topper Name : %s",(arr + i) -> name);
        printf("\n\t Topper Roll No. : %d",(arr + i) -> no);
        printf("\n\t Topper Subject Marks : ");
        for (int j = 0 ; j < 5 ; j++) {
            printf("\n\t Subject %d Marks : %d",j,(arr + j) -> s_marks[j]);
        }
        printf("\n\t Topper Percentage : %f",(arr + i) -> percentage);
        printf("\n\t *************************** \n\n");
    }

    free(arr);
    arr = NULL;

    return 0;   
}

/*
    Output ->    
                Enter the number of students : 3

                Enter Student 1 Name : Nirman Bhise
                Enter Student Roll No. : 1
                Enter Student's 5 Subject Marks (Out of 100) :
                Enter Subject 1 Marks : 78
                Enter Subject 2 Marks : 79
                Enter Subject 3 Marks : 98
                Enter Subject 4 Marks : 90
                Enter Subject 5 Marks : 87

                Student Details : 
                Student Name : Nirman Bhise
                Student Roll No. : 1
                Student Subject Marks : 
                Subject 0 Marks : 78
                Subject 1 Marks : 79
                Subject 2 Marks : 98
                Subject 3 Marks : 90
                Subject 4 Marks : 87
                Student Percentage : 86.000000


                Enter Student 2 Name : Jyoti Dongare
                Enter Student Roll No. : 2
                Enter Student's 5 Subject Marks (Out of 100) :
                Enter Subject 1 Marks : 87
                Enter Subject 2 Marks : 98
                Enter Subject 3 Marks : 97
                Enter Subject 4 Marks : 90
                Enter Subject 5 Marks : 89

                Student Details : 
                Student Name : Jyoti Dongare
                Student Roll No. : 2
                Student Subject Marks :
                Subject 0 Marks : 87
                Subject 1 Marks : 98
                Subject 2 Marks : 97
                Subject 3 Marks : 90
                Subject 4 Marks : 89
                Student Percentage : 92.000000


                Enter Student 3 Name : Bhavesh Patil
                Enter Student Roll No. : 3
                Enter Student's 5 Subject Marks (Out of 100) :
                Enter Subject 1 Marks : 98
                Enter Subject 2 Marks : 89
                Enter Subject 3 Marks : 78
                Enter Subject 4 Marks : 78
                Enter Subject 5 Marks : 77

                Student Details :
                Student Name : Bhavesh Patil
                Student Roll No. : 3
                Student Subject Marks :
                Subject 0 Marks : 98
                Subject 1 Marks : 89
                Subject 2 Marks : 78
                Subject 3 Marks : 78
                Subject 4 Marks : 77
                Student Percentage : 84.000000



                ***** Toppers Details *****
                Topper Name : Jyoti Dongare
                Topper Roll No. : 2
                Topper Subject Marks :
                Subject 0 Marks : 98
                Subject 1 Marks : 89
                Subject 2 Marks : 78
                Subject 3 Marks : 78
                Subject 4 Marks : 77
                Topper Percentage : 92.000000
                ***************************                            
*/