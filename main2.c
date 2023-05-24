#include <stdio.h>
#include <string.h>
#include "queueP.h"

int main(){
    queuep qp;
    element pedido;
    int opcion, cantidad = 30;
    createQP(&qp);
    while(opcion != 2 || !isEmptyQP(qp)){
        printf("Menu de pedidos\n");
        printf("1. Agregar pedido\n");
        printf("2. Salir\n");
        scanf("%d", &opcion);
        if(opcion == 1){
            printf("Ingrese el nombre del cliente: ");
            scanf("%s", pedido.name);
            printf("Ingrese el valor del pedido: ");
            scanf("%d", &pedido.value);
            printf("Ingrese la prioridad del pedido: ");
            scanf("%d", &pedido.priority);
            insertInPriority(&qp, pedido);
        }else{
            //Atender pedidos
            while(!isEmptyQP(qp)){
                if(cantidad <= 0){
                    printf("No hay mas productos disponibles\n");
                    deleteQP(&qp);
                    break;
                }else{
                    pedido = deleteInPriority(&qp);
                    printf("Pedido atendido\n");
                    printf("Nombre del cliente: %s\n", pedido.name);
                    printf("Valor del pedido: %d\n", pedido.value);
                    printf("Prioridad del pedido: %d\n", pedido.priority);
                    cantidad -= pedido.value;
                    printf("Cantidad disponible: %d\n", cantidad);
                }
            }
        }
    }

    return 0;
}