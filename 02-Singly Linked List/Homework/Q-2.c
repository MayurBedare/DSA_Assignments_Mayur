/*
    Q-2 -> Print alternate nodes of singly linked list  
*/

/*
    Input : |_head_| --> |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_NULL_|
*/

#include "node.c"

void alternateList(Node*);

int main()
{
    Node *head = NULL;

    //Creating the linked list
    head = createList();

    alternateList(head);
    
    return 0;
}

void alternateList(Node* p)
{
    printf("\n Linked List : \n|_head_| ");

    while (p != NULL)
    {
    printf("--> |_%d_|_%s_|_%u_|", p -> number, p -> name, p -> next);
    
    //Move two step ahead if possible 
    if (p -> next != NULL)
    {
        p = p ->next ->next;
    }
    else
    {
        break; //Prevent segmentation fault
    }
    }
    
}

/*
    Output : 
                Enter Number and Name : 1 AA
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 2 BB
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 3 CC
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 4 DD
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 5 EE
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 0

                Linked List :
                |_head_| --> |_1_|_AA_|_12194696_|--> |_3_|_CC_|_12194776_|--> |_5_|_EE_|_0_|
*/


