/*
    A-1 ->  Write a C program to create a Graph using Adjacency Matrix
*/

#include<stdio.h>
#include<stdlib.h>

void A_matrix(int **,int);
void print(int **,int);

int main() {
    int ver;
    printf(" Enter number of vertices : ");
    scanf("%d",&ver);
    //Allocate memory for adjacency matrix
    int **a = (int**)malloc(ver *sizeof(int*));
    for (int i = 0 ; i < ver ; i++) {
        a[i] = (int*)malloc(ver *sizeof(int));
        for (int j = 0 ; j < ver ; j++) {
            a[i][j] = 0;
        }
    }
    A_matrix(a,ver);
    print(a,ver);
    return 0;
}

void A_matrix(int **a,int ver) {
    int i, j, ans;
    do {
        printf("Enter an edge (from to) :");
        scanf("%d %d",&i,&j);

        if(i >= 0 && i < ver && j>=0 && j < ver) {
            a[i][j] = 1;
            a[j][i] = 1; // undirected graph
        }
        else {
            printf("Invalid edge !\n");
        }
        printf("Add more edges ? (1 for yes / 0 for no): ");
        scanf("%d",&ans);
    }while(ans != 0);
}

void print(int **a,int ver) {
    int totalDeg = 0;
    printf("\n Adjacency matrix : \n");
    for (int i = 0; i < ver ; i++) {
        int deg = 0;
        for (int j = 0; j < ver ; j++) {
            printf("%d",a[i][j]);
            if (a[i][j] == 1)
                deg++;
        }
        totalDeg += deg;
        printf("1. Vertex %d Degree = %d \n",i,deg);
    }
    printf("\n Total Degree(All vetices) = %d \n",totalDeg);
}

