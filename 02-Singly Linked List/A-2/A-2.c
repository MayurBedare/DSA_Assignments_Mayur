/*
    A-2 ->  write a c program to Create and Display Singly Linked list. with structure "Student" with following data members:
            -Name 
            -Roll no
            -standard
            -Division
*/

/* 
    Input -> |_kartik_|_1_|_7th_|_B_|_next_| --> |_chirag_|_2_|_7th_|_B_|_next_| --> |_soham_|_3_|_7th_|_B_|_0_|               
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
    char std_name[20];
    int std_rollNo;
    char std_standard[10];
    char std_div[2];
    struct Student *next;
} Student;

Student* createSLL();
void displaySLL(Student*);

int main() {
    
    Student *head = NULL;

    head = createSLL();

    displaySLL(head);
        
    return 0;
}

Student* createSLL() {

    Student *head = NULL,*nw,*last = NULL;

    int n;
    int i =1;
    printf("\n\tEnter Number of students : ");
    scanf("%d", &n);

    do
    {
        printf("\n\tGive Student %d details : ",i);
        nw = malloc(sizeof(Student));
        printf("\n\tEnter Student name : ");
        scanf("%s", nw -> std_name);
        printf("\tEnter Student roll no : ");
        scanf("%d",&(nw -> std_rollNo));
        printf("\tEnter Student standard : ");
        scanf("%s", nw -> std_standard);
        printf("\tEnter Student division : ");
        scanf("%s", nw -> std_div);
        nw -> next = NULL;

        if (head == NULL) {
            head = nw;
        }
        else {
            last -> next = nw;
        }
        last = nw;

        i++;
    } while ( i-1 != n );

    return head; 
}

void displaySLL(Student *p) {

    printf("\n\t|_head_| ");
    for ( ; p != NULL; p = p -> next )
    {
        printf("--> |_%s_|_%d_|_%s_|_%s_|_%p_| ", p -> std_name, p -> std_rollNo, p -> std_standard, p -> std_div, p -> next);
    }
    printf("\n\n");
}

/*
    Output ->     
                Enter Number of students : 3

                Give Student 1 details : 
                Enter Student name : kartik
                Enter Student roll no : 1
                Enter Student standard : 7th
                Enter Student division : B

                Give Student 2 details : 
                Enter Student name : chirag
                Enter Student roll no : 2
                Enter Student standard : 7th
                Enter Student division : B

                Give Student 3 details : 
                Enter Student name : soham
                Enter Student roll no : 3
                Enter Student standard : 7th
                Enter Student division : B

                |_head_| --> |_kartik_|_1_|_7th_|_B_|_00C10D40_| --> |_chirag_|_2_|_7th_|_B_|_00C10D70_| --> |_soham_|_3_|_7th_|_B_|_00000000_|                           
*/