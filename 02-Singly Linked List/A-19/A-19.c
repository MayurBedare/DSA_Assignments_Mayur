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

typedef struct SLLNode
{
    int number;
    char name[20];
    struct SLLNode *next;
} SLLNode;

SLLNode* create();
void insert(SLLNode*);
void delete(SLLNode*);
void revert(SLLNode*);
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
        printf("\n\n\tEnter you choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create();
            break;

        case 2:
            insert(head);
            break;

        case 3:
            delete(head);
            break;

        case 4:
            revert(head);
            break;

        case 5: 
            print(head);
            break;
        
        default:
            printf("\n\t Invalid choice! Please try again.");
        }
    }

    freeSLL(head);

    return 0;
    
}

SLLNode* create() {

    SLLNode *head, *nw, *last;
    head = NULL, nw = NULL, last = NULL;

    int cnt;

    do
    {
        nw = malloc(sizeof(SLLNode));

        printf("\n\tEnter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

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

void insert(SLLNode *head) {

    SLLNode *nw = NULL,*p = NULL;
    p = head;

    int pos;
    printf("\n\tEnter the position of node to insert : ");
    scanf("%d", &pos);

    nw = malloc(sizeof(SLLNode));
    if (nw == NULL)
    {
        printf("\n\tMemory Allocation Failed!");
    }
    
    printf("\n\tEnter the number and name of new inserted node at Given position : ");
    scanf("%d %s", &(nw -> number), nw -> name);

    if (pos == 1) {
        nw -> next = head;
        head = nw;
        print(head);
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
        print(head);
    }

}

void delete(SLLNode *head) {

    SLLNode *del = NULL,*temp = NULL;
    del = head;

    int pos;
    printf("\n\tEnter the position of the node to be deleted : ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        head = del -> next;
        free(del);
        print(head);
    } else {
        for (int i = 1 ; i < pos-1 && del -> next != NULL ; del = del -> next,i++);

        if (del -> next != NULL) {
            if (del -> next -> next == NULL) {
                del -> next = NULL;
                free(del -> next);
                print(head);
            } else {
            temp = del -> next;
            del -> next = del -> next -> next;
            free(temp);
            print(head);
            }
        } else {
            printf("\n\tInvalid Position Entered!\n\n");
            free(del);
            del = NULL;
        }
    }

}

void revert(SLLNode *head) {

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
    
    print(head);

}

void print(SLLNode *d) {

    printf("\n\n|_Head_| ");
    for ( ; d != NULL ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("\n\n");

}

void freeSLL(SLLNode *f) {

    for( ; f != NULL ; f = f -> next)
        free(f);

    f = NULL;
}

/*
    Output ->                                
*/