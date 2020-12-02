//ejemplo de pipes
//Agregamos librerias
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*Agregamos libreria para usar for*/
#include <string.h>
#include <wait.h>

#define MSGSIZE 16 /*Definición de una macro para el tamaño del mensaje que estara leyendo el mensaje cada 16 caracteres*/

int main (int argc, const char argv[]){
    FILE * in; 
    int pid, p[2];
    /*la función pipe va devolver los numeros que identifique en el sistema operativo*/
    if (pipe(p) < 0){
        printf("No pude crear los pipes\n");
        return -2;
    }

    if (!(in= fopen(argv[1], "r"))){
        printf  ("No pude leer el archivo %s\n", argv[1]);
        return -1;
    }
/*si soy el proceso padre voy a crear un buffer del tamaño de la constante ya definida*/
    if (pid = fork()){
        char buffer[MSGSIZE];
        printf ("++ Soy el padre. Voy a leer desde %s\n", argv[1]);
        while (fgets(buffer, MSGSIZE, in)){
            printf("lei %s. Diem %d: Cual es el caracter mas grande?\n", buffer, pid);
            write (p[1],buffer, MSGSIZE);
        }
        close(P[1]); /*Cerramos el pipe para que no se pueda leer y escribir en el*/
        printf ("Esperando a mis hijos\n");
        wait(NULL);
        fclose(in);
    }else{ /*Ejecutamos los arreglos de nuestro hijo*/
        close(p[1]);/*Cierre de la escritura*/
        printf ("soy el hijo. Espero que aparezca algo en el pipe\n");
        char buffer [MSGSIZE], max;

        while (read(p[0], buffer, MSGSIZE)>0){
            printf("Lei '%s' desde el pipe\n", buffer);
            max =buffer[0];
            for (int i = 0; i< MSGSIZE; i++){
                if (buffer[i]>max){
                    max =buffer[i];
                }
                printf ("Max; '%c'\n", max);

            }

        }
   
    }
    return 0; 
    
}
