/*
 * Archivo: Matriz.c
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 2-10-2011
 * 
 *
 * Nota: Definicion de las funciones de clase matriz
 *
 */
#include "matriz.h"
#include "coordenadas.h"

char** crear_matriz(char fila,char cols)
{
   int i;
   char** matrix=NULL;
   matrix=(char**)malloc(sizeof(char*)* fila);
   for(i=0;i<fila;i++){
      *(matrix+i)=(char*)malloc(sizeof(char)*cols);
   }
   return matrix;
}

void liberar_matriz(matriz* tablero,char fila)
{
   int i;
   for(i=0;i<fila;i++){
      free(*(tablero->casillas+i));
   }
   free(tablero->casillas);
   free(tablero);
}

void iniciar_matriz(char **matrix, char letra)
{
    int i,j;
 for (i=0;i<FILAS_NAVAL;i++)
    {
        for (j=0;j<COLUMNAS_NAVAL;j++)
            matrix[i][j]=letra;
    }
}

matriz* constructor_matriz(char letra)
{
    matriz *tablero=malloc(sizeof(matriz));
    tablero->altura=FILAS_NAVAL;
    tablero->longitud=COLUMNAS_NAVAL;
    tablero->casillas=crear_matriz(tablero->altura,tablero->longitud);

    iniciar_matriz(tablero->casillas,letra);
    return tablero;
}

char devolver_celda(matriz *tablero,coord *a)
{
	int fila=a->fila;
	int columna=a->columna;
	return (tablero->casillas[fila][columna]);
}

int marcar(matriz *tablero,char valor,coord *c)
{

    if (valor !=  tablero->casillas[c->fila][c->columna])  //si son iguales significa que el valor estaria por se estaria por reescribir
    {	
	tablero->casillas[c->fila][c->columna]=valor;
        return ACEPTAR_MARCAR;
    }
    else
    {
        return ERROR_MARCAR;
    }
}
