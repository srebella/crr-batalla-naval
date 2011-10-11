/*
 * funciones.c
 *
 *  Created on: 01/10/2011
 *      
 *
 */

#include <sys/socket.h>       /*  socket definitions        */
#include <sys/types.h>        /*  socket types              */
#include <arpa/inet.h>        /*  inet (3) funtions         */
#include <unistd.h>           /*  misc. UNIX functions      */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define LISTENQ		(1024)
#define ECHO_PORT	(2002)
#define MAX_LINE	(1000)


int crear(char* ppuerto){

	short int puerto;                   /*  port number               */
	struct    sockaddr_in direccion_t;  /*  socket address structure  */
	int       manejador;                /*  listening socket          */
	char     *endptr;                   /*  for strtol()              */


	// guarda el puerto que le di
	puerto = strtol(ppuerto, &endptr, 0);

	// crea el socket de escucha
	manejador = socket(AF_INET, SOCK_STREAM, 0);

	// limpia la estructura y la llena con los valores importantes
	memset(&direccion_t, 0, sizeof(direccion_t));
	direccion_t.sin_family      = AF_INET;
	direccion_t.sin_addr.s_addr = htonl(INADDR_ANY);
	direccion_t.sin_port        = htons(puerto);

	// bindea nuestro socket addres a nuestro socket de escucha
	bind(manejador, (struct sockaddr *) &direccion_t, sizeof(direccion_t));

	// llama a listen
	listen(manejador, LISTENQ);

	printf("Socket creado para puerto %i\n", puerto);
	return manejador;
}

int conectar(char* ip, char* ppuerto){
	int       conexion;                 /*  connection socket         */
	short int puerto;                   /*  port number               */
	struct    sockaddr_in direccion_t;  /*  socket address structure  */
	char     *endptr;                   /*  for strtol()              */

	// setea puerto remoto
	puerto = strtol(ppuerto, &endptr, 0);

	// crea socket de escucha
	conexion = socket(AF_INET, SOCK_STREAM, 0);

	// limpia estructura y llena con cosas importantes
	memset(&direccion_t, 0, sizeof(direccion_t));
	direccion_t.sin_family      = AF_INET;
	direccion_t.sin_port        = htons(puerto);

	// setea la IP remota
	inet_aton(ip, &direccion_t.sin_addr);

	// conecta al server
	connect(conexion, (struct sockaddr *) &direccion_t, sizeof(direccion_t) );

	printf("Conectado al servidor en %s:%i\n",ip,puerto);
	return conexion;
}

int buscar_nueva_conexion(int manejador){
	struct sockaddr_in cliente_t;
	int conexion = accept(manejador, NULL,NULL);
	printf("Aceptada conexion:\n\tIP=%s\n\tSocket=%i\n",inet_ntoa(cliente_t.sin_addr),conexion);
	return conexion;
}

int loop_proceso_forkeado(int manejador, void *puntero, void *tuberia){
	char *buffer,*dt;
	int conexion;
	buffer = puntero;
	dt=tuberia;
	while(1){
		int cant=0;
		if ((cant=read (dt[0], buffer, MAX_LINE)) < 0){
			//printf("infinitooo aaaaaaaa xD");
		}else{
			if(cant>0){
				while(1){
					printf("H: esperando conexion...\n");
					conexion = buscar_nueva_conexion(manejador);
					printf("H: acepte conexion\n");
				}
			}else{

			}
		}
	}
	return conexion;
}

int recibir_datos (int conexion, void *puntero, size_t n){
	char *buffer;
	buffer = puntero;
	// escribe el socket hasta N bytes
	read(conexion,buffer,n);
	return 0;
}

int enviar_datos(int conexion, const void *puntero, size_t n){
	const char *buffer;
	buffer = puntero;
	// lee el socket hasta N bytes
	write(conexion,buffer,n);
	return 0;
}

