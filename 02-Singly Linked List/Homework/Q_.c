/*
    Q- ->  Revert the given linked list 
*/

/*
    Input : |_Head_| --> |__|__|_Address_|
*/

#include "node.c"

Node* revert(Node*);

int main()
{
    Node *head = NULL;

    //Creating Linked List
    head = createList();

    printf("\nLinked List before revert :\n");
    displayList(head);

    head = revert(head);
    
    printf("\n\nLinked List after revert :\n");
    displayList(head);

    //freeing allocated memory 
    freeList(head);
    
    return 0;
}

Node* revert(Node* t)
{
    Node *x,*y,*z;
    x = t; 
    y = x -> next;
    z = y -> next;
    
    while (x -> next != NULL)
    {
        if (z -> next != NULL)
        {
            t = y -> next;
            y -> next = z -> next;
            z -> next = z -> next -> next;
            y -> next -> next = t; 
        }
        else
        {
            t = y -> next;
            z -> next = y;
            y -> next = x;
            x -> next = NULL;
            
        }
    }    
    return t;
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
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 6 FF
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 0

                Linked List before revert :

                Linked List :

                |_head_| --> |_1_|_AA_|_9047360_| --> |_2_|_BB_|_9047400_| --> |_3_|_CC_|_9047440_| --> |_4_|_DD_|_9047480_| --> |_5_|_EE_|_9047520_| --> |_6_|_FF_|_0_|      

                Linked List after revert :

                Linked List :

                |_head_| --> |_6_|_FF_|_9047480_| --> |_5_|_EE_|_9047440_| --> |_4_|_DD_|_9047400_| --> |_3_|_CC_|_9047360_| --> |_2_|_BB_|_9056144_| --> |_1_|_AA_|_0_|
*/


