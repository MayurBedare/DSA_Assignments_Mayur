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

    for (int i = 1 ; i < pos -1 && p != NULL ; p = p -> next, i++)
    {
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
}

/*
    Output : 
*/


