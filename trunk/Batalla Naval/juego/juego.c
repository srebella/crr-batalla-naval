/*
 * Archivo: Juego.c
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 6-10-2011
 * 
 * Nota: Definicion de las funciones de la clase Juego
 *
 */
#include "juego.h"
struct jugador* asignar_jugador(char nombre)
{
    struct jugador *Jug=malloc(sizeof(struct jugador));
    Jug->nombre=nombre;
    Jug->vida=8;
    Jug->matriz_propia=constructor_matriz();
    Jug->matriz_ajena=constructor_matriz();
    return Jug;
}
