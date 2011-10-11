/*
 * Archivo: mensajes_consola.c
 * Proyecto: CRR - Batalla naval
 *
 * Fecha de creación: 2-10-2011
 *
 * Nota: En este archivo se definen las funciones que van a interactuar
 * con el usuario.
 *
 */

#include "mensajes_consola.h"
#include "validaciones.h"
#include "conversores.h"


//no me gusta que reciba "matriz", creo que deberia recibir el **casillas directamente
void mostrar_tablero (matriz *tablero)
{
    char valor;
    int i;
    int j;
    coord posicion;
    printf ("\t1 2 3 4 5 6 7 8\n");
    for (i=0;i<FILAS_NAVAL;i++)
    {
        valor=conversor_letra(i);
        printf ("%c \t",valor);
        for (j=0;j<COLUMNAS_NAVAL;j++)
        {
            posicion.fila=i;
            posicion.columna=j;
            valor=devolver_celda(tablero,&posicion); 
	    printf ("%c ",valor);
        }
        printf ("\n");
    }
}

void mensaje_espera(matriz *tablero_propio,matriz *tablero_ajeno)
{
    //matrices propias
    printf ("es el turno del otro jugador, por favor aguarde \n");
    printf ("Tus botes \n");
    mostrar_tablero (tablero_propio);
    printf ("Botes del rival\n");
    mostrar_tablero (tablero_ajeno);
    //resultado del ultimo tiro
    //vidas restantes
}

//mensaje de comienzo de juego y colocacion de barcos
void mensaje_inicial()
{
    printf ("\n");
    printf ("\n");
    printf ("¡Bienvenido! gracias por elegir CRR proyectos \n");
    printf ("Es su turno, por favor eliga donde va a colocar sus barcos \n");
    
    printf ("Valores de eferencias : \n");
    printf ("0: Nada en particular \n");  
    printf ("A: Misil que cayo en el agua \n");  
    printf ("B: Barco \n");  
    printf ("H: Barco hundido \n");  
    printf ("X: Desconocido \n");  
          
    printf ("Valores entre A y H para filas y de 1 a 8 para las columnas \n");  
    printf ("\n");
}

coord mensaje_insertar_barco (char cantidad_barcos_colocados,matriz *tablero)
{
    printf ("\n");
    printf("barcos restantes %d \n",BARCOS_INICIAL - cantidad_barcos_colocados);
        
    return pedido_datos_coordenadas();
    
}

coord mensaje_ataque(matriz *tablero_propio,matriz *tablero_ajeno)
{
    //matrices propias
    printf ("\n");
    printf ("Tus botes y los tiros del rival \n");
    mostrar_tablero (tablero_propio);
    printf ("\n");
    printf ("Tablero del rival\n");
    mostrar_tablero (tablero_ajeno);
    
    //resultado del ultimo tiro
    
    
    return pedido_datos_coordenadas();
    
    //vidas restantes
    //pedido y validacion de ataque
}

//Funcion que interactua con el usuario para pedir una coordenada de la matriz
//es utilizada para atacar y para colocar barcos
coord pedido_datos_coordenadas()
{
    char fila;
    char columna;
 
    coord coordenadas;
    printf("Seleccione coordenadas de ataque \n");
    printf("Fila: ");
    fila=getchar();getchar();
	
    coordenadas.fila=conversor_fila(fila);
    control_fila(&coordenadas.fila,fila);

    printf("Columna: ");
    columna=getchar();getchar();

    fflush(stdin);
    coordenadas.columna=atoi(&columna);
    coordenadas.columna--;	
 	
    control_columna (&coordenadas.columna);
    
    printf ("Fin del turno \n");
    printf ("\n");
    
    return coordenadas;
}

void mensaje_ganaste(matriz *tablero_propio,matriz *tablero_ajeno)
{
    printf ("\n");
    printf("¡¡¡Felicidades!!! Ganaste la partida. \n Gracias por jugar con nosotros \n");
    printf ("Tus botes \n");
    mostrar_tablero (tablero_propio);
    printf ("Botes del rival\n");
    mostrar_tablero (tablero_ajeno);  
    printf ("\n");  
}

void mensaje_perdiste(matriz *tablero_propio,matriz *tablero_ajeno)
{
    printf ("\n");
    printf("Lastima, perdiste el juego. \n Gracias por jugar con nosotros \n");
    printf ("Tus botes \n");
    mostrar_tablero (tablero_propio);
    printf ("Botes del rival\n");
    mostrar_tablero (tablero_ajeno);
    printf ("\n");    
}

void mensaje_conectar()
{
     //magia!!!. hablar con calde
}

void mensaje_espectador()
{
     //llegaste tarde.
     //datos jugadores
     //matrices
}
