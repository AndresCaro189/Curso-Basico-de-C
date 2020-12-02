/*
1- Crear pointer para saber que hay en front y rear
2- Colocar estos valores en -1 al inicializar
3- incrementar en 1 el valor de "rear"
    Cuando agreguemos un elemento
4- Retornar el valor de front al quitar un elemento
    e incrementar en 1  el valor de 
    front al usar dequeve
5- Antes de agregar un elemento revisar si hay espacio
6- Antes de remover un elemento revisamos que existe elementos
7- asegurarnos de que al remover todos los elementos
    resetea nuestro front y rear en 1
    y agregar nuestro front y rear a -1 
    y agregar el valor de 0 a front al hacer nuestro primer enqueve
    */


#include<stdio.h>
#define SIZE 5
int values[size], front = -1, rear=-1;

void enQueue(int value){
    if(rear == SIZE-1)
        printf("Nuestro Queve esta lleno \n" );
    else {
        if(front==-1)
            front= 0;
        rear++;
        values[rear] = value;
        printf("Se inserto el valor %d correctamente \n", value);
    }
}

void deQueue(){
    if(front == -1)
        printf("Nuestro Queve esta vacio \n" );
    else{
        printf("Se elimino el valor %d \n", values[front]);
        front++;
        if (front > rear)
        front = rear = -1;
    }
}

main(int argc, char const *argv[])
{
    enQueue (1);
        enQueue (2);
            enQueue (3);
                enQueue (4);
                    enQueue (5);
    deQueue ();
        deQueue ();
            deQueue ();
                deQueue ();
                    deQueue ();
    enQueue (10);
    return 0;
}