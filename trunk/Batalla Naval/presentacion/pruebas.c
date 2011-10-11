/*   
 * Archivo: pruebas.c - proximamente presentacion_consola.c
 * Proyecto: CRR - Batalla naval
 * 
 * Fecha de creación: 1-10-2011
 * Última modificación: Nico
 * 
 * Nota: Esta es una version preeliminar para probar funciones y empezar
 * a organizar ideas
 * 
 */

#include <stdio.h>
#include "../juego/Librerias/Matriz.h"

#define FILAS_NAVAL 8
#define COLUMNAS_NAVAL 8
#define BARCOS_INICIAL 8
#define ERROR_FILA 100
#define ERROR_COLUMNA 200

void mostrar_tableros (matriz tablero)
{
    char valor;
    int i;
    int j;
    for (i=0;i<=FILAS_NAVAL;i++)
    {
        for (j=0;j<=COLUMNAS_NAVAL;j++)
        {
            valor=devolver_celda(tablero,i,j); // funcion de santi. ver como llamarla
            printf ("%c ",valor);
        }
        printf ("\n");    
    }
}

void mensaje_espera()
{
        printf ("es el turno del otro jugador, por favor aguarde \n");
}




void mensaje_inicial()
{
 int cantidad_barcos=BARCOS_INICIAL;
    char fila;
    int columna;
    int numero_fila=0;
    
    printf ("¡Bienvenido! gracias por elegir CRR proyectos \n");
    printf ("Es su turno, por favor eliga donde va a colocar sus barcos \n");
    printf ("Valores entre A y H para filas y de 1 a 8 para las columnas \n");
        
    while (cantidad_barcos>0)
    {
        printf("barcos restantes %d \n",cantidad_barcos);
        printf("Fila: ");
        scanf("%c",&fila);
        
        printf("Columna: ");
        scanf("%d",&columna);
        
        numero_fila=conversor_fila(fila);
        
        while (numero_fila==ERROR_FILA)  //todo indicca que esta va a ser la fucion "controlar_fila"
        {
            printf ("el valor de la fila esta fuera de los parametros, escoja nuevamente \n");
            printf("Fila: ");
            scanf("%c",&fila);
            numero_fila=conversor_fila(fila);
        }
        
        columna=conversor_columna(columna);
        
        while (columna==ERROR_COLUMNA) //todo indicca que esta va a ser la fucion "controlar_columna"
        {
            printf ("el valor de la columa esta fuera de los parametros, escoja nuevamente \n");
            printf("Columna: ");
            scanf("%d",&columna);
            columna=conversor_columna(columna);
        }
        
        if (Marcar("B",(fila,columna))    //funcion de santi
        {
            printf ("insercion correcta \n");
            cantidad_barcos= cantidad_barcos-1;
        }   
        else
        {
            printf ("no se pudo agregar el bote, controle que no haya un bote previo \n");
        }
    }
    
    printf ("Fin del turno \n");
        
}

int conversor_columna (int columna)
{
   if (columna>=1) && (columna<=8)
   {
        return columna-1;
   }
   else
   {
        return ERROR_COLUMNA;
   }
}


int conversor_fila (char fila)
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
