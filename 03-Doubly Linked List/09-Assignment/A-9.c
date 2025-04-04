/*
    A-7 ->  write a c program to Create a doubly linked list, accept a key, and delete the node which contains the key element. 
*/

/* 
    Input -> |_Head_| <--> |_00000000_|_1_|_AA_|_00CD0D40_| <--> |_00CD2F98_|_2_|_BB_|_00CD0D68_| <--> |_00CD0D40_|_3_|_CC_|_00000000_| 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DLLNode
{
    int number;
    char name[20];
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

DLLNode* createDLL();
void displayDLL(DLLNode*);
void freeDLL(DLLNode*);
DLLNode* deleteKey(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\tLinked List : ");
    displayDLL(head);

    head = deleteKey(head);

    printf("\n\tLinked List after Deletion of node at Last position : ");
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

DLLNode* deleteKey(DLLNode *head) {

    DLLNode *del = NULL,*temp = NULL;
    temp = malloc(sizeof(DLLNode));
    del = head;

    int pos;
    printf("\n\tEnter key/value ie Node's name and number Eg. 1 AA : ");
    scanf("%d %s", &(temp -> number), temp -> name);
    
    if (temp -> number == del -> number && (!strcmp(temp -> name, del -> name))) {
        head = del -> next;
        head -> prev = NULL;
        free(del);
        free(temp);
        del = NULL, temp = NULL;
    } else {
        for ( ; temp -> number != del -> number && strcmp(temp -> name, del -> name) && del -> next != NULL ; del = del -> next);
        
        if (temp -> number == del -> number && (!strcmp(temp -> name, del -> name))) {
        if (del -> next != NULL ) {
            temp = del -> prev -> next;
            del -> prev -> next = del -> prev -> next -> next;
            free(temp);
            free(del);
            del = NULL,temp = NULL;
        } else {
            del -> prev -> next = NULL;
            free(temp);
            free(del);
            del = NULL, temp = NULL;
        }
        } else {
        printf("\n\tInvalid Key/Value Entered!\n\n");
        exit(0);
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
                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List : 

            |_Head_| <--> |_00000000_|_1_|_AA_|_00CD0D40_| <--> |_00CD2F98_|_2_|_BB_|_00CD0D68_| <--> |_00CD0D40_|_3_|_CC_|_00000000_| 


                    Enter key/value ie Node's name and number Eg. 1 AA : 2 BB

                    Linked List after Deletion of node at Last position : 

            |_Head_| <--> |_00000000_|_1_|_AA_|_00CD0D68_| <--> |_00CD0D40_|_3_|_CC_|_00000000_| 
*/