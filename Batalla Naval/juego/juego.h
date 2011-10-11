/*
 * Archivo: Juego.h
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 6-10-2011
 *  *
 * Nota: Estructura y funciones de la clase Juego
 *
 */
#ifndef _JUEGO_H_
#define _JUEGO_H_
#include "jugadores.h"
typedef struct Juego
{
    /*vector que contiene la información de todos los
    espectadores*/
    int *espectador;

    struct jugador *Jugador1; //instancia de la clase Jugador Nº1
    struct jugador *Jugador2; //instancia de la clase Jugador Nº2
}Juego;

/*relaciona a una persona real (física) con una
instancia dentro del juego*/
struct jugador* asignar_jugador(char nombre);

//interfaz con la capa “Conexión”
void com_conexion();

//interfaz con la capa “Presentación”
//bool com_presentacion();

/*crea el servidos en la máquina en la que se
ejecuta el programa*/
//bool crear_servidor();

//arbitra toda la lógica del juego
void Magia();

#endif
