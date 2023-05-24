#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "queue.h"

void create(Queue *qu){
    qu->head = NULL;
    qu->tail = NULL;
}
int isEmpty(Queue qu){
    return qu.tail == NULL && qu.head == NULL ? 1 : 0;
}
void enqueue(Queue *qu, element e){
    Node *new;
    new = (Node*)malloc(sizeof(Node));
    if(isEmpty(*qu)){
        qu->head = new;
        qu->head->e = e;
        qu->head->next = NULL;
        qu->tail = new;
    }else{
        qu->tail->next = new;
        qu->tail = new;
        qu->tail->next = NULL;
        qu->tail->e = e;
    }
}
element dequeue(Queue *qu){
    element copy_e;
    if(isEmpty(*qu)){
        printf("Underflow\n");
        return copy_e;
    }else{
        Node *aux;
        if(qu->tail == qu->head) qu->tail = NULL;
        copy_e = qu->head->e;
        aux = qu->head;
        qu->head = aux->next;
        free(aux);
        return copy_e;
    }
}
void show(Queue *qu){
    Node *aux = qu->head;
    while(aux != NULL){
        printf("%d\n", aux->e);
        aux = aux->next;
    }
}
void clean(Queue *qu){
    while(!isEmpty(*qu)){
        dequeue(qu);
    }
}