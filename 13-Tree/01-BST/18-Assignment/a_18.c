/*
    A-18 -> Write a C program to display element in a BST levelwise 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
} node;

node* createNode(int data) {
    node* new = (node*)malloc(sizeof(node));
    if (!new) {
        printf("Memory Error!\n");
        return NULL;
    }

    new->data = data;
    new->left = new->right = NULL;
    return new; 
}

node* insert(node* root, int data) {
    if (!root) {
        return createNode(data);
    }

    if (data < root->data)
        root->left = insert (root->left , data);
    else 
        root->right = insert(root->right,data);
    
    return root;
}

typedef struct QueueNode {
    node* treeNode;
    struct QueueNode *next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Que;

Que* createQueue() {
    Que *q = (Que*)malloc(sizeof(Que));
    q->front = q->rear = NULL;
    return q;
}

void enque(Que *q, node *treeNode) {
    QNode *temp = (QNode*)malloc(sizeof(QNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

node* deque(Que *q) {
    if (q->front == NULL)
        return NULL;
    QNode *temp = q->front;
    node *n = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) 
        q->rear = NULL;
    free(temp);
    return n;
}

int isQueEmpty(Que *q) {
    return (q->front == NULL);
}

void levelOrderTraversal(node *root) {
    if (!root)  return;
    Que *q = createQueue();
    enque(q,root);
    while(!isQueEmpty(q)) {
        node *current = deque(q);
        printf("%d",current->data);
        if(current->left)
            enque(q, current->left);
        if(current->right)
            enque(q, current->right);
    }
    free(q);
}

int main() {
    node *root = NULL;
    int n, value;
    printf("Enter no. of elements to insert in BST : \n");
    scanf("%d",&n);
    printf("Enter %d values : \n",n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d",&value);
        root = insert(root,value);
    }
    printf("Level order traversal of BST : \n");
    levelOrderTraversal(root);

    return 0;
}
