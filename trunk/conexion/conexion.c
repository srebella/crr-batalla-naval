/*
 * conexion.c
 *
 *  Created on: 01/10/2011
 *      
 */

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "funciones.h"
#include "fachada.h"
#include "buffer.h"

#define MAX_LINE 131
#define MAX_CONN 10
#define PUERTO "2060"


int main (int argc, char *argv[]){
	int conexion_socket, manejador_socket,flag,dt[2];
	int J1;
	int J2;
	char buffer[MAX_LINE];
	//char buffer1[MAX_LINE];
	//char buffer2[MAX_LINE];
	pid_t idProceso;
	//obtiene datos del usuario
	flag=0;
	if (1<argc){
		if ( !strncmp(argv[1], "-s", 2) || !strncmp(argv[1], "-s", 2) ) {
			flag = 1;
		}
	}

	int i,j;
	char** M1=NULL;
	char** M2=NULL;
	char** M3=NULL;
	char** M4=NULL;
	M1=(char**)malloc(sizeof(char*)* 8);
	M2=(char**)malloc(sizeof(char*)* 8);
	M3=(char**)malloc(sizeof(char*)* 8);
	M4=(char**)malloc(sizeof(char*)* 8);
	for(i=0;i<8;i++){
		M1[i]=(char*)malloc(sizeof(char)*8);
		M2[i]=(char*)malloc(sizeof(char)*8);
		M3[i]=(char*)malloc(sizeof(char)*8);
		M4[i]=(char*)malloc(sizeof(char)*8);
	}


	if (flag==1){			// Server
		printf("Soy server\n");
		manejador_socket=crear_servidor(PUERTO);

		pipe(dt);
		printf("Creado el pipe\n");

		printf("Forkeando el proceso\n");
		idProceso = 5;//fork();

		if (idProceso == 0 ){
			loop_proceso_forkeado(manejador_socket, buffer, dt);
		}else{
			printf("P: esperando conexion J1...\n");
			J1 = buscar_nueva_conexion(manejador_socket);
			//printf("P: esperando conexion J2...\n");
			J2 = buscar_nueva_conexion(manejador_socket);
			printf("P: todo listo, que empiece el juego!\n");

			// Ahora activo la bandera para que busque otras conexiones
			//strcpy (buffer, "Hola");
			//write (dt[1], buffer, strlen(buffer)+1);

			/* Chat =P
			strcpy(buffer1,"nada");
			strcpy(buffer2,"nada");
			recibir_datos(J1, buffer1, MAX_LINE);
			recibir_datos(J2, buffer2, MAX_LINE);
			printf("P: recibi %s del J1\n",buffer1);
			printf("P: recibi %s del J2\n",buffer2);
			printf("P: envio %s a J1\n",buffer2);
			printf("P: envio %s a J2\n",buffer1);
			enviar_datos(J1, buffer2, strlen(buffer2));
			enviar_datos(J2, buffer1, strlen(buffer1));*/
			int V1,V2,V3,V4,c1=0,c2=0,c3=0,c4=0;
			char accion1,accion2;

			// RECIBE J1
			devolver_matriz(J1,M1,M3,&V1,&V3,&accion1);
			printf("Matriz enviada J1:\n");
			for (i=0;i<8;i++){
				for (j=0;j<8;j++){
					printf("%c",M1[i][j]);
				}
				printf("\n");
			}
			printf("Vidas J1=%i\n",V1);
			printf("Accion: %c\n",accion1);

			//RECIBE J2
			devolver_matriz(J2,M2,M4,&V2,&V4,&accion2);
			printf("Matriz enviada J2:\n");
			for (i=0;i<8;i++){
				for (j=0;j<8;j++){
					printf("%c",M2[i][j]);
				}
				printf("\n");
			}
			printf("Vidas J2=%i\n",V2);
			printf("Accion: %c\n",accion2);

			// RECIBE ATAQUE 1
			devolver_ataque(J1, &c1, &c3);
			M2[c1][c3]='O';
			printf(" - J1 ataca!! [ %i , %i ]\n",c1,c3);

			// RECIBE ATAQUE 2
			devolver_ataque(J2, &c2, &c4);
			M1[c2][c4]='O';
			printf(" - J2 ataca!! [ %i , %i ]\n",c2,c4);

			// ENVIA MATRIZ 1
			enviar_matriz(J1,M1,M3,V1,V3,accion2);
			printf("Matriz enviada\n");

			// ENVIA MATRIZ 2
			enviar_matriz(J2,M2,M4,V2,V4,accion1);
			printf("Matriz enviada\n");

			close(J1);
			close(J2);
			printf("P: cerre conexiones\n");
		}
	}else{				// Cliente
		printf("Soy cliente\n");
		//enviar_matriz( 7,  M1,  M2);

		conexion_socket=conectarse_a_servidor("127.0.0.1",PUERTO);

		/* Chat =P
		printf("Nombre: ");
		fgets(buffer, MAX_LINE, stdin);

		printf("Mandando \"%s\"...",buffer);

		enviar_datos(conexion_socket, buffer, strlen(buffer));
		printf("Enviado\n");

		recibir_datos(conexion_socket, buffer, MAX_LINE);
		printf("Conectado con \"%s\"\n",buffer);*/

		printf("Letra para llenar la matriz: ");
		char letra1;
		letra1=getchar();
		getchar();
		for (i=0;i<8;i++){
			for (j=0;j<8;j++){
				M1[i][j]=letra1;
				printf("%c",M1[i][j]);
			}
			printf("\n");
		}
		for (i=0;i<8;i++){
			for (j=0;j<8;j++){
				M2[i][j]='X';
				//printf("%c",M1[i][j]);
			}
			//printf("\n");
		}

		printf("Mis vidas [0-9]: ");
		char vidas1;
		vidas1=getchar();
		getchar();
		int V1=atoi(&vidas1);
		int V2=0;

		printf("Accion: ");
		char respuesta;
		respuesta=getchar();
		getchar();

		// MANDO
		enviar_matriz(conexion_socket,M1,M2,V1,V2,respuesta);
		printf("Matriz enviada\n");

		// MANDO
		if (V1<5)	{enviar_ataque(conexion_socket,7,0);}
		else		{enviar_ataque(conexion_socket,3,2);}
		printf("Vida enviada (%i)\n",V1);

		// RECIBO
		devolver_matriz(conexion_socket,M1,M2,&V1,&V2,&respuesta);
		printf("Matriz recibidas:\n");
		for (i=0;i<8;i++){
			for (j=0;j<8;j++){
				printf("%c",M1[i][j]);
			}
			printf("\n");
		}
		printf("Vidas: %i\n",V1);
		printf("Respuesta: %c\n",respuesta);
	}
	return 0;
}
