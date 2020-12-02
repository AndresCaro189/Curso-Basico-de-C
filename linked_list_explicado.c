#include <stdio.h>
#include <stdlib.h>

//definir el nodo
typedef struct Node{
    int number; //Lista de numeros
    struct Node * next; //estructura autoreferenciada
}NODE; //en vez de "struct Node" solo pones NODE

//crear funcion que crea un nuevo nodo
NODE * createNode( int number)
{
    NODE * newNode;
    newNode = malloc(sizeof(NODE));
    newNode->next = NULL; //el siguiente del nodo sera NULL
    newNode->number = number; //asignar el dato number al puntero newNode
    return newNode;
}

int main(int argc,const char * argv[]){
    //creando la lista
    NODE * start = NULL,*current, *sig; //crea puntero start con NULL para poner la lista vacia
    // current puntero auxiliar

    char goOn; //bandera de continuacion, goOn puede ser int tambien
    int listSize = 0,number; //listSize es el tamaño de la lista
    do{
        printf("La lista tiene %d nodos. Ingrese 0 para terminar\n",listSize);
        scanf("%d",&number);
        if(number){ //si el number es distinto de 0 continua
            if(!start){ //si start = NULL se crea el NODO (lista vacia)
                    start = createNode(number); //crea el nodo start
                    printf("primer nodo start->number %d\n",start->number);
                    printf("primer nodo start->next %p\n",start->next);
               listSize++;
            } else{ //si lista no esta vacia,
                //con el nodo que se acaba de crear, apuntarlo desde el final de la lista
                current = start; //se crea current para no perder el inicio de la lista
                printf("else current->number %d\n",current->number);
                printf("else current->next %p\n",current->next);

                while (current->next){ // mientras current tenga algo en su next
                    printf("while antes current->number %d\n",current->number);
                    printf("while antes current->next %p\n",current->next);
                    printf("current = current->next\n");
                    current = current->next; // current sea igual al siguiente
                    printf("while despues current->number %d\n",current->number);
                    printf("while despues current->next %p\n",current->next);
                    //avanza entre los nodos, termina cuando no tiene siguiente
                }
                //el siguiente sera el nodo que se creara
                current->next=createNode(number); //asi queda encadenado
                printf("Encadena la lista current->number %d\n",current->number);
                printf("Encadena la lista current->next %p\n",current->next);
                listSize++;
            }

            goOn = 1;
        }else{
            goOn = 0;
        }
    }while(goOn); //se detiene si goOn es 0

    current = start; //inicializa el nodo current con el inicio;
    printf("Inicializa current->number %d\n",current->number);
    printf("Inicializa current->next %p\n",current->next);
    printf("La lista tiene los numeros:\n");
    while (current){ //mientras current no sea null
        printf("%d %p",current->number, current->next); //desreferencia current accede a number
        printf(current->next?",":"\n"); //pregunta si existe numero siguiente
        //si es verdadero pone una , y sigue con el siguiente valor sino pone \n
        current = current->next; //para que la repitiva avance
    }

    //liberar memoria
    current = start;
    printf("\nLiberar memoria\n");
    while (current->next!= NULL){ //mientras current no sea null
        printf("\ndireccion current next: %p\n",current->next);
        printf("direccion current number: %d\n",current->number);
        sig = current->next; //quedarnos con el nodo
        printf("Asigna current->next a sig\n");
        printf("direccion sig next: %p\n",sig->next);
        printf("direccion sig number: %d\n",sig->number);
        free(current); //libera el nodo actual
        printf("Libera current\n");
        current = sig; //current sera sig
        printf("Asigna sig a current\n");
        printf("valor current->next: %p\n",current->next);
        printf("valor current->number: %d\n",current->number);
    }

    return 0;
}