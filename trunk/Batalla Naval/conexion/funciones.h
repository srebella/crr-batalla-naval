/*
 * funciones.h
 *
 *  Created on: 01/10/2011
 *     
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <sys/socket.h>       /*  socket definitions        */
#include <sys/types.h>        /*  socket types              */
#include <arpa/inet.h>        /*  inet (3) funtions         */
#include <unistd.h>           /*  misc. UNIX functions      */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int crear (char* puerto);

int conectar (char* ip, char* puerto);

int buscar_nueva_conexion(int manejador);

int loop_proceso_forkeado(int manejador, void *puntero, void *tuberia);

int enviar_datos(int conn_s, const void *pbuffer, size_t n);

int recibir_datos (int conn_s, void *pbuffer, size_t maxlen);

#endif /* FUNCIONES_H_ */
