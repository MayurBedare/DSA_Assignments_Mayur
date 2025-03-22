/*
    A-2 ->  write a c program to Create and Display Singly Linked list. with structure "Student" with following data members:
            -Name 
            -Roll no
            -standard
            -Division
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
void freeSLL(Student*);

int main() {
    
    Student *head = NULL;

    head = createSLL();

    displaySLL(head);

    freeSLL(head);
        
    return 0;
}

Student* createSLL() {

    Student *head = NULL,*nw,*last = NULL;

    int i = 1;
    int cnt;

    do
    {
        printf("\n\tGive Student %d details : ",i);

        nw = malloc(sizeof(Student));
        if (nw == NULL)
        {
        printf("Memory Allocation Failed!");
        }

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

        printf("\n\tDo you want to enter more records ( yes(1) / no(0) ) :");
        scanf("%d", &cnt);

        i++;
    } while (cnt != 0);

    return head; 
}

void displaySLL(Student *d) {

    printf("\n\t|_head_| ");
    for ( ; d != NULL; d = d -> next )
        printf("--> |_%s_|_%d_|_%s_|_%s_|_%p_| ", d -> std_name, d -> std_rollNo, d -> std_standard, d -> std_div, d -> next);

    printf("\n\n");
}

void freeSLL(Student *f) {

    for( ; f != NULL ; f = f -> next)
        free(f);

}

/*
    Output ->     
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