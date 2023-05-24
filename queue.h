typedef struct node{
    element e;
    struct node *next;
}Node;

typedef struct queue{
    Node *head;
    Node *tail;
}Queue;


void create(Queue *qu);
int isEmpty(Queue qu);
void enqueue(Queue *qu, element e);
element dequeue(Queue *qu);
void show(Queue *qu);
void clean(Queue *qu);

#include "queue.c"

