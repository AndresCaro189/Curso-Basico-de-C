#include  <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  Node
{
    int number;
    struct Node*next;
}NODE;

NODE * createNode (int number){
   
    NODE * newNode;
    newNode = malloc (sizeof(NODE) );
    newNode-> next = NULL;
    newNode-> number = number;

    return newNode;
}

int main (int argc, const char* argv[]){
    NODE* start = NULL, *current;
    char goOn;
    int listSize = 0, number;

    do{
        printf("La lista contiene %d nodos. Ingrese el siguiente numero (o para finalizar\n", listSize);
            scanf("%d", &number );
            if (number){
                if (!start){
                    start = createNode(number);
                    listSize++;
                }else{
                    current = start;
                    while (current ->next)
                    {
                        current = current->next;
                    }
                    current->next=createNode(number);
                    listSize++;
                }
                goOn= 1;
            }else {
                goOn=0;
            }
    }while (goOn);
    
    
    while (current)
    {
        current = start;
        printf("La lista contiene los numeros: \n");
        printf("%d", current->number);
        printf(current->next ? "," : "\n");
        current = current->next;
    }
    
    return 0;
}










