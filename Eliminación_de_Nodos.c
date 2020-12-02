#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int number;
	struct Node * next;
} NODE;

NODE * createNode(int number){
	NODE * newNode;
	newNode = malloc(sizeof(NODE));
	newNode->next = NULL;
	newNode->number = number;
	return newNode;
} 

void showNodes(NODE * start, int listSize){
	if(listSize){ 
		NODE * current = start;
		printf("||================================||\n"); 
		printf("|| La lista contiene los numeros: || \n");
		printf("||================================||\n\n");
		while (current){
			printf("%d", current->number );
			printf(current->next ? ", " : ".\n\n");
			current = current->next;
		}
	} else {
		printf("||=======================||\n"); 
		printf("|| ¡La lista esta vacia! ||\n");
		printf("||=======================||\n\n"); 
	}
}

void eraseNode(NODE * start, int number, int listSize){
	NODE * current = start;
	NODE * previousNode, * nextNode;
	int goOn = 1, nodeIndex = 1;
	
	while ( goOn ){
		if(current->number != number && current->next != NULL ){
			previousNode = current;
			current = current->next;
			nextNode = current->next;
			goOn = 1;
			nodeIndex++;
		} else {
			if (current->number == number){	
				if (nodeIndex == 1){
					start = current->next;
					free(current);
					listSize--;
				} else {
					previousNode->next = nextNode;
					free(current);
					listSize--;
				}
			}else{
				printf("||======================||\n"); 
				printf("|| ¡Ese nodo no existe! ||\n");
				printf("||======================||\n\n"); 
			}
				goOn = 0;
			}
	}
	showNodes(start, listSize);
}

int main( int argc, const char * argv[]){
	NODE * start = NULL, * current, *next;
	int goOn;
	int listSize = 0, nodeToErase;
	char boolean[100], number[100]; 
	 do {
		printf("||=============================||\n"); 
	 	printf("|| La lista contiene %d nodos.  ||\n|| coloca el siguiente numero. ||\n||      (0 para terminar)      ||\n", listSize );
		printf("||=============================||\n\n"); 
		scanf("%s", number);
		if ( atoi(number) ){
			if ( !start ){
				start = createNode( atoi( number ) );
				listSize++;	
			} else {
				current = start;
				while( current->next ){
					current = current->next;
				}
				current->next = createNode( atoi( number ) );
				listSize++;
			}
			goOn = 1;
		} else { 
			if ( strcmp(number, "0") == 0 ){
				printf("||=============================||\n");
				printf("|| ¡Has terminado de ingresar! ||\n");
				printf("||=============================||\n\n");
				goOn = 0;
			} else {
				printf("||=================================||\n");
				printf("||¡El input no es un numero valido!||\n||     ingresa un numero valido    ||\n");
				printf("||=================================||\n\n");
				goOn = 1;
			}
		 	
		}
	} while ( goOn );

	showNodes(start, listSize);

	if (listSize){
		do {
			goOn = 1;
			printf("||================================||\n"); 
			printf("|| ¿Quieres borrar un nodo? (S/N) ||\n");
			printf("||================================||\n\n"); 
			scanf("%99s", boolean);
			if (strlen(boolean) == 1 ){
				if( strcmp( boolean, "S" ) == 0 || strcmp(boolean, "s") == 0 ){
					printf("||=========================================||\n"); 
					printf("||        ¿Cual nodo quieres borrar?       ||\n|| (coloca el numero contenido en el nodo) ||\n");
					printf("||=========================================||\n\n"); 
					scanf("%d", &nodeToErase);
					printf("||=============================||\n"); 
					printf("|| El nodo con %d sera borrado  ||\n||             ...             ||\n", nodeToErase);
					printf("||=============================||\n\n"); 
					eraseNode(start, nodeToErase, listSize);
					goOn = 0;
				} else if ( strcmp( boolean, "N") == 0 || strcmp( boolean, "n" ) == 0) {
					printf("||======================||\n"); 
					printf("|| Ningun nodo borrado. ||\n");
					printf("||======================||\n\n"); 
					goOn = 0;
				} else {
					printf("||==================================||\n"); 
					printf("|| Coloca 'S' para si y 'N' para no ||\n");
					printf("||==================================||\n\n"); 
					goOn = 1;
				}	
			} else {
				printf("||==================================||\n"); 
				printf("||       Input demasiado largo      ||\n|| Coloca 'S' para si y 'N' para no ||\n");
				printf("||==================================||\n\n"); 
				goOn = 1;
			}
		}while ( goOn );
	}

	 current = start;
	 while(current){
		next = current->next;
		free(current);
		current = next;
	}
	 return 0;
}