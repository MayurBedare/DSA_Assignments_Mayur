#ifndef NODE_H
#define NODE_H

//Sturcture for a node in the singly linked list
typedef struct Node
{
    int number;
    char name[20];
    struct Node *next;
} Node;

// Function declarations (no definitions!)
Node *createList();
void displayList(Node*);
void freeList(Node*);

#endif