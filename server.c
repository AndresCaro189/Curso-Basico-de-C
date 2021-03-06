//Sockets, conección entre cliente y servidor 
//Ingresamos librerias 
#include <sys/socket.h> //Llibreria de los Sockets
#include <netinet/in.h>  //Libreria de comunicación
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, const char *argv[] ){
    if (argc >1){
        int server_socket, client_socket, longitud_cliente, puerto;

        puerto = atoi (argv[1]);     

        struct sockaddr_in server; //servidor
        struct sockaddr_in client; //cliente

        server.sin_family       = AF_INET; //Protocolo de internet
        server.sin_port         = htons (puerto);
        server.sin_addr.s_ddr   = INADDR_ANY; //Quien se puede conectar
        bzero( &(server.sin_zero), 8 ); //Se requiere para usar las librerias de sockets
        //Socked del servido en modo escucha
        if((server_socket = socket(AF_INET, SOCK_STREAM, 0) )== -1){
            printf("No pude abrir el socket\n" );

            return -1;
        }
        //Conectar el Socked con un puerto
        if(bind(server_socket, (struct sockaddr *) &server, sizeof(struct sockaddr))== -1){
            printf("no pude abrir el puerto %s\n", argv[1]);

            return -2;
        }
        //Socked de modo escucha
        if (listen(server_socket, 5 )==-1){
            printf("No pude ponerme en modo escucha\n");
        }
        //darle respuesta al cliente desde el servicor
        longitud_cliente = sizeof (struct sockaddr_in );

        printf("Esperando clientes...\n");
        //Resivir nuestro primer cliente
        if ((client_socket = accept(server_socket, (struct sockaddr*) &client, &longitud_cliente))) == -1 {
            printf("No pudimos aceptar una conexión\n");
           
            return -4;  
        }
        //Comunicarnos con el cliente
        char str [INET_ADDRSTRLEN];
        inet_ntop(AF_INT, &(client.sin_addr), str, INET_ADDRSTRLEN);

        printf("se conecto un cliente desde %s:%d. Lo saludo\n", str, client.sin_port);
        send (client_socket, "Bienvenido a mi servidor.\n", 26, 0);

        printf("El saludo fue enviado!\n");
        shutdown (client_socket, 2);
        shutdown (server_socket, 2);
    }else
    {
        printf("por favor indique el puerto\n");
        
        return -5;
    }
    
}