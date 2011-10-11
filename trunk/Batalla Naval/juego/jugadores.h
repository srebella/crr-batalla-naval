/*
 * Archivo: Jugadores.h
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 6-10-2011
 * 
 *
 * Nota: Estructura y funciones de la clase Jugadores
 *
 */
#ifndef _JUGADORES_H_
#define _JUGADORES_H_
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "barco.h"
#include "juego.h"

#define FILAS_NAVAL 8
#define COLUMNAS_NAVAL 8
#define ERROR_MARCAR 600
#define ACEPTAR_MARCAR 100

typedef struct jugador
{
    /*instancia de matriz que contiene los misiles
    enviados por el jugador y el resultado proporcionado por el
    contrincante*/
    //int **mat_Ajena;
    matriz *matriz_ajena;

    /*instancia de matriz que indica sus barcos propios
    y los misiles lanzados por el contrincante*/
    //int **mat_Propia;
    matriz *matriz_propia;

    char nombre; //nick del jugador
    int vida; //barcos restantes del jugador
}judador;

//envía un "misil" a las coordenadas especificadas
void atacar(struct jugador* Jug,coord *c);

//crea un barco en la posición indicada
int colocar_barco (struct jugador *Jug,coord *c);

//impide acciones al jugador hasta la respuesta del servidor
void esperar();

//decrece la cantidad de barcos del jugador
int perder_vida (struct jugador* Jug);

#endif
