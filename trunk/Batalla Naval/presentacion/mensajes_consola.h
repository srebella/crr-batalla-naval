/*   
 * Archivo: mensajes_consola.c
 * Proyecto: CRR - Batalla naval
 * 
 * Fecha de creación: 2-10-2011
 * 
 * Nota: En este archivo se declaran las funciones que van a interactuar
 * con el usuario.
 * 
 */

#ifndef MENSAJES_CONSOLA_H
#define MENSAJES_CONSOLA_H

#include <stdio.h>
#include "../juego/matriz.h"

void mostrar_tablero (matriz *tablero);
void mensaje_espera(matriz *tablero_propio,matriz *tablero_ajeno);
coord mensaje_ataque();
void mensaje_ganaste(matriz *tablero_propio,matriz *tablero_ajeno);
void mensaje_perdiste(matriz *tablero_propio,matriz *tablero_ajeno);
void mensaje_conectar();
void mensaje_espectador();
coord mensaje_insertar_barco (char cantidad_barcos_colocados,matriz *tablero);
//Funcion que interactua con el usuario para pedir una coordenada de la matriz
//es utilizada para atacar y para colocar barcos
coord pedido_datos_coordenadas();

//mensaje de comienzo de juego y colocacion de barcos
void mensaje_inicial();

#endif //MENSAJES_CONSOLA_H

