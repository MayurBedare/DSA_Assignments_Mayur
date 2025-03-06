/*
    Q-7 ->  Insert a node at head and end position  
*/

/*
    Input : |_Head_| --> |_3_|_AA_|_Address_| --> |_5_|_BB_|_Address_| --> |_6_|_DD_|_0_|
*/

#include "node.c"

Node* headNodeIns(Node*);
Node* endNodeIns(Node*);

int main()
{
    Node *head = NULL;

    //Creating Linked List
    head = createList();

    head = headNodeIns(head);
    endNodeIns(head);
    displayList(head);    

    //freeing allocated memory 
    freeList(head);

    return 0;
}

Node* headNodeIns(Node* head)
{
    Node *nw = (Node*)malloc(sizeof(Node));
    nw -> next = NULL;
    printf("\nInsertion of linked list node at head position -\n");
    printf("Enter Number & Name :");
    scanf("%d %s", &nw -> number, &nw -> name);
    nw -> next = head;
    head = nw;
    return head;
}

Node* endNodeIns(Node* p)
{
    Node *nw = (Node*)malloc(sizeof(Node));
    nw -> next = NULL;
    printf("\nInsertion of linked list node at end position -\n");
    printf("Enter Number and Name :");
    scanf("%d %s", &nw -> number, &nw -> name);

    while (p != NULL)
    {
        if(p -> next == NULL)
        {
            p -> next = nw;
            break;
        }
        p = p -> next;
    }
    
}

/*
    Output : 
                Enter Number and Name : 3 AA
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 5 BB
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 1

                Enter Number and Name : 6 DD
                Enter name : Do you want to enter more records ? (1 for yes / 0 for no) : 0

                Insertion of linked list node at head position -
                Enter Number & Name :1 EE

                Insertion of linked list node at end position -
                Enter Number and Name :7 FF

                Linked List :
                |_head_| --> |_1_|_EE_|_14167960_| --> |_3_|_AA_|_14159304_| --> |_5_|_BB_|_14159344_| --> |_6_|_DD_|_14159424_| --> |_7_|_FF_|_0_|
*/


