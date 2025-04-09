/*
    A-6 ->  write a c program to Create a circular doubly linked list and delete the node which key matches the user's key
*/

/*
    Input -> |_Head_| <--> |_008213B0_|_1_|_AA_|_00821388_| <--> |_00822FC0_|_2_|_BB_|_008213B0_| <--> |_00821388_|_3_|_CC_|_00822FC0_|  <--> |_last_|
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
DCLLNode* deleteKey(DCLLNode*);
void displayDCLL(DCLLNode*);
void freeDCLL(DCLLNode*);

int main() {
   
    DCLLNode *last = NULL;

    last = createDCLL();

    printf("\n\t Doubly Circular Linked List : ");
    displayDCLL(last);

    last = deleteKey(last);

    if (last == NULL) {
        printf("\n\t Doubly Circular Linked List is empty!\n\n");
        exit(0);
    }

    printf("\n\t Doubly Circular Linked List after deletion of the key/value : ");
    displayDCLL(last);
    
    freeDCLL(last);

    return 0;
    
}

DCLLNode* createDCLL() {

    DCLLNode *head = NULL,*nw = NULL, *last = NULL;
    
    int cnt;

    do
    {
        nw = malloc(sizeof(DCLLNode));

        printf("\n\tEnter Number and Name : ");
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

DCLLNode* deleteKey(DCLLNode *last) {

    DCLLNode *p = NULL,*prev = NULL,t;
    p = last -> next;

    printf("\n\t Enter the kay/value of the node to be deleted eg.1 AA : ");
    scanf("%d %s", &(t.number), t.name);

    if (p -> number == t.number && !(strcmp(p -> name, t.name))) {
        if (p == last) {
            free(p);
            p = NULL;
            return p;
        }
        last -> next = p -> next;
        p -> next -> prev = last;
        free(p);
        p = NULL;
    } else {
        for (prev = p,p = p -> next ; p -> number != t.number && (strcmp(p -> name, t.name)) && p != last ; p = p -> next,prev = prev -> next);

        if (p -> number == t.number && !(strcmp(p -> name, t.name))) {
            if (p != last) {
                prev -> next = p -> next;
                p -> next -> prev = prev;
                free(p);
                p = NULL;
            } else {
                prev -> next = p -> next;
                prev -> next -> prev = prev;
                free(p);
                p = NULL;
                last = prev;
            }
        } else {
            printf("\n\t Key/Value not found!\n\n");
            exit(0);
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
                    Enter Number and Name : 1 AA
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 BB
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 CC
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Doubly Circular Linked List :

            |_Head_| <--> |_008213B0_|_1_|_AA_|_00821388_| <--> |_00822FC0_|_2_|_BB_|_008213B0_| <--> |_00821388_|_3_|_CC_|_00822FC0_|  <--> |_last_|


                    Enter the kay/value of the node to be deleted eg.1 AA : 2 BB

                    Doubly Circular Linked List after deletion of the key/value :

            |_Head_| <--> |_008213B0_|_1_|_AA_|_008213B0_| <--> |_00822FC0_|_3_|_CC_|_00822FC0_|  <--> |_last_|
*/