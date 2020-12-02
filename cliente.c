//Sockets, conección entre cliente y servidor 
//Ingresamos librerias 
#include <sys/socket.h> //Llibreria de los Sockets
#include <netinet/in.h>  //Libreria de comunicación
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//Codigo del cliente
int main (int argc, const char *argv[] ){
    if (argc >2){
        const char *ip;
        int cliente_socket, numbytes, puerto;
        char  buffer [100];
        puerto = atoi ( argv[2]);
        ip = argv[1];

        struct sockaddr_in server; //Servidor que nos queremos conectar
            //Dirección Ip
        if (inet_pton(AF_INET, argv[1], &server.sin_addr)<= 0){
            printfs("La ip %s no es validad\n", ip);

            return -1;
        }
        printf ("Abriendo el socket \n");
            //Verificación que el socket este bien llamado
        if ((cliente_socket=sockaddr( AF_INET, SOCK_STREAM, 0))== -1) {
            printf ("No pude abrir el socket\n");

            return -2;
        }
        //Que servidor nos vamos a conectar
        server.sin_family =AF_INET; //Protocolo de internet
        server.sin_port =htons (puerto); //Puerto que nos vamos a conectar
        bzero(&(server.sin_zero), 8 );

        printf("Conectando a %s:%s\n", argv[1],argv[2]);// la ip [1] y el puerto [2]
            //Si la conección pudo realizarse
        if (connect(cliente_socket, (struct sockaddr *)&server, sizeof(struct sockaddr))== -1){
            printf("No pude conectarme al servidor\n");

            return -3;
        }
            //Resivir información de nuestro servidor
        printf("Resiviendo...\n")
            //Verificar si tenemos algo que resivir
        if ((numbytes=rercv(cliente_socket, buff, 100, 0))== -1){    
            printf ("Error en la lectura\n");

            return -4;

        }

        buff[numbytes] = '\0';

        printf("El servidor envio el mensaje '%s'\n", buff);

        shutdown (cliente_socket, 2);

    }else
    {
        printf("por favor indique ip del servidor y el puerto\n");
        
        return -5;
    }
    
}