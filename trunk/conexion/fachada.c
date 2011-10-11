/*
 * fachada.c
 *
 *  Created on: 01/10/2011
 *      
 */

#include "funciones.h"

int crear_servidor(char *puerto){
	int manejador;
	manejador = crear(puerto);
	return manejador;
}

int conectarse_a_servidor(char *ip, char *puerto){
	int conexion;
	conexion=conectar(ip,puerto);
	return conexion;
}

int enviar_ataque(int destino, int coordenada1, int coordenada2){
	char buffer[2];
	sprintf(buffer, "%i%i", coordenada1,coordenada2);
	enviar_datos(destino, buffer, strlen(buffer));
	return 0;
}

int devolver_ataque(int fuente, int *coordenada1, int *coordenada2){
	char buffer[2],a[2],b[2],*fin;
	recibir_datos(fuente,buffer,3);
	sprintf(a,"%c",buffer[0]);
	sprintf(b,"%c",buffer[1]);
	*coordenada1=(int)strtol (a,&fin,10);
	*coordenada2=(int)strtol (b,&fin,10);
	//printf("c1=%i\nc2=%i\n",*coordenada1,*coordenada2);
	return 0;
}

int enviar_posicion_barcos(int destino, char *posiciones[]){
	return 0;
}

int devolver_posicion_barcos(){
	return 0;
}

int enviar_resultados(int destino, char *resultados){
	return 0;
}

char* devolver_resultado(){
	return "hola";
}

int enviar_matriz(int destino, char **M1, char **M2,int V1, int V2, char respuesta){
	char buffer[131]={};
	int i,j;
	for (i=0; i<8; i++){
		for (j=0; j<8; j++){
			sprintf(buffer, "%s%c", buffer,M1[i][j]);
		}
	}
	for (i=0; i<8; i++){
		for (j=0; j<8; j++){
			sprintf(buffer, "%s%c", buffer,M2[i][j]);
		}
	}
	sprintf(buffer, "%s%i%i%c", buffer,V1,V2,respuesta);
	enviar_datos(destino, buffer, strlen(buffer));
	return 0;
}

int devolver_matriz(int fuente, char **M1, char **M2, int *V1, int *V2, char *respuesta){
	char buffer[131],a[2],b[2],*fin;
	int i,j;
	recibir_datos(fuente,buffer,131);
	for (i=0;i<8;i++){
		for (j=0;j<8;j++){
			M1[i][j]=buffer[i*8+j];
			//M1[i,j]=buffer[i*8+j];
			//printf("%c",M1[i,j]);
		}
		//printf("\n");
	}
	for (i=0;i<8;i++){
		for (j=0;j<8;j++){
			M2[i][j]=buffer[64+i*8+j];
			//M2[i,j]=buffer[64+i*8+j];
			//printf("%c",M2[i,j]);
		}
		//printf("\n");
	}
	sprintf(a,"%c",buffer[128]);
	sprintf(b,"%c",buffer[129]);
	*V1=(int)strtol (a,&fin,10);
	*V2=(int)strtol (b,&fin,10);
	*respuesta=buffer[130];
	return 0;
}

char* devolver_respuesta(){
	return "hola";
}

int enviar_fin_partido(){
	return 0;
}
