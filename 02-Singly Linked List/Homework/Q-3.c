/*
    Q-3 -> Swap two consecutive nodes of linked list
*/

/*
    Input : |_head_| --> |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_|

    Output : |_head_| --> |_2_|_BB_|_100_| --> |_1_|_AA_|_200_| --> |_4_|_DD_|_300_| --> |_3_|_EE_|_400_|
*/

#include "node.c"

void swap(Node*);

int main()
{
    Node *head = NULL;

    //Creating Linked List
    head = createList();

    swap(head);
    displayList(head);  
    
    //freeing allocated memory 
    freeList(head);
    
    return 0;
}

void swap(Node* p)
{
    Node *q, t;

    for ( ; p != NULL ; p = q -> next)
    {
        q = p -> next;

        if (q == NULL)
        break;
        
        t.number = p -> number;
        p -> number = q -> number;
        q -> number = t.number;

        strcpy(t.name, p -> name);
        strcpy(p -> name, q -> name);
        strcpy(q -> name, t.name);
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
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 0

                Linked List :
                |_head_| --> |_2_|_BB_|_10292544_| --> |_1_|_AA _|_10292584_| --> |_4_|_DD_|_10292624_| --> |_3_|_CC_|_0_|
*/


