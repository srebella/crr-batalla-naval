/*
 * Archivo: validaciones.c
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 2-10-2011
 *
 * Nota: En este archivo se declaran las funciones que van controlar que los
 * datos ingresados por el usuario esten dentro de los parametros esperados
 *
 */


#ifndef VALIDACIONES_H
#define VALIDACIONES_H

//revisa que la coordenada de fila sea valida. caso contrario pide un nuevo valor
void control_fila (char *numero_fila, char fila);

//revisa que la coordenada de columna sea valida. caso contrario pide un nuevo valor
void control_columna( char *numero_columna);

#endif //VALIDACIONES_H
