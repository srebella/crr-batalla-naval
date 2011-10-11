#ifndef _JUEGO_H_
#define _JUEGO_H_
typedef struct{
    /*vector que contiene la información de todos los
    espectadores*/
    int *espectador;

    Jugador Jugador1; //instancia de la clase Jugador Nº1
    Jugador Jugador2; //instancia de la clase Jugador Nº2
}Juego;

/*relaciona a una persona real (física) con una
instancia dentro del juego*/
Jugador AsignarJugador();

//interfaz con la capa “Conexión”
void Com_Conexion();

//interfaz con la capa “Presentación”
bool Com_Presentacion();

/*crea el servidos en la máquina en la que se
ejecuta el programa*/
bool CrearServidor();

//arbitra toda la lógica del juego
void Magia();

#endif

