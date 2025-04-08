/*
    A-10 -> write a c program to Delete duplicate values(nodes) in doubly linked list.
*/

/*
    Input -> |_Head_| <--> |_00000000_|_1_|_a_|_00BC1388_| <--> |_00BC2FC0_|_2_|_b_|_00BC13B0_| <--> |_00BC1388_|_1_|_a_|_00BC13D8_| <--> |_00BC13B0_|_3_|_c_|_00BC1400_| <--> |_00BC13D8_|_1_|_a_|_00000000_|     
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
DLLNode* deleteDuplicateKeys(DLLNode*);

int main() {
    
    DLLNode *head = NULL;

    head = createDLL();

    printf("\n\tLinked List : ");
    displayDLL(head);

    head = deleteDuplicateKeys(head);

    printf("\n\tLinked List after Deletion of duplicate nodes : ");
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

DLLNode* deleteDuplicateKeys(DLLNode *head) {

    DLLNode *p1 = NULL, *p2 = NULL, *t = NULL;
    for (p1 = head ; p1 != NULL ; p1 = p1 -> next) {
        for (p2 = p1 -> next ; p2 != NULL ; p2 = p2 -> next) {
            if (p1 -> number == p2 -> number && !(strcmp(p1 -> name, p2 -> name))) {
                t = p2;
                p2 = p2 -> prev;
                if (t -> next == NULL) {
                    t -> prev -> next = NULL;
                } else {
                    t -> prev -> next = t -> next;
                    t -> next -> prev = t -> prev;
                }
                free(t);
                t = NULL;
            }
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
                    Enter Number and Name : 1 a
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 2 b
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 1 a
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 3 c
            Do you want to enter more records ( yes(1) / no(0) ) : 1

                    Enter Number and Name : 1 a
            Do you want to enter more records ( yes(1) / no(0) ) : 0

                    Linked List :

            |_Head_| <--> |_00000000_|_1_|_a_|_00BC1388_| <--> |_00BC2FC0_|_2_|_b_|_00BC13B0_| <--> |_00BC1388_|_1_|_a_|_00BC13D8_| <--> |_00BC13B0_|_3_|_c_|_00BC1400_| <--> |_00BC13D8_|_1_|_a_|_00000000_|     


                    Linked List after Deletion of duplicate nodes :

            |_Head_| <--> |_00000000_|_1_|_a_|_00BC1388_| <--> |_00BC2FC0_|_2_|_b_|_00BC13D8_| <--> |_00BC1388_|_3_|_c_|_00000000_|
*/