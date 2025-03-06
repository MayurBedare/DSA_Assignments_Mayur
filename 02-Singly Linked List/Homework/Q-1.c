/*
    Q-1 -> Create, Display & Free Singly Linked List 
*/

/*
    Input : |_Head_| --> |_1_|_AA_|_100_| --> |_3_|_CC_|_300_| --> |_5_|_EE_|_NULL_|
*/

#include "node.c"

void displayList(Node*);
void freeList(Node*);

int main()
{
    Node *head = NULL;

    //Creating and displaying the linked list 
    head = createList();
    displayList(head);

    //freeing allocated memory 
    freeList(head);
    
    return 0;
}

void displayList(Node* head)
{
    if (head == NULL)
    {
        printf("\n The List is empty \n");
        return;
    }

    printf("\n Linked List : \n|_head_| ");
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

/*
    Output :           
                Enter Number and Name : 1 AA 
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 3 CC
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 5 EE
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 0

                Linked List :
                |_head_| --> |_1_|_AA _|_14291848_| --> |_3_|_CC_|_14291888_| --> |_5_|_EE_|_0_|
*/


