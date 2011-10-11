/*   
 * Archivo: magia_crr.c
 * Proyecto: CRR - Batalla naval
 * 
 * Fecha de creación: 2-10-2011
 * 
 * Nota: puf, ¿como explicar lo que es la magia?. Este archivo contiene
 * el nucleo de toda la aplicacion.
 */

#include <stdio.h>
#include "presentacion/mensajes_consola.h"
#include "juego/matriz.h"

    
int main ()
{
    
    coord coordenadas_ataque;
    coord coordenadas_barco;
	//establecer conexion (ver algun dia)
	//crear jugadores
    
    printf ("------------------------------------------------------------\n");
	printf("Simulacro naval \n 2 jugadores en una maquina \n");	
    printf ("------------------------------------------------------------\n");
		
    //iniciar matrices   --este es un ejemplo. esto y las vidas van a estar dentro de la clase jugador
	matriz* jugador1_propia = constructor_matriz('0');
	matriz* jugador1_ajena = constructor_matriz('X');
	matriz* jugador2_propia = constructor_matriz('0');
	matriz* jugador2_ajena = constructor_matriz('X');

	int cantidad_barcos_j1=0;
	int cantidad_barcos_j2=0;
	
	//inicializacion - Jugador 1. 

	printf("TURNO DEL JUGADOR 1");
	mensaje_inicial(jugador1_propia);

	while (cantidad_barcos_j1<BARCOS_INICIAL)
	{
		coordenadas_barco=mensaje_insertar_barco (cantidad_barcos_j1,jugador1_propia);
        
        if (marcar(jugador1_propia,'B',&coordenadas_barco)==ACEPTAR_MARCAR) 
        {
            printf ("insercion correcta en %d %d\n",coordenadas_barco.fila, coordenadas_barco.columna);
        }
        else
        {
            printf ("no se pudo realizar la insercion, controle que no haya un bote previo \n");
        }
        
		mostrar_tablero(jugador1_propia);
		cantidad_barcos_j1++;
	}

	
	printf("TURNO DEL JUGADOR 2");
	mensaje_inicial(jugador2_propia);
	while (cantidad_barcos_j2<BARCOS_INICIAL)
	{
		coordenadas_barco=mensaje_insertar_barco (cantidad_barcos_j2,jugador2_propia);
        
        if (marcar(jugador2_propia,'B',&coordenadas_barco)==ACEPTAR_MARCAR) 
        {
            printf ("insercion correcta en %d %d\n",coordenadas_barco.fila, coordenadas_barco.columna);
        }
        else
        {
            printf ("no se pudo realizar la insercion, controle que no haya un bote previo \n");
        }
        
		mostrar_tablero(jugador2_propia);
		cantidad_barcos_j2++;
	}

    //ciclo "infinito" termina en jugado1->vidas==0 o jugado2->vidas==0	

	do 
	{
        //ciclo jugador 1
        printf ("jugador 1: es su turno de atacar \n");
        coordenadas_ataque = mensaje_ataque(jugador1_propia,jugador1_ajena);
        if (devolver_celda(jugador2_propia,&coordenadas_ataque) == 'B')  //falta- que pasa si tiro de nuevo al mismo lugar
        {
            //hundido
            marcar(jugador1_ajena,'H',&coordenadas_ataque);
            marcar(jugador2_propia,'H',&coordenadas_ataque);
            cantidad_barcos_j2--;
            printf ("hundiste un barco, al oponente le quedan %d vidas \n",cantidad_barcos_j2);
        }
        else
        {
            //agua
            marcar(jugador1_ajena,'A',&coordenadas_ataque);
            marcar(jugador2_propia,'A',&coordenadas_ataque);  
            printf ("agua, al oponente le quedan %d vidas \n",cantidad_barcos_j2);
        }

        if (cantidad_barcos_j2>0)
        {
            //ciclo jugadore 2

            printf ("jugador 2: es su turno de atacar \n");
            coordenadas_ataque = mensaje_ataque(jugador2_propia,jugador2_ajena);
            if (devolver_celda(jugador1_propia,&coordenadas_ataque) == 'B')  //falta- que pasa si tiro de nuevo al mismo lugar
            {
                //hundido
                marcar(jugador2_ajena,'H',&coordenadas_ataque);
                marcar(jugador1_propia,'H',&coordenadas_ataque);
                cantidad_barcos_j1--;
                printf ("hundiste un barco, al oponente le quedan %d vidas \n",cantidad_barcos_j1);
            }
            else
            {
                //agua
                marcar(jugador2_ajena,'A',&coordenadas_ataque);
                marcar(jugador1_propia,'A',&coordenadas_ataque);
                printf ("agua, al oponente le quedan %d vidas \n",cantidad_barcos_j1);
            }
        }
	}
	while (cantidad_barcos_j2>0 && cantidad_barcos_j1>0);


    //enviar mensajes al ganador y al perdedor
	
    if (cantidad_barcos_j1==0)
	{
	    //mensaje para j1
        mensaje_perdiste(jugador1_propia,jugador2_propia);
        //mensaje para j2
        mensaje_ganaste(jugador2_propia,jugador1_propia);
	}
	else
	{
        //mensaje para j1
        mensaje_ganaste(jugador1_propia,jugador2_propia);
        //mensaje para j2
        mensaje_perdiste(jugador2_propia,jugador1_propia);
	}
	
	return 0;
}
