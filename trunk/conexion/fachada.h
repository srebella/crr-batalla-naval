/*
 * fachada.h
 *
 *  Created on: 01/10/2011
 *     
 */

#ifndef FACHADA_H_
#define FACHADA_H_

int crear_servidor (char *puerto);

int conectarse_a_servidor(char *ip, char *puerto);

int enviar_ataque(int destino, int coordenada1, int coordenada2);

int devolver_ataque(int fuente, int *coordenada1, int *coordenada2);

char* devolver_respuesta();

int enviar_posicion_barcos(int destino, char *posiciones[]);

int devolver_posicion_barcos();

int enviar_resultados(int destino, char *resultados);

char* devolver_resultado();

int enviar_matriz(int destino, char **M1, char **M2, int V1, int V2, char respuesta);

int devolver_matriz(int fuente, char **M1, char **M2, int *V1, int *V2, char *respuesta);

int enviar_fin_partido(int destino);

#endif /* FACHADA_H_ */
