/*
 * Archivo: Barco.c
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 2-10-2011
 * 
 *
 * Nota: Definicion de las funciones de la clase barco
 *
 */
#include "barco.h"
void construir_barco(coord *popa,coord *proa)
{
    barco *bote=malloc (sizeof(barco));
    bote->estado=1;
    bote->longitud=1;
    bote->popa=malloc (sizeof(coord));
    bote->popa->fila=popa->fila;
    bote->popa->columna=popa->columna;
    bote->proa=malloc (sizeof(coord));
    bote->proa->fila=proa->fila;
    bote->proa->columna=proa->columna;
}

int destruir_barco(barco *bote)
{
    //suponemos que la longitud del barco es 1
    free(bote);
    if (&bote==NULL)
    return 1;
    else return 0;
}

void golpe(barco *b)
{
    destruir_barco(b);
}
