/*
    A-2 ->  Write a C program to create a Graph using Adjacency List
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct AdjListEdge {
    int no;
    struct AdjListEdge* next;
}edge;

void A_List(edge*,int);
void print(edge*,int);

int main() {
    edge *head = NULL;
    int ver,i,ch;
    printf("\n Enter the number of vertices : ");
    scanf("%d",&ver);
    head = (edge*)malloc((ver+1)*sizeof(edge)); 

    if (head = NULL) {
        printf("Memory Allocation Failed! \n");

        return 1;
    }
    for (i = 1; i <= ver ; i++) {
        head[i].no = i;
        head[i].next = NULL;
    }
    do {
        printf("\n **************** ");
        printf("\n 1. Add Edge ");
        printf("\n 2. Print Adjancy List");
        printf("\n 3. Exit");
        printf("\n **************** ");
        printf("\n Enter you choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                A_List(head,ver);
                break;
            case 2:
                print(head,ver);
                break;
            case 3:
                exit(0);
            default : 
                printf("\n Invalid choice!");
        }
    }while(1);

    return 0;   
}

void A_List(edge*a,int ver) {
    int i,j;
    edge *nw,*e;
    printf("\n Enter edge (from to):");
    scanf("%d %d",&i,&j);
    if (i <= ver && j <= ver && i>0 && j>0) {
        nw = (edge*)malloc(sizeof(edge));
        nw -> no = j;
        nw -> next = NULL;
        if (a[i].next == NULL) {
            a[i].next = nw;
        }
        else {
            for (e = a[i].next ; e != NULL ; e = e -> next) {
                if (e->no == j) {
                    printf("\n Edge already exists ");
                    free(nw);
                    return;
                }
                if(e->next == NULL) {
                    e->next = nw;
                    return;
                }
            }
        }
    }
    else {
        printf("\n Invalid Edge ");
    }
}

void print(edge* a,int ver) {
    int i;
    edge* e;
    for (i = 1; i <= ver ; i++) {
        printf("\n vertex %d --> ",a[i].no);

        for (e = a[i].next; e!= NULL ; e = e->next) {
            printf("%d",e->no);
        }
        printf("\n");
    }
}

