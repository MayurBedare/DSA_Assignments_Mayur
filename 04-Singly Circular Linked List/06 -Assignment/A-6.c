/*
    A-6 ->  write a c program to Create a circular singly linked list and delete the node which key matches the user's key
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SCLLNode
{
    int number;
    char name[20];
    struct SCLLNode *next;
} SCLLNode;

SCLLNode* createSCLL();
SCLLNode* deleteKey(SCLLNode*);
void displaySCLL(SCLLNode*);
void freeSCLL(SCLLNode*);


int main() {
   
    SCLLNode *last = NULL;

    printf("\n\t ***** Delete a node at the given key : Singly Circular Linked List ***** \n");

    printf("\n\t --------------------------------------------------------");
    printf("\n\t Create a linked list to delete a node at the given key : \n");
    printf("\t -------------------------------------------------------- \n");

    last = createSCLL();

    printf("\n\t -------------------------------------------------------- \n");
    printf("\n\t Linked List : ");
    displaySCLL(last);
    
    while (1) {
        int ch; 
        printf("\n\t ---------------------------------");
        printf("\n\t 1. Delete a node at the given key ");
        printf("\n\t 2. Exit ");
        printf("\n\t ---------------------------------");
        printf("\n\t Enter your choice : ");
        scanf("%d",&ch);
        printf("\t ----------------------------------- \n");
        
        switch (ch) {
            case 1:
                if (last == NULL) {
                    printf("\n\t Linked List is Empty! \n\n");
                    exit(0);
                }
                last = deleteKey(last);
                break;
            
            case 2:
                freeSCLL(last);
                last = NULL;
                printf("\n\t Program Exited Successfully. \n\n");
                exit(0);

            default: 
                printf("\n\t Invalid Choice Entered! \n");
                break;
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
        nw = (SCLLNode*)malloc(sizeof(SCLLNode));
        if (nw == NULL) {
            printf("\n\t Memory Allocation Failed! \n\n");
            exit(1);
        }

        printf("\n\t Enter Number and Name : ");
        scanf("%d", &(nw -> number));
        getchar();
        fgets(nw -> name,20,stdin);
        nw -> name[strcspn(nw -> name,"\n")] = '\0';

        nw -> next = nw;

        if (head == NULL) {
            head = nw;
        }
        else {
            last -> next = nw;
            nw -> next = head;
        }
        
        last = nw;

        printf("\n\t Do you want to enter more records ( yes(1) / no(0) ) : ");
        scanf("%d", &cnt);
    } while (cnt != 0);

    return last;

}

SCLLNode* deleteKey(SCLLNode *last) {

    SCLLNode *p = NULL,*prev = NULL;
    int t,flag = 0;
    p = last -> next;

    printf("\n\t Enter the kay of the node to be deleted eg. 1 AA -> key is 1 : ");
    scanf("%d", &t);

    if (p -> number == t) {
        flag = 1;
        if (p == last) {
            free(p);
            p = NULL;
            printf("\n\t Linked List is Empty! \n");
            return p;
        }
        last -> next = p -> next;
        free(p);
        p = NULL;
    } else {
        for (prev = p,p = p -> next ; p -> number != t && p != last ; p = p -> next,prev = prev -> next);

        if (p -> number == t) {
            flag = 1;
            if (p != last) {
                prev -> next = p -> next;
                free(p);
                p = NULL;
            } else {
                prev -> next = p -> next;
                free(p);
                p = NULL;
                last = prev;
            }
        } else {
            printf("\n\t Key not found! \n");
        }
    }

    if (flag == 1) {
        printf("\n\t Linked List after deletion of the key : ");
        displaySCLL(last);
    }

    return last;

}

void displaySCLL(SCLLNode *last) {
    
    SCLLNode *d = NULL;
    d = last -> next;
    printf("\n\n\t |_Head_| ");

    for ( ; d != last ; d = d -> next )
        printf("--> |_%d_|_%s_|_%p_| ", d -> number, d -> name, d -> next);

    printf("--> |_%d_|_%s_|_%p_| <-- |_last_|", d -> number, d -> name, d -> next);

    printf("\n");

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
