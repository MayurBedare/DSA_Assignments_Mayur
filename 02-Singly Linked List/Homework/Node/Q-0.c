/*
    Q- ->  
*/

/*
    Input : |_Head_| --> |__|__|_Address_|
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


