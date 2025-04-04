/*
    A-11 -> write a c program to Create Menu Driven for doubly linked list which consist following functions:- 
            - Create(),
            - Insert(),
            - Delete(),
            - Reverse(),
            - Display().
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct DLLNode
{
    int number;
    char name[20];
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

DLLNode* createDLL();
DLLNode* insert(DLLNode*);
DLLNode* delete(DLLNode*);
DLLNode* revert(DLLNode*);
void displayDLL(DLLNode*);
void freeDLL(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    printf("\n\t *****Menu Driven Program = Doubly Linked List*****\n");

    while (1)
    {
        int choice;
        printf("\n\t 1. Create Doubly Linked List");
        printf("\n\t 2. Insert Node at any position in Doubly Linked List");
        printf("\n\t 3. Delete Node at any position in Doubly Linked List");
        printf("\n\t 4. Reverse the Doubly Linked List");
        printf("\n\t 5. Print Doubly Linked List");
        printf("\n\t 6. Exit");
        printf("\n\n\t Enter you choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = createDLL();
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
            displayDLL(head);
            break;
        
        case 6:
            printf("\n");
            return 0;

        default:
            printf("\n\t Invalid choice! Please try again.");
        }
    }
    
    printf("\n\tLinked List : ");
    displayDLL(head);
    
    freeDLL(head);

    return 0;
    
}

DLLNode* createDLL() {

    DLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = malloc(sizeof(DLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = NULL;

        if (head == NULL) {
            head = nw;
            nw -> prev = NULL;
        }
        else {
            last -> next = nw;
            nw -> prev = last;
        }
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return head;

}

DLLNode* insert(DLLNode *head) {

    DLLNode *nw = NULL,*p = NULL;
    p = head;

    int pos;
    printf("\n\tEnter the position of node to insert : ");
    scanf("%d", &pos);

    nw = malloc(sizeof(DLLNode));
    if (nw == NULL)
    {
        printf("\n\tMemory Allocation Failed!");
    }
    
    printf("\n\tEnter the number and name of new inserted node at Given position : ");
    scanf("%d %s", &(nw -> number), nw -> name);

    if (pos == 1) {
        nw -> next = head;
        head -> prev = nw;
        head = nw;
    } else {
        for (int i = 1 ; i < pos-1 && p != NULL ; p = p -> next, i++);

        if (p != NULL) {
            nw -> next = p -> next;

            if (p -> next != NULL)
                p -> next -> prev = nw;

            p -> next = nw;
            nw -> prev = p;
        } else {
            printf("\n\tInvalid Position Entered!\n\n");
            free(p);
            exit(0);
        }
    }

    return head;

}

DLLNode* delete(DLLNode *head) {

    DLLNode *del = NULL,*temp = NULL;
    del = head;

    int pos;
    printf("\n\tEnter the position of the node to be deleted : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        head = del -> next;
        head -> prev = NULL;
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
                temp -> next -> prev = del;
                free(temp);
            }
        } else {
            printf("\n\tInvalid Position Entered!\n\n");
            free(del);
            del = NULL;
            exit(0);
        }
    }

   return head;

}

DLLNode* revert(DLLNode *head) {

    DLLNode *trace = NULL, *temp = NULL;

    for (trace = head,temp = trace -> next ; trace != NULL ; trace = trace -> prev, temp = trace -> next) {

        trace -> next = trace -> prev;
        trace -> prev = temp;

        if (trace -> prev == NULL) {
            head = trace;
            break;
        }

    }

    return head;

}

void displayDLL(DLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeDLL(DLLNode *f) {

    for( ; f != NULL ; f = f -> next)
        free(f);

    f = NULL;
}

/*
    Output ->
                    *****Menu Driven Program = Doubly Linked List*****

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Linked List
                    3. Delete Node at any position in Doubly Linked List
                    4. Reverse the Doubly Linked List
                    5. Print Doubly Linked List
                    6. Exit

                    Enter you choice : 1

                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Linked List
                    3. Delete Node at any position in Doubly Linked List
                    4. Reverse the Doubly Linked List
                    5. Print Doubly Linked List
                    6. Exit

                    Enter you choice : 5


            |_Head_| <--> |_00000000_|_1_|_AA_|_00DD0D40_| <--> |_00DD2F98_|_2_|_BB_|_00DD0D68_| <--> |_00DD0D40_|_3_|_CC_|_00000000_| 


                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Linked List
                    3. Delete Node at any position in Doubly Linked List
                    4. Reverse the Doubly Linked List
                    5. Print Doubly Linked List
                    6. Exit

                    Enter you choice : 2

                    Enter the position of node to insert : 2

                    Enter the number and name of new inserted node at Given position : 5 MM

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Linked List
                    3. Delete Node at any position in Doubly Linked List
                    4. Reverse the Doubly Linked List
                    5. Print Doubly Linked List
                    6. Exit

                    Enter you choice : 5


            |_Head_| <--> |_00000000_|_1_|_AA_|_00DD0D90_| <--> |_00DD2F98_|_5_|_MM_|_00DD0D40_| <--> |_00DD0D90_|_2_|_BB_|_00DD0D68_| <--> |_00DD0D40_|_3_|_CC_|_00000000_|   


                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Linked List
                    3. Delete Node at any position in Doubly Linked List
                    4. Reverse the Doubly Linked List
                    5. Print Doubly Linked List
                    6. Exit

                    Enter you choice : 3

                    Enter the position of the node to be deleted : 2

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Linked List
                    3. Delete Node at any position in Doubly Linked List
                    4. Reverse the Doubly Linked List
                    5. Print Doubly Linked List
                    6. Exit

                    Enter you choice : 5


            |_Head_| <--> |_00000000_|_1_|_AA_|_00DD0D40_| <--> |_00DD2F98_|_2_|_BB_|_00DD0D68_| <--> |_00DD0D40_|_3_|_CC_|_00000000_|


                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Linked List
                    3. Delete Node at any position in Doubly Linked List
                    4. Reverse the Doubly Linked List
                    5. Print Doubly Linked List
                    6. Exit

                    Enter you choice : 4

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Linked List
                    3. Delete Node at any position in Doubly Linked List
                    4. Reverse the Doubly Linked List
                    5. Print Doubly Linked List
                    6. Exit

                    Enter you choice : 5


            |_Head_| <--> |_00000000_|_3_|_CC_|_00DD0D40_| <--> |_00DD0D68_|_2_|_BB_|_00DD2F98_| <--> |_00DD0D40_|_1_|_AA_|_00000000_|


                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Linked List
                    3. Delete Node at any position in Doubly Linked List
                    4. Reverse the Doubly Linked List
                    5. Print Doubly Linked List
                    6. Exit

                    Enter you choice : 6
*/