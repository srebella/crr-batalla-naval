/*
 * Archivo: validaciones.c
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 2-10-2011
 *
 * Nota: En este archivo se definen las funciones que van controlar que los
 * datos ingresados por el usuario esten dentro de los parametros esperados
 *
 */

#include <stdio.h>
#include "conversores.h"

//revisa que la coordenada de fila este entre los valores esperados. caso contrario pide un nuevo valor
void control_fila (char *numero_fila, char fila)
{
      while (*numero_fila==ERROR_FILA)
        {
            printf ("el valor de la fila esta fuera de los parametros, escoja nuevamente \n");
            printf("Fila: ");
            scanf("%s",&fila);
            *numero_fila=conversor_fila(fila);
        }
}   

//revisa que la coordenada de columna este entre los valores esperados. caso contrario pide un nuevo valor
void control_columna( char *numero_columna)
{
    while (*numero_columna==ERROR_COLUMNA)
        {
            printf ("el valor de la columa esta fuera de los parametros, escoja nuevamente \n");
            printf("Columna: ");
            scanf("%d",numero_columna);
            *numero_columna=conversor_columna(*numero_columna);
        }
}
