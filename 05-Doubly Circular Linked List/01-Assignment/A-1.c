/*
    A-1 ->  write a c program to Create and display circular doubly linked list.
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
void displayDLL(DLLNode*);
void freeDLL(DLLNode*);

int main() {
   
    DLLNode *last = NULL;

    last = createDLL();

    printf("\n\t Doubly Circular Linked List : ");
    displayDLL(last);
    
    freeDLL(last);

    return 0;
    
}

DLLNode* createDLL() {

    DLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = malloc(sizeof(DLLNode));

        printf("\n\t Enter Number and Name : ");
        scanf("%d %s", &(nw -> number), nw -> name);

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

void displayDLL(DLLNode *last) {

    DLLNode *d = NULL;
    d = last -> next;
    printf("\n\n|_Head_| ");
    printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);


    for (d = d -> next ; d != last -> next ; d = d -> next )
        printf("<--> |_%p_|_%d_|_%s_|_%p_| ", d -> prev, d -> number, d -> name, d -> next);

    printf(" <--> |_last_|");

    printf("\n\n");

}

void freeDLL(DLLNode *last) {

    if (last == NULL)
        return;

    DLLNode *f = NULL;
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
                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Doubly Circular Linked List : 

            |_Head_| <--> |_00CD13A0_|_1_|_AA_|_00CD1378_| <--> |_00CD2FB8_|_2_|_BB_|_00CD13A0_| <--> |_00CD1378_|_3_|_CC_|_00CD2FB8_|  <--> |_last_|                          
*/