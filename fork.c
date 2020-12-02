//Ejemplo de paralelismo
//Introduciomos nuestras librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main ( int argc, const char argv[]){
    int pid = fork(); /*Numero de identificación del proceso*/

    if (pid) {/* Si esta funcion me devuelve un numero diferente a 0 es el proceso padre*/
        printf ("Loke I am your father. My PID is %d and your PID is %d\n", getpid(), pid);
    }else   /*Soy el hijo*/
    {
         printf ("I am Luke. My PID is %d\n", getpid());
    }
    while (1);
    return 0;
}