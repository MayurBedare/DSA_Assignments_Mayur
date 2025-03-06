/*
    Q-5 ->  Add 2 consecutive node into 3rd node (create that 3rd node) and so on
*/

/*
    Input : |_Head_| --> |_3_|_AA_|_Address_| --> |_5_|_BB_|_Address_| --> |_4_|_CC_|_Address_| --> |_6_|_DD_|_0_|
*/

#include "node.c"

void add(Node*);

int main()
{
    Node *head = NULL;

    //Creating Linked List
    head = createList();

    add(head);
    displayList(head);

    //freeing allocated memory 
    freeList(head);
    
    return 0;
}

void add(Node* p)
{
    Node *nw, *q;

    while (p != NULL && p ->next != NULL)
    {
        q = p -> next;
        nw = (Node*)malloc(sizeof(Node));
        nw -> number = p -> number + q -> number;
        snprintf(nw -> name, sizeof(nw -> name),"%s %s", p ->name, q -> name);
        nw -> next = q -> next;
        q -> next = nw;
        p = nw -> next;
    }
    
}

//function definition

/*
    Output : 
                Enter Number and Name : 3 AA 
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 5 BB
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 4 CC
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 6 DD
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 0

                Linked List :
                |_head_| --> |_3_|_AA _|_7867712_| --> |_5_|_BB_|_7867832_| --> |_8_|_AA  BB_|_7867752_| --> |_4_|_CC_|_7867792_| --> |_6_|_DD_|_7867872_| --> |_10_|_CC DD_|_0_| 
*/


