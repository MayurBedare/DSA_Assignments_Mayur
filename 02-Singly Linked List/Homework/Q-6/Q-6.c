/*
    Q-6 -> Find middle element in the linked list  
*/

/*
    Input : |_Head_| --> |_1_|_AA_|_Address_| --> |_2_|_BB_|_Address_| --> |_3_|_CC_|_Address_| --> |_4_|_DD_|_Address_| --> |_5_|_EE_|_0_|
*/

#include "node.c"

void printMiddleNode(Node*);

int main()
{
    Node *head = NULL;

    //Creating Linked List
    head = createList();

    printMiddleNode(head);

    //freeing allocated memory 
    freeList(head);
    
    return 0;
}

void printMiddleNode(Node* head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    printf("\nMiddle Node : |_%d_|_%s_|_%p_| ", slow -> number, slow -> name, slow -> next);
    
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

                Middle Node : |_3_|_CC_|_14683536_|
*/


