/*
    A-8 ->  write a c program to Create a Menu driven for circular singly linked list which consists the following functions: - 
            - Create(), 
            - Insert(),
            - Delete(), 
            - Display().  
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SCLLNode
{
    int number;
    char name[20];
    struct SCLLNode *next;
} SCLLNode;

SCLLNode* createSCLL();
SCLLNode* insert(SCLLNode*);
SCLLNode* delete(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    printf("\n\t *****Menu Driven Program = Singly Circular Linked List*****\n");

    while (1)
    {
        int choice;
        printf("\n\t 1. Create Doubly Linked List");
        printf("\n\t 2. Insert Node at any position in Singly Circular Linked List");
        printf("\n\t 3. Delete Node at any position in Singly Circular Linked List");
        printf("\n\t 4. Print Singly Circular Linked List");
        printf("\n\t 5. Exit");
        printf("\n\n\t Enter you choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            last = createSCLL();
            break;

        case 2:
            last = insert(last);
            break;

        case 3:
            last = delete(last);
            break;

        case 4: 
            displaySCLL(last);
            break;
        
        case 5:
            printf("\n");
            return 0;

        default:
            printf("\n\t Invalid choice! Please try again.");
        }
    }
    
    freeSCLL(last);

    return 0;
    
}

SCLLNode* createSCLL() {

    SCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = malloc(sizeof(SCLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

        nw -> next = nw;

        if (head == NULL) {
            head = nw;
        }
        else {
            last -> next = nw;
            nw -> next = head;
        }
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

SCLLNode* insert(SCLLNode *last) {

    SCLLNode *p = NULL;
    p = last -> next;

    SCLLNode *nw = NULL;
    nw = malloc(sizeof(SCLLNode));
    printf("\n\t Enter number and name of the node to be inserted at the given position : ");
    scanf("%d %s", &(nw -> number),nw -> name);

    int pos;
    printf("\n\t Enter the position where new node to be insereted : ");
    scanf("%d",&pos);

    if (pos == 1) {
        nw -> next = last -> next;
        last -> next = nw;
    } else {
        int i;
        for(i = 1 ; i < (pos - 1) && p != last ; i++, p = p -> next);

        if (p != last) {
            nw -> next = p -> next;
            p -> next = nw;
        } else {
            if (i == (pos - 1)) {
            nw -> next = p -> next;
            p -> next = nw;
            last = nw;
            } else {
                printf("\n\t Invalid position entered!\n\n");
                exit(0);
            }
        }
    }

    return last;

}

SCLLNode* delete(SCLLNode *last) {

    int pos;
    SCLLNode *d = NULL,*prev = NULL;
    d = last -> next;

    printf("\n\t Enter the position of the node to be deleted from the given linked list : ");
    scanf("%d",&pos);

    if (pos == 1) {
        if (d == last) {
            free(d);
            d = NULL;
            return d;
        }
        last -> next = d -> next;
        free(d);
        d = NULL;
    } else {
        int i;
        for (prev = d,d = d -> next,i = 1 ; i < (pos - 1) && d != last ; prev = prev -> next,d = d -> next,i++);

        if (d != last) {
            prev -> next = d -> next;
            free(d);
            d = NULL;
        } else {
            if (i == (pos - 1)) {
            prev -> next = d -> next;
            last = prev;
            free(d);
            d = NULL;
            } else {
                printf("\n\t Invalid Position entered!\n\n");
                exit(0);
            }
        }
    }

    return last;

}

void displaySCLL(SCLLNode *last) {
    
    SCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n|_Head_| ");

    for ( ; d != last ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("--> |_%d_|_%s_|_%p_| <-- |_last_|", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSCLL(SCLLNode *last) {

    if (last == NULL)
        return;

    SCLLNode *f = NULL,*t = NULL;
    f = last -> next;

    while (f != last) {
        t = f;   
        f = f -> next;
        free(t);
        t = NULL;
    }
    
    free(f);
    f = NULL;
}

/*
    Output ->
                    *****Menu Driven Program = Singly Circular Linked List*****

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Singly Circular Linked List
                    3. Delete Node at any position in Singly Circular Linked List
                    4. Print Doubly Linked List
                    5. Exit

                    Enter you choice : 1

                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Singly Circular Linked List
                    3. Delete Node at any position in Singly Circular Linked List
                    4. Print Doubly Linked List
                    5. Exit

                    Enter you choice : 4


            |_Head_| --> |_1_|_AA_|_00BF13B0_| --> |_2_|_BB_|_00BF13D8_| --> |_3_|_CC_|_00BF1388_| <-- |_last_|


                    1. Create Doubly Linked List
                    2. Insert Node at any position in Singly Circular Linked List
                    3. Delete Node at any position in Singly Circular Linked List
                    4. Print Doubly Linked List
                    5. Exit

                    Enter you choice : 2

                    Enter number and name of the node to be inserted at the given position : 5 MM

                    Enter the position where new node to be insereted : 2

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Singly Circular Linked List
                    3. Delete Node at any position in Singly Circular Linked List
                    4. Print Doubly Linked List
                    5. Exit

                    Enter you choice : 4


            |_Head_| --> |_1_|_AA_|_00BF1400_| --> |_5_|_MM_|_00BF13B0_| --> |_2_|_BB_|_00BF13D8_| --> |_3_|_CC_|_00BF1388_| <-- |_last_|


                    1. Create Doubly Linked List
                    2. Insert Node at any position in Singly Circular Linked List
                    3. Delete Node at any position in Singly Circular Linked List
                    4. Print Doubly Linked List
                    5. Exit

                    Enter you choice : 3

                    Enter the position of the node to be deleted from the given linked list : 2

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Singly Circular Linked List
                    3. Delete Node at any position in Singly Circular Linked List
                    4. Print Doubly Linked List
                    5. Exit

                    Enter you choice : 4


            |_Head_| --> |_1_|_AA_|_00BF13B0_| --> |_2_|_BB_|_00BF13D8_| --> |_3_|_CC_|_00BF1388_| <-- |_last_|


                    1. Create Doubly Linked List
                    2. Insert Node at any position in Singly Circular Linked List
                    3. Delete Node at any position in Singly Circular Linked List
                    4. Print Doubly Linked List
                    5. Exit

                    Enter you choice : 5
*/