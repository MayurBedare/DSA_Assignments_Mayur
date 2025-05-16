/*
    A-19 -> write a c program to Create a Singly linked list  and perform menu driven which includes following functions: 
            - create(),
            - Insert(),
            - Delete(),
            - Revert(),
            - print()
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SLLNode
{
    int number;
    char name[20];
    struct SLLNode *next;
} SLLNode;

SLLNode* create();
SLLNode* insert(SLLNode*);
SLLNode*  delete(SLLNode*);
SLLNode*  revert(SLLNode*);
void print(SLLNode*);
void freeSLL(SLLNode*);

int main() {
    
    SLLNode *head = NULL;

    int choice;

    while (!choice)
    {
        int choice;
        printf("\n\t*****Menu Driven Program = Singly Linked List");
        printf("\n\t1.Create Linked List");
        printf("\n\t2.Insert Node at any position in Linked List");
        printf("\n\t3.Delete Node at any position in Linked List");
        printf("\n\t4.Reverse the Linked List");
        printf("\n\t5.Print Linked List");
        printf("\n\t6.Exit");
        printf("\n\n\tEnter you choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create();
            break;

        case 2:
            head = insert(head);
            break;

        case 3:
            head = delete(head);
            break;

        case 4:
            head = revert(head);
            break;

        case 5: 
            print(head);
            break;
        
        case 6:
            freeSLL(head);
            head = NULL;
            printf("\n\t Program Exited Successfully. \n\n");
            exit(0);

        default:
            printf("\n\t Invalid choice! Please try again.");
        }
    }

    return 0;
    
}

SLLNode* create() {

    SLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = (SLLNode*)malloc(sizeof(SLLNode));
        if (nw == NULL)
        {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\tEnter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

        nw -> next = NULL;

        if (head == NULL)
            head = nw;
        else 
            last -> next = nw;
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

SLLNode* insert(SLLNode *head) {

    SLLNode *nw = NULL,*p = NULL;
    p = head;

    int pos;
    printf("\n\tEnter the position of node to insert : ");
    scanf("%d", &pos);

    nw = (SLLNode*)malloc(sizeof(SLLNode));
    if (nw == NULL)
    {
        printf("\n\t Memory Allocation Failed! \n\n");
        exit(1);
    }
    
    printf("\n\tEnter the number and name of new inserted node at Given position : ");
    scanf("%d", &(nw -> number));
    getchar();
    fgets(nw -> name,20,stdin);
    nw -> name[strcspn(nw -> name,"\n")] = '\0';

    if (pos == 1) {
        nw -> next = head;
        head = nw;
    } else {
        for (int i = 1 ; i < pos-1 && p != NULL ; p = p -> next, i++);

        if (p != NULL) {
            nw -> next = p -> next;
            p -> next = nw;
        } else {
            printf("\n\tInvalid Position Entered!");
            free(p);
        }
        
        printf("\n\tLinked list after Insertion of node at given position : ");
    }
    
    return head;
}

SLLNode* delete(SLLNode *head) {

    SLLNode *del = NULL,*temp = NULL;
    del = head;

    int pos;
    printf("\n\tEnter the position of the node to be deleted : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        head = del -> next;
        free(del);
    } else {
        for (int i = 1 ; i < pos-1 && del -> next != NULL ; del = del -> next,i++);

        if (del -> next != NULL) {
            if (del -> next -> next == NULL) {
                del -> next = NULL;
                free(del -> next);
            } else {
            temp = del -> next;
            del -> next = del -> next -> next;
            free(temp);
            }
        } else {
            printf("\n\tInvalid Position Entered!\n\n");
        }
    }

    return head;

}

SLLNode* revert(SLLNode *head) {

    SLLNode *x,*y,*z;
    x = head; 
    y = x -> next;
    z = y -> next;
    
    while (x -> next != NULL)
    {
        if (z -> next != NULL)
        {
            head = y -> next;
            y -> next = z -> next;
            z -> next = z -> next -> next;
            y -> next -> next = head; 
        }
        else
        {
            head = y -> next;
            z -> next = y;
            y -> next = x;
            x -> next = NULL;
            
        }
    }    
    
    return(head);

}

void print(SLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSLL(SLLNode *f) {
    SLLNode *t = NULL;

    while (f != NULL) {
        t = f;
        f = f -> next;
        free(t);
    }
}

/*
    Output ->    
                    *****Menu Driven Program = Singly Linked List
                    1.Create Linked List
                    2.Insert Node at any position in Linked List
                    3.Delete Node at any position in Linked List
                    4.Reverse the Linked List
                    5.Print Linked List
                    6.Exit

                    Enter you choice : 1

                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    *****Menu Driven Program = Singly Linked List
                    1.Create Linked List
                    2.Insert Node at any position in Linked List
                    3.Delete Node at any position in Linked List
                    4.Reverse the Linked List
                    5.Print Linked List
                    6.Exit

                    Enter you choice : 5


            |_Head_| --> |_1_|_AA_|_00C713B0_| --> |_2_|_BB_|_00C713D8_| --> |_3_|_CC_|_00000000_| 


                    *****Menu Driven Program = Singly Linked List
                    1.Create Linked List
                    2.Insert Node at any position in Linked List
                    3.Delete Node at any position in Linked List
                    4.Reverse the Linked List
                    5.Print Linked List
                    6.Exit

                    Enter you choice : 2

                    Enter the position of node to insert : 2

                    Enter the number and name of new inserted node at Given position : 5 MM

                    Linked list after Insertion of node at given position :
                    *****Menu Driven Program = Singly Linked List
                    1.Create Linked List
                    2.Insert Node at any position in Linked List
                    3.Delete Node at any position in Linked List
                    4.Reverse the Linked List
                    5.Print Linked List
                    6.Exit

                    Enter you choice : 5


            |_Head_| --> |_1_|_AA_|_00C71400_| --> |_5_|_MM_|_00C713B0_| --> |_2_|_BB_|_00C713D8_| --> |_3_|_CC_|_00000000_|


                    *****Menu Driven Program = Singly Linked List
                    1.Create Linked List
                    2.Insert Node at any position in Linked List
                    3.Delete Node at any position in Linked List
                    4.Reverse the Linked List
                    5.Print Linked List
                    6.Exit

                    Enter you choice : 3

                    Enter the position of the node to be deleted : 2

                    *****Menu Driven Program = Singly Linked List
                    1.Create Linked List
                    2.Insert Node at any position in Linked List
                    3.Delete Node at any position in Linked List
                    4.Reverse the Linked List
                    5.Print Linked List
                    6.Exit

                    Enter you choice : 5


            |_Head_| --> |_1_|_AA_|_00C713B0_| --> |_2_|_BB_|_00C713D8_| --> |_3_|_CC_|_00000000_|


                    *****Menu Driven Program = Singly Linked List
                    1.Create Linked List
                    2.Insert Node at any position in Linked List
                    3.Delete Node at any position in Linked List
                    4.Reverse the Linked List
                    5.Print Linked List
                    6.Exit

                    Enter you choice : 4

                    *****Menu Driven Program = Singly Linked List
                    1.Create Linked List
                    2.Insert Node at any position in Linked List
                    3.Delete Node at any position in Linked List
                    4.Reverse the Linked List
                    5.Print Linked List
                    6.Exit

                    Enter you choice : 5


            |_Head_| --> |_3_|_CC_|_00C713B0_| --> |_2_|_BB_|_00C71388_| --> |_1_|_AA_|_00000000_|


                    *****Menu Driven Program = Singly Linked List
                    1.Create Linked List
                    2.Insert Node at any position in Linked List
                    3.Delete Node at any position in Linked List
                    4.Reverse the Linked List
                    5.Print Linked List
                    6.Exit

                    Enter you choice : 6                            
*/