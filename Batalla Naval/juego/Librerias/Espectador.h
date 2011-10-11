#ifndef _ESPECTADOR_H_
#define _ESPECTADOR_H_
typedef struct{
    int **matrizJ1_A; //contiene la matriz ajena del Jugador1
    int **matrizJ1_P; //contiene la matriz propia del Jugador1
    int **matrizJ2_A; //contiene la matriz ajena del Jugador2
    int **matrizJ2_P; //contiene la matriz propia del Jugador2
}Matrices;

//muestra la informacion de las matrices
void Ver_datos();

#endif


