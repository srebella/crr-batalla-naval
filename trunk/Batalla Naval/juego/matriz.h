/*
 * Archivo: Matriz.h
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 2-10-2011
 *
 * Nota: Estructura y funciones de la clase matriz
 *
 */


#ifndef _MATRIZ_H_
#define _MATRIZ_H_
#include <stdio.h>
#include <stdlib.h>
#include "coordenadas.h"

#define FILAS_NAVAL 8
#define COLUMNAS_NAVAL 8
#define ERROR_MARCAR 600
#define ACEPTAR_MARCAR 100
#define BARCOS_INICIAL 4

typedef struct matriz
{
    int altura; //cantidad de filas
    int longitud; //cantidad de columnas
    char **casillas; //matriz de (Altura x Longitud) caracteres
}matriz;

//crea puntero doble para la matriz
char** crear_matriz(char fila,char cols);

//libera espacio ocupado por la matriz
void liberar_fichero(matriz* tablero,int fila);

//inicializa matriz con valores en 0
void iniciar_matriz(char **matrix, char letra);

//crea una instancia de matriz
matriz* constructor_matriz(char letra);

//manda mensaje con todos los contenidos de sus celdas
char devolver_celda (matriz *tablero,coord *a);

//cambia el valor de una casilla de la matriz
int marcar(matriz *tablero,char valor,coord *c);  //necesitaria que esto devuelva 0 en  caso de intentar insertar un barco donde ya hay uno.

#endif

