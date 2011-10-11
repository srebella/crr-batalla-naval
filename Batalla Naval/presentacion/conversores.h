/*
 * Archivo: conversores.c
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 2-10-2011
 *
 * Nota: En este archivo se definen las funciones que transforman los datos
 * ingresados por el usuario en valores aptos para la capa "juego"
 *
 */


#ifndef CONVERSORES_H
#define CONVERSORES_H

#define FILAS_NAVAL 8
#define COLUMNAS_NAVAL 8

#define ERROR_FILA 100
#define ERROR_COLUMNA 200
#define ERROR_LETRA 'n'

//convierte el valor recibido por el usuario (1-8) a el valor que realmente se procesa (0-7)
char conversor_columna (char columna);

//convierte el valor recibido por el usuario (A-H) a el valor que realmente se procesa (0-7)
char conversor_fila (char fila);

//convierte el valor (0-7) a (A-H) 
char conversor_letra (int numero);

#endif //CONVERSORES_H
