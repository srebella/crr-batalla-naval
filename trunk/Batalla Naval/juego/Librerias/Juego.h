#ifndef _JUEGO_H_
#define _JUEGO_H_
typedef struct{
    /*vector que contiene la informaci�n de todos los
    espectadores*/
    int *espectador;

    Jugador Jugador1; //instancia de la clase Jugador N�1
    Jugador Jugador2; //instancia de la clase Jugador N�2
}Juego;

/*relaciona a una persona real (f�sica) con una
instancia dentro del juego*/
Jugador AsignarJugador();

//interfaz con la capa �Conexi�n�
void Com_Conexion();

//interfaz con la capa �Presentaci�n�
bool Com_Presentacion();

/*crea el servidos en la m�quina en la que se
ejecuta el programa*/
bool CrearServidor();

//arbitra toda la l�gica del juego
void Magia();

#endif

