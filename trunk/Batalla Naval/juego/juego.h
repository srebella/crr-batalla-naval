/*
 * Archivo: Juego.h
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creaci�n: 6-10-2011
 *  *
 * Nota: Estructura y funciones de la clase Juego
 *
 */
#ifndef _JUEGO_H_
#define _JUEGO_H_
#include "jugadores.h"
typedef struct Juego
{
    /*vector que contiene la informaci�n de todos los
    espectadores*/
    int *espectador;

    struct jugador *Jugador1; //instancia de la clase Jugador N�1
    struct jugador *Jugador2; //instancia de la clase Jugador N�2
}Juego;

/*relaciona a una persona real (f�sica) con una
instancia dentro del juego*/
struct jugador* asignar_jugador(char nombre);

//interfaz con la capa �Conexi�n�
void com_conexion();

//interfaz con la capa �Presentaci�n�
//bool com_presentacion();

/*crea el servidos en la m�quina en la que se
ejecuta el programa*/
//bool crear_servidor();

//arbitra toda la l�gica del juego
void Magia();

#endif
