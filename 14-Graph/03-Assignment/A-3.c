/*  A-3 ->  Write a menu-driven C program to perform the following operations on an undirected graph using an adjacency list/matrix:
            Add an edge between two vertices
            Display the graph
            Traverse the graph using BFS
            Traverse the graph using DFS
            Check if an edge exists between two vertices
            Check if a path exists between two vertices         */

#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListEdge {
    int no;
    struct AdjListEdge* next;
} edge;

void A_List(edge*,int);
int findIndex(edge*,int,int);
void bfs(edge*,int[],int[],int);
void dfs(edge*,int[],int[],int);
int findEdge(edge*,int);
int findPath(edge*,int,int,int);

void print(edge*, int);

int main() {
    edge *head = NULL;
    int ver, i, ch,n1,n2;

    printf("\n\t Enter the number of vertices : ");
    scanf("%d", &ver);

    int *arr = (int*)calloc(ver,sizeof(int));
    if (arr == NULL) {
        printf("\n\t Memory Allocation Failed! \n");
        return 1;
    }
    int *visit = (int*)calloc(ver,sizeof(int));
    if (visit == NULL) {
        printf("\n\t Invalid Address! ");
        exit(1);
    }

    head = (edge*)malloc((ver + 1) * sizeof(edge)); 

    if (head == NULL) {
        printf("\n\t Memory Allocation Failed! \n");
        return 1;
    }

    for (i = 1; i <= ver; i++) {
        head[i].no = i;
        head[i].next = NULL;
    }

    do {
        printf("\n\t --------------------------------------- ");
        printf("\n\t 1. Add Edge ");
        printf("\n\t 2. Print Adjacency List");
        printf("\n\t 3. BFS ");
        printf("\n\t 4. DFS ");
        printf("\n\t 5. Find the edge between any 2 vertices ");
        printf("\n\t 6. Find the path between any 2 vertices ");
        printf("\n\t 7. Exit");
        printf("\n\t --------------------------------------- ");
        printf("\n\t Enter your choice: ");
        scanf("%d", &ch);
        printf("\t --------------------------------------- \n");

        switch (ch) {
            case 1:
                A_List(head,ver);
                break;
            case 2:
                print(head,ver);
                break;
            case 3:
                bfs(head,arr,visit,ver);
                break;
            case 4:
                dfs(head,arr,visit,ver);
                break;
            case 5:
                i = 0;
                i = findEdge(head,ver);
                if (i == 1) printf("\n\t Edge is present between 2 vertices \n");
                else if (i == -1);
                else    printf("\n\t There is no Edge present between 2 vertices \n");

                break;
            case 6:
                printf("\n\t Enter Vertice 1 : ");
                scanf("%d",&n1);
                i = findIndex(head,n1,ver);
                if (i == 0) {
                    printf("\n\t The Vertice 1 is not exist in the given Graph! \n");
                    break;
                }
                printf("\n\t Enter Vertice 2 : ");
                scanf("%d",&n2);
                i = findIndex(head,n2,ver);
                if (i == 0) {
                    printf("\n\t The Vertice 2 is not exist in the given Graph! \n");
                    break;
                }
                i = 0;
                i = findPath(head,ver,n1,n2);
                if (i == 1) printf("\n\t Path is present between 2 vertices \n");
                else    printf("\n\t There is no Path present between 2 vertices \n");

                break;
            case 7:
                printf("\n\t Program Exitted Successfully...\n\n");
                exit(0);
            default: 
                printf("\n\t Invalid choice!");
        }
    } while (1);

    return 0;   
}

void A_List(edge* a, int ver) {
    int i, j;
    edge *nw, *e;

    printf("\n\t Enter edge (from to): ");
    scanf("%d %d", &i, &j);

    if (i <= ver && j <= ver && i > 0 && j > 0) {
        nw = (edge*)malloc(sizeof(edge));
        nw->no = j;
        nw->next = NULL;

        if (a[i].next == NULL) {
            a[i].next = nw;
        } else {
            for (e = a[i].next; e != NULL; e = e->next) {
                if (e->no == j) {
                    printf("\n\t Edge already exists ");
                    free(nw);
                    return;
                }
                if (e->next == NULL) {
                    e->next = nw;
                    return;
                }
            }
        }
    } else {
        printf("\n\t Invalid Edge ");
    }
}

int findIndex(edge* head,int x,int n) {
    for (int i = 1; i <= n ; i++) {
        if (head[i].no == x) return i;
    }
    return 0;
}

void bfs(edge* head, int arr[], int visit[],int n) {
    int front = -1, rear = -1;

    int m = 0,index = 1;
    front = 0;

    printf("\n\t The BFS of given Graph : ");
    for (int i = 1 ; i <= n ; i++) {
        edge*x = &head[index];
        while (x != NULL) {
            int flag = 0;
            for (int k = 0 ; k < m ; k++) {
                if (visit[k] == x -> no) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                visit[m++] = x -> no;
                arr[(++rear)%n] = x -> no;
            }
            x = x -> next;
        }
        printf("%d ",arr[front++]);
        index = findIndex(head,arr[front],n);
    }
    printf("\n");

    free(visit);
    visit = NULL;
}

void dfs(edge* head, int arr[], int visit[], int n) {
    int top = -1;
    int m = 0,index = 1;

    printf("\n\t The DFS of given Graph : ");
    for (int i = 1 ; i <= n ; i++) {
        edge*x = &head[index];
        while (x != NULL) {
            int flag = 0;
            for (int k = 0 ; k < m ; k++) {
                if (visit[k] == x -> no) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                visit[m++] = x -> no;
                arr[++top] = x -> no;
                break;
            }
            x = x -> next;
        }
        printf("%d ",arr[top]);
        index = findIndex(head,arr[top],n);
    }
    printf("\n");

    free(visit);
    visit = NULL;
}

int findEdge(edge* head, int n) {
    int n1,n2,index;
    printf("\n\t Enter Vertice 1 : ");
    scanf("%d",&n1);
    
    index = findIndex(head,n1,n);
    if (index == 0) {
        printf("\n\t The Vertice 1 is not exist in the given Graph! \n");
        return -1;
    }

    printf("\n\t Enter Vertice 2 : ");
    scanf("%d",&n2);

    index = findIndex(head,n2,n);
    if (index == 0) {
        printf("\n\t The Vertice 2 is not exist in the given Graph! \n");
        return -1;
    }
    
    for (edge*x = head[findIndex(head,n1,n)].next ; x != NULL ; x = x -> next)
        if (n2 == x -> no)  return 1;

    return 0;
}

int findPath(edge* head, int n,int n1,int n2) {
    
    for (edge*x = head[findIndex(head,n1,n)].next ; x != NULL ; x = x -> next) {
        if (n2 == x -> no)  return 1;
        else {
            for (edge *y = &head[findIndex(head,x -> no,n)] ; y != NULL ; y = y -> next) {
                if (n2 == y -> no)  return 1;
            }
        }
    }

    return 0;
}

void print(edge* a, int ver) {
    int i;
    edge* e;

    for (i = 1; i <= ver; i++) {
        printf("\n\t vertex %d --> ", a[i].no);

        for (e = a[i].next; e != NULL; e = e->next) {
            printf("%d ", e->no);
        }
        printf("\n");
    }
}
