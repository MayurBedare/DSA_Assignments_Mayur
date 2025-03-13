/*
    Q-8 -> Insert a node at any position depending upon user i/p (Node Insertion at any position)  
*/

/*
    Input : |_Head_| --> |_3_|_AA_|_Address_| --> |_5_|_BB_|_Address_| --> |_6_|_DD_|_0_|
*/

#include "node.c"

Node* insert(Node*);

int main()
{
    Node *head = NULL;

    //Creating Linked List
    head = createList();

    head = insert(head);

    displayList(head);

    //freeing allocated memory 
    freeList(head);
    
    return 0;
}

Node* insert(Node* head)
{
    Node *nw, *p = head;
    int pos, i;
    printf("\nEnter the position :");
    scanf("%d", &pos);

    nw = (Node*)malloc(sizeof(Node));
    printf("\nInsertion of linked list node at any position -\n");
    printf("Enter the Number & Name :");
    scanf("%d %s", & nw -> number, & nw -> name);

    nw -> next = NULL;

    //Insert at beginning
    if(pos == 1)
    {
        nw -> next = head;
        head = nw;
        return head;
    }

    for (int i = 1 ; i < pos - 1 && p != NULL ; p = p -> next, i++);
    
    //Insert at mid and end
    if(p != NULL)
    {
        nw -> next = p -> next;
        p -> next = nw;
    }
    else
    {
        printf("\n\t Invalid position");
        free(nw);//Free memory if insertion is not possible
    }

    return head; 
}

/*
    Output -> 
                Enter Number and Name : 3 AA
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 5 BB
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 6 DD
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 0

                Enter the position :2

                Insertion of linked list node at any position -
                Enter the Number & Name :2 CC

                Linked List :

                |_head_| --> |_3_|_AA_|_00D513C8_| --> |_2_|_CC_|_00D51378_| --> |_5_|_BB_|_00D513A0_| --> |_6_|_DD_|_00000000_|
*/

/*
    Position = 1 (Head Position) :

    Linked List : 

    |_head_| --> |_2_|_CC_|_00CB2FB8_| --> |_3_|_AA_|_00CB1378_| --> |_5_|_BB_|_00CB13A0_| --> |_6_|_DD_|_00000000_| 
*/

/*
    Position = 2 (Mid Position) :

    Linked List :

    |_head_| --> |_3_|_AA_|_00D513C8_| --> |_2_|_CC_|_00D51378_| --> |_5_|_BB_|_00D513A0_| --> |_6_|_DD_|_00000000_|
*/

/*
    Position = 3 (Mid Position) :

    Linked List :

    |_head_| --> |_3_|_AA_|_00C01378_| --> |_5_|_BB_|_00C013C8_| --> |_2_|_CC_|_00C013A0_| --> |_6_|_DD_|_00000000_|
*/

/*
    Position = 4 (End Position) :

    Linked List :

    |_head_| --> |_3_|_AA_|_00851378_| --> |_5_|_BB_|_008513A0_| --> |_6_|_DD_|_008513C8_| --> |_2_|_CC_|_00000000_|
*/