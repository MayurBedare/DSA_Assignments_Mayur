/*
    A-8 ->  write a c program to Create a Menu driven for circular doubly linked list which consists the following functions: - 
            - Create(), 
            - Insert(),
            - Delete(), 
            - Display().
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DCLLNode
{
    int number;
    char name[20];
    struct DCLLNode *next;
    struct DCLLNode *prev;
} DCLLNode;

DCLLNode* createDCLL();
DCLLNode* insert(DCLLNode*);
DCLLNode* delete(DCLLNode*);
void displayDCLL(DCLLNode*);
void freeDCLL(DCLLNode*);

int main() {
   
    DCLLNode *last = NULL;

    printf("\n\t *****Menu Driven Program = Singly Circular Linked List*****\n");

    while (1)
    {
        int choice;
        printf("\n\t 1. Create Doubly Linked List");
        printf("\n\t 2. Insert Node at any position in Doubly Circular Linked List");
        printf("\n\t 3. Delete Node at any position in Doubly Circular Linked List");
        printf("\n\t 4. Print Doubly Circular Linked List");
        printf("\n\t 5. Exit");
        printf("\n\n\t Enter you choice : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            last = createDCLL();
            break;

        case 2:
            last = insert(last);
            break;

        case 3:
            last = delete(last);
            break;

        case 4: 
            displayDCLL(last);
            break;
        
        case 5:
            printf("\n");
            return 0;

        default:
            printf("\n\t Invalid choice! Please try again.");
        }
    }
    
    freeDCLL(last);

    return 0;
    
}

DCLLNode* createDCLL() {

    DCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = (DCLLNode*)malloc(sizeof(DCLLNode));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\tEnter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

        nw -> next = nw;
        nw -> prev = nw;

        if (head == NULL) {
            head = nw;
        }
        else {
            last -> next = nw;
            nw -> prev = last;
            nw -> next = head;
            head -> prev = nw;
        }
        
        last = nw;

        printf("Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

DCLLNode* insert(DCLLNode *last) {

    DCLLNode *p = NULL;
    p = last -> next;

    DCLLNode *nw = NULL;
    nw = malloc(sizeof(DCLLNode));
    printf("\n\t Enter number and name of the node to be inserted at the given position : ");
    scanf("%d", &(nw -> number));
    getchar();
    fgets(nw -> name,20,stdin);
    nw -> name[strcspn(nw -> name,"\n")] = '\0';

    int pos;
    printf("\n\t Enter the position where new node to be insereted : ");
    scanf("%d",&pos);

    if (pos == 1) {
        nw -> next = last -> next;
        nw -> next -> prev = nw;
        nw -> prev = last;
        last -> next = nw;

    } else {
        int i;
        for(i = 1 ; i < (pos - 1) && p != last ; i++, p = p -> next);

        if (p != last) {
            nw -> next = p -> next;
            nw -> next -> prev = nw;
            nw -> prev = p;
            p -> next = nw;
        } else {
            if (i == (pos - 1)) {
            nw -> next = p -> next;
            nw -> prev = p;
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

DCLLNode* delete(DCLLNode *last) {

    int pos;
    DCLLNode *d = NULL;
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
        d -> next -> prev = last;
        free(d);
        d = NULL;
    } else {
        int i;
        for (d = d -> next,i = 1 ; i < (pos - 1) && d != last ; d = d -> next,i++);

        if (d != last) {
            d -> prev -> next = d -> next;
            d -> next -> prev = d -> prev;
            free(d);
            d = NULL;
        } else {
            if (i == (pos - 1)) {
            d -> prev -> next = d -> next;
            d -> prev -> next -> prev = d -> prev;
            last = d -> prev;
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

void displayDCLL(DCLLNode *last) {

    DCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n|_Head_| ");
    printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);


    for (d = d -> next ; d != last -> next ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf(" <--> |_last_|");

    printf("\n\n");

}

void freeDCLL(DCLLNode *last) {

    if (last == NULL)
        return;

    DCLLNode *f = NULL;
    f = last -> next;

    while (f != last) {   
        f = f -> next;
        free(f -> prev);
        f -> prev = NULL;
    }

    free(f);
    f = NULL;

}

/*
    Output ->
                    *****Menu Driven Program = Singly Circular Linked List*****

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Circular Linked List
                    3. Delete Node at any position in Doubly Circular Linked List
                    4. Print Doubly Circular Linked List
                    5. Exit

                    Enter you choice : 1  

                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Circular Linked List
                    3. Delete Node at any position in Doubly Circular Linked List
                    4. Print Doubly Circular Linked List
                    5. Exit

                    Enter you choice : 2

                    Enter number and name of the node to be inserted at the given position : 5 MM

                    Enter the position where new node to be insereted : 2

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Circular Linked List
                    3. Delete Node at any position in Doubly Circular Linked List
                    4. Print Doubly Circular Linked List
                    5. Exit

                    Enter you choice : 4


            |_Head_| <--> |_00CD13D8_|_1_|_AA_|_00CD1400_| <--> |_00CD1388_|_5_|_MM_|_00CD13B0_| <--> |_00CD1400_|_2_|_BB_|_00CD13D8_| <--> |_00CD13B0_|_3_|_CC_|_00CD1388_|  <--> |_last_|


                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Circular Linked List
                    3. Delete Node at any position in Doubly Circular Linked List
                    4. Print Doubly Circular Linked List
                    5. Exit

                    Enter you choice : 3

                    Enter the position of the node to be deleted from the given linked list : 2

                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Circular Linked List
                    3. Delete Node at any position in Doubly Circular Linked List
                    4. Print Doubly Circular Linked List
                    5. Exit

                    Enter you choice : 4


            |_Head_| <--> |_00CD13D8_|_1_|_AA_|_00CD13B0_| <--> |_00CD1388_|_2_|_BB_|_00CD13D8_| <--> |_00CD13B0_|_3_|_CC_|_00CD1388_|  <--> |_last_|


                    1. Create Doubly Linked List
                    2. Insert Node at any position in Doubly Circular Linked List
                    3. Delete Node at any position in Doubly Circular Linked List
                    4. Print Doubly Circular Linked List
                    5. Exit

                    Enter you choice : 5
*/