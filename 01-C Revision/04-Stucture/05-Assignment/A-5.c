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
    int i = 0,ch,size = 2;
    S *arr = NULL;
    arr = malloc(sizeof(S));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed!");
        exit(1);
    }

    printf("\n\t ***** Finding Topper from the Student Details Provided ***** \n");

    while (ch) {
        int sum = 0;

        if (i > 0) {
            arr = (S*)realloc(arr,size*sizeof(S));
            if (arr == NULL) {
                printf("\n\t Memory Allocation Failed!");
                exit(1);
            }
        }

        printf("\n\t Enter Student %d Name : ",i+1);
        if (i > 0)  getchar();
        fgets((arr + i) -> name,20,stdin);
        (arr + i) -> name[strcspn((arr + i) -> name,"\n")] = '\0';

        printf("\t Enter Student Roll No. : ");
        scanf("%d",&((arr + i) -> no));

        printf("\t Enter Student's 5 Subject Marks (Out of 100) :\n");
        for (int j = 0 ; j < 5 ; j++) {
            printf("\t Enter Subject %d Marks : ",j+1);
            scanf("%d",&((arr + i) -> s_marks[j]));
            sum = sum + (arr + i) -> s_marks[j];
        }

        (arr + i) -> percentage = (sum/5);

        printf("\n\t Do you want to add more details of student ( Yes(1) / No(0) ) : ");
        scanf("%d",&ch); 
        printf("\n");
        
        i++,size++;

    }
    int cap = 1;

    int *topper = NULL;
    topper = malloc(sizeof(int));
    if (topper == NULL) {
        printf("\n\t Memory Allocation Failed!");
        exit(1);
    }

    printf("\n\t All Student Details As Provided : \n");
    for (int k = 0 ; k < i ; k++) {
        printf("\n\t Student %d Name : %s",k+1,(arr + k) -> name);
        printf("\n\t Student %d Roll No. : %d",k+1,(arr + k) -> no);
        printf("\n\t Student %d Subject Marks : ",k+1);
        for (int j = 0 ; j < 5 ; j++) {
        printf("\n\t Subject %d Marks : %d",j+1,(arr + k) -> s_marks[j]);
        }
        printf("\n\t Student %d Percentage : %f\n\n",k+1,(arr + k) -> percentage);

        for (int l = 0 ; l < i; l++) {
            if (k != l) {
                if (((arr + k) -> percentage) >= ((arr + l) -> percentage)) {
                topper[0] = k;
                }
            }
        }
    }
    
    if (i == 1) {
        topper[0] = 0;
    } else {
        for (int m = 0 ; m < i ; m++) {
            if (m != topper[0]) {
                if (((arr + topper[0]) -> percentage) == ((arr + m) -> percentage)) {
                    topper = (int*)realloc(topper,(cap+1)*sizeof(int));
                    topper[cap] = m;
                    cap++;
                }
            }
        }
    }
    
    if (cap > 1)    printf("\n\t Their are total %d Toppers as per the student details given : \n\n",cap);

    for (int m = 0 ; cap != 0 ; cap--,m++) {
        if (cap == (m+1)) printf("\n\t ***** Topper Details ***** ");
        else  printf("\n\t ***** Topper %d Details ***** ",m+1);  

        printf("\n\t Topper Name : %s",(arr + topper[m]) -> name);
        printf("\n\t Topper Roll No. : %d",(arr + topper[m]) -> no);
        printf("\n\t Topper Subject Marks : ");
        for (int j = 0 ; j < 5 ; j++) {
            printf("\n\t Subject %d Marks : %d",j,(arr + topper[m]) -> s_marks[j]);
        }
        printf("\n\t Topper Percentage : %f",(arr + topper[m]) -> percentage);
        printf("\n\t ***************************\n");
        
        if (cap == 1)   printf("\n");
    } 

    free(arr);
    arr = NULL;

    return 0;   
}

/*
    Output ->    
                ***** Finding Topper from the Student Details Provided ***** 

                Enter Student 1 Name : Nirman Bhise
                Enter Student Roll No. : 1
                Enter Student's 5 Subject Marks (Out of 100) :
                Enter Subject 1 Marks : 78
                Enter Subject 2 Marks : 79
                Enter Subject 3 Marks : 98
                Enter Subject 4 Marks : 90
                Enter Subject 5 Marks : 87

                Do you want to add more details of student ( Yes(1) / No(0) ) : 1


                Enter Student 2 Name : Jyoti Bedare
                Enter Student Roll No. : 2
                Enter Student's 5 Subject Marks (Out of 100) :
                Enter Subject 1 Marks : 87
                Enter Subject 2 Marks : 98
                Enter Subject 3 Marks : 97
                Enter Subject 4 Marks : 90
                Enter Subject 5 Marks : 89

                Do you want to add more details of student ( Yes(1) / No(0) ) : 1


                Enter Student 3 Name : Bhavesh Patil
                Enter Student Roll No. : 3
                Enter Student's 5 Subject Marks (Out of 100) :
                Enter Subject 1 Marks : 98
                Enter Subject 2 Marks : 89
                Enter Subject 3 Marks : 78
                Enter Subject 4 Marks : 77
                Enter Subject 5 Marks : 78

                Do you want to add more details of student ( Yes(1) / No(0) ) : 0


                All Student Details As Provided :

                Student 1 Name : Nirman Bhise
                Student 1 Roll No. : 1
                Student 1 Subject Marks :
                Subject 1 Marks : 78
                Subject 2 Marks : 79
                Subject 3 Marks : 98
                Subject 4 Marks : 90
                Subject 5 Marks : 87
                Student 1 Percentage : 86.000000


                Student 2 Name : Jyoti Bedare
                Student 2 Roll No. : 2
                Student 2 Subject Marks :
                Subject 1 Marks : 87
                Subject 2 Marks : 98
                Subject 3 Marks : 97
                Subject 4 Marks : 90
                Subject 5 Marks : 89
                Student 2 Percentage : 92.000000


                Student 3 Name : Bhavesh Patil
                Student 3 Roll No. : 3
                Student 3 Subject Marks :
                Subject 1 Marks : 98
                Subject 2 Marks : 89
                Subject 3 Marks : 78
                Subject 4 Marks : 77
                Subject 5 Marks : 78
                Student 3 Percentage : 84.000000


                ***** Topper Details *****
                Topper Name : Jyoti Bedare
                Topper Roll No. : 2
                Topper Subject Marks :
                Subject 0 Marks : 87
                Subject 1 Marks : 98
                Subject 2 Marks : 97
                Subject 3 Marks : 90
                Subject 4 Marks : 89
                Topper Percentage : 92.000000
                ***************************                         
*/