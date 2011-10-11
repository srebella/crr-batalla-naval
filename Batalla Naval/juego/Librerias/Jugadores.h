#ifndef _JUGADORES_H_
#define _JUGADORES_H_
typedef struct{
    /*instancia de matriz que contiene los misiles
    enviados por el jugador y el resultado proporcionado por el
    contrincante*/
    int **mat_Ajena;

    /*instancia de matriz que indica sus barcos propios
    y los misiles lanzados por el contrincante*/
    int **mat_Propia;

    char nombre; //nick del jugador
    int vida; //barcos restantes del jugador
}Judador;

//envía un misil a las coordenadas especificadas
void Atacar(int coord);

//crea un barco en la posición indicada
void Colocar_barco();

//impide acciones al jugador hasta la respuesta del servidor
void Esperar();

//decrece la cantidad de barcos del jugador
int Perder_vida();

#endif
