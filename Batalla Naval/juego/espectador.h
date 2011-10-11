/*
 * Archivo: Espectador.h
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 1-10-2011
 *
 * Nota: Estructura y funciones de la clase Espectador
 *
 */
#ifndef _ESPECTADOR_H_
#define _ESPECTADOR_H_
typedef struct Matrices
{
    matriz matrizJ1_A;
    //int **matrizJ1_A; //contiene la matriz ajena del Jugador1
    matriz matrizJ1_P;
    //int **matrizJ1_P; //contiene la matriz propia del Jugador1
    matriz matrizJ2_A;
    //int **matrizJ2_A; //contiene la matriz ajena del Jugador2
    matriz matrizJ2_P;
    //int **matrizJ2_P; //contiene la matriz propia del Jugador2
}Matrices;

//muestra la informacion de las matrices
void ver_datos();

#endif
