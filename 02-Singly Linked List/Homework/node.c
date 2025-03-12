#include "node.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function Definition
Node *createList()
{
    Node *head = NULL, *newNode , *lastNode = NULL; 
    int choice;

    do 
    {
        //Allocate memory for new node
        newNode = (Node*)malloc(sizeof(Node));

        if(newNode == NULL)
        {
            printf("Memory Allocation Failed : \n");
            return head;
        }

        //Get input from the user
        printf("\nEnter Number and Name : ");
        scanf("%d", &newNode -> number);
        getchar();//Clear the buffer using fgets
        printf("Enter name : ");
        fgets(newNode -> name, sizeof(newNode -> name),stdin);
        newNode -> name[strcspn(newNode -> name, "\n")] = '\0';//Remove newline character
        newNode -> next = NULL;

        //Insert node into the linked list
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            lastNode -> next = newNode;
        }
        lastNode = newNode;

        //Check if the user wants to continue
        printf("Do you want to enter more records ? (1 for yes / 0 for no) : ");
        scanf("%d",&choice);
    }
    while (choice == 1);
    return head;    
}

void displayList(Node* head)
{
    if (head == NULL)
    {
        printf("\n The List is empty \n");
        return;
    }

    printf("\nLinked List : \n\n|_head_| ");
    Node *temp = head;
    
    while (temp != NULL)
    {
        printf("--> |_%d_|_%s_|_%u_| ", temp ->number, temp ->name,temp ->next);
        temp = temp -> next;
    }    
}

void freeList(Node* head)
{
    Node *temp;

    while (head != NULL)
    {
        temp = head; head = head -> next;
        free(temp);
    }
    
}