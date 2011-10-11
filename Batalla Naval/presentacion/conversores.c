/*
 * Archivo: conversores.c
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 2-10-2011
 *
 * Nota: En este archivo se declaran las funciones que transforman los datos
 * ingresados por el usuario en valores aptos para la capa "juego"
 *
 */

#include "conversores.h"

//convierte el valor recibido por el usuario (1-8) a el valor que realmente se procesa (0-7)
char conversor_columna (char columna)
{
   if ((columna>=1) && (columna<=8))
   {
        return columna-1;
   }
   else
   {
        return ERROR_COLUMNA;
   }
}

//convierte el valor recibido por el usuario (A-H) a el valor que realmente se procesa (0-7)
char conversor_fila (char fila)
{
   if ((fila=='a') || (fila=='A'))
   {
        return 0;
   }
   if ((fila=='b') || (fila=='B'))
   {
        return 1;
   }
   if ((fila=='c') || (fila=='C'))
   {
        return 2;
   }
   if ((fila=='d') || (fila=='D'))
   {
        return 3;
   }
   if ((fila=='e') || (fila=='E'))
   {
        return 4;
   }
   if ((fila=='f') || (fila=='F'))
   {
        return 5;
   }
   if ((fila=='g') || (fila=='G'))
   {
        return 6;
   }
   if ((fila=='h') || (fila=='H'))
   {
        return 7;
   }

   return ERROR_FILA;   //valor de error
}

char conversor_letra (int numero)
{
    switch (numero)
    {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
        case 4:
            return 'E';
        case 5:
            return 'F';
        case 6:
            return 'G';
        case 7:
            return 'H';        
    }

    return ERROR_LETRA; //ERROR
}

