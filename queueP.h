
#define SIZE_P 3

typedef struct Element{
    int value;
    char name[50];
    int priority;
}element;

#include "queue.h"

typedef struct QueueP{
    int sqp;
    Queue QP[SIZE_P];
}queuep;

void createQP(queuep *qp);
void insertInPriority(queuep *qp, element e);
int isEmptyQP(queuep qp);
element deleteInPriority(queuep *qp);
element deleteQP(queuep *qp);

#include "queueP.c"