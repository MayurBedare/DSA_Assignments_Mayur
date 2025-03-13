/*
    Q-4 ->  Display all even node data, odd node data & count of even nodes & count of odd nodes
*/

/*
    Input : |_Head_| --> |_3_|_AA_|_Address_| --> |_5_|_BB_|_Address_| --> |_4_|_CC_|_Address_| --> |_6_|_DD_|_0_|
*/

#include "node.c"

//function declaration

int main()
{
    Node *head = NULL;

    //Creating Linked List
    head = createList();

    //function call

    //freeing allocated memory 
    freeList(head);
    
    return 0;
}

//function definition

/*
    Output : 
*/


