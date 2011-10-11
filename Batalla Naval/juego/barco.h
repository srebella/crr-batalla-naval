/*
 * Archivo: Barco.h
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 2-10-2011
 * 
 *
 * Nota: Estructura y funciones de la clase barco
 *
 */
#ifndef _BARCO_H_
#define _BARCO_H_

#include <stdio.h>
#include <stdlib.h>
#include "coordenadas.h"

#define FILAS_NAVAL 8
#define COLUMNAS_NAVAL 8
#define ERROR_MARCAR 600
#define ACEPTAR_MARCAR 100

typedef struct barco
{
    int estado; //indica si el barco está hundido o no
    int longitud; //casillas que ocupa el barco(por default es 1)
    coord *popa; //casilla inicial del barco
    coord *proa; //casilla final del barco
}barco;

//crea una nueva instancia de barco llenando sus atributos
void construir_barco(coord *popa,coord *proa);

//decrece el numero de barcos de jugador y
//borra el barco de la matriz
int destruir_barco(barco *bote);

//marca un golpe en el barco
void golpe(barco *b);

#endif

