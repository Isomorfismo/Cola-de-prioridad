#include <stdio.h>
#define SIZE_P 3

void createQP(queuep *qp){
    qp->sqp = SIZE_P;
    for(int i = 0; i < qp->sqp; i++){
        create(&qp->QP[i]);
    } 
}
void insertInPriority(queuep *qp, element e){
    if(e.priority < 0 || e.priority >= qp->sqp){
        printf("Invalid priority\n");
    }
    else{
        enqueue(&qp->QP[e.priority], e);
    }
}
int isEmptyQP(queuep qp){
    int i = 0;
    while(i < qp.sqp){
        if(!isEmpty(qp.QP[i])){
            return 0;
        }
        i++;
    }
    return 1;
}
element deleteInPriority(queuep *qp){
    element e;
    if(isEmptyQP(*qp)){
        printf("Underflow\n");
        return e;
    }
    else{
        for(int i = 0; i < qp->sqp; i++){
            if(!isEmpty(qp->QP[i])){
                e = dequeue(&qp->QP[i]);
                return e;
            }
        }
    }
}
element deleteQP(queuep *qp){
    if(!isEmptyQP(*qp)){
        for(int i = 0; i < qp->sqp; i++){
            deleteInPriority(&qp->QP[i]);
        }
    }
}